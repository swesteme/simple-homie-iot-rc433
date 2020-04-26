#include "RcRemoteButton.h"
#include "RcReceiver.h"

RcRemoteButton::RcRemoteButton(RcReceiver* receiverNode, const char* id,
                               const char* name, unsigned long code,
                               unsigned long offCode)
    : RemoteButton(receiverNode, id, name, code), offCode(offCode) {}

ResultState RcRemoteButton::checkCode(unsigned long cmpCode) const {
  // check, whether the code matches
  if (getCode() == cmpCode) {
    return STATE_ON;
  }

  if (offCode == cmpCode) {
    return STATE_OFF;
  }

  return STATE_NO_MATCH;
}
