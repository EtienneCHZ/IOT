/* // EMETTEUR
 #include "MicroBit.h"

MicroBit uBit;

void onDataReceived(MicroBitEvent) {
    ManagedString receivedData = uBit.serial.readUntil('\n');
    uBit.display.print("*");
    uBit.sleep(200);
    uBit.display.clear();
    uBit.radio.datagram.send(receivedData);
}

int main() {

    uBit.init();
    //uBit.serial.baud(115200);
    uBit.radio.setGroup(1);
    uBit.radio.setTransmitPower(6);
    uBit.radio.enable();
    uBit.serial.setRxBufferSize(32);
    uBit.serial.eventOn("\n"); 
    uBit.messageBus.listen(MICROBIT_ID_SERIAL, MICROBIT_SERIAL_EVT_DELIM_MATCH, onDataReceived);
    release_fiber();
} */