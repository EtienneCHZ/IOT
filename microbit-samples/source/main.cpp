//RECEPTEUR
#include "MicroBit.h"

// Initialisation de la micro:bit
MicroBit uBit;

// Callback pour la réception de données radio
void onRadioDataReceived(MicroBitEvent) {
    PacketBuffer packet = uBit.radio.datagram.recv(); // Récupère le message
    if (packet.length() > 1) {
        ManagedString receivedData((char *)packet.getBytes(), packet.length());
        
        // Affiche les données reçues via le port série
        uBit.serial.printf("Data received: %s\r\n", receivedData.toCharArray());
        
        // Indique visuellement la réception sur l'écran LED
        uBit.display.print("*");
        uBit.sleep(200);
        uBit.display.clear();
    }
}

int main() {
    // Initialisation de la micro:bit
    uBit.init();

    // Configure le groupe et la puissance radio
    uBit.radio.setGroup(1);  // Définit le même groupe que l'émetteur
    uBit.radio.setTransmitPower(6); // Puissance maximale
    uBit.radio.enable();  // Active le module radio

    // Ajoute un listener pour la réception de données radio
    uBit.messageBus.listen(MICROBIT_ID_RADIO, MICROBIT_RADIO_EVT_DATAGRAM, onRadioDataReceived);

    // Laisser le programme tourner
    release_fiber();
}