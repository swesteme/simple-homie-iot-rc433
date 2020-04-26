#pragma once

#include <RemoteButton.h>

class RcReceiver;

class RcRemoteButton : public RemoteButton {
  public:
    // constructor
    RcRemoteButton(RcReceiver *receiverNode, const char* id, const char* name, unsigned long code, unsigned long offCode);

  protected:
    virtual ResultState checkCode(unsigned long cmpCode) const;

  private:
    // switch off code
    unsigned long offCode;
};

