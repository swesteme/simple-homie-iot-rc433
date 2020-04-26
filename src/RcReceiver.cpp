#include "RcReceiver.h"

RcReceiver::RcReceiver(int recvpin, int sendpin, const char* name)
    : Receiver("remotecontrol", name),
      receiver(),
      pinReceive(recvpin),
      pinSend(sendpin) {}

void RcReceiver::setup() {
  HomieNode::setup();

  // sender/receiver settings
  receiver.setProtocol(1);
  receiver.setPulseLength(321);

  if (pinSend != -1) {
    receiver.enableTransmit(pinSend);
  }

  if (pinReceive != -1) {
    // get interrupt for pin
    int interrupt = digitalPinToInterrupt(pinReceive);

    // Receiver on interrupt 0 => that is pin #2
    // receiver settings
    receiver.enableReceive(interrupt);
  }
}

unsigned long RcReceiver::fillReceivedCode() {
  // check, whether new rc input is available
  if (receiver.available()) {
    unsigned long received = receiver.getReceivedValue();

    // reset state
    receiver.resetAvailable();

    return received;
  }

  return 0;
}

bool RcReceiver::send(unsigned long code) {
  receiver.send(code, 24);
  return true;
}
