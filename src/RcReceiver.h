#pragma once

#include <Receiver.h>
#include <Sender.h>
#include <RCSwitch.h>

class RcReceiver : public Receiver, public Sender {
 public:
  // constructor
  RcReceiver(int recvpin, int sendpin, const char* name);

  virtual bool send(const unsigned long code);

 protected:
  virtual void setup();

  virtual unsigned long fillReceivedCode();

 private:
  // RC receiver pointer
  RCSwitch receiver;
  // receiver pin
  int pinReceive;
  // sender pin
  int pinSend;
};
