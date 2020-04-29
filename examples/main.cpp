#include <Arduino.h>
#include <KillConfigNode.h>
#include <RcReceiver.h>
#include <RcRemoteButton.h>
#include <Switch.h>

// Homie node receiving the signal to kill the Homie configuration and reboot.
KillConfigNode killConfigNode;

// RC sender/receiver object
RcReceiver rcReceiver(D1, D2, "Radio-Sensor");

// Use intertechno remote controlled (433Mhz) power switches
Switch intertechno1(&rcReceiver, "intertechno1", "Intertechno1", 262213,
                    262212);
Switch intertechno2(&rcReceiver, "intertechno2", "Intertechno2", 262229,
                    262228);
Switch intertechno3(&rcReceiver, "intertechno3", "Intertechno3", 282709,
                    282708);

// living room 433MHz remote control
RcRemoteButton buttonA(&rcReceiver, "buttonA", "Button A", 5244241, 5244244);
RcRemoteButton buttonB(&rcReceiver, "buttonB", "Button B", 5247313, 5247316);
RcRemoteButton buttonC(&rcReceiver, "buttonC", "Button C", 5248081, 5248084);
RcRemoteButton buttonD(&rcReceiver, "buttonD", "Button D", 5248273, 5248276);

void setup() {
  Serial.begin(115200);
  Serial << endl << "Start setup..." << endl;

  // inititalise Homie library
  Homie_setFirmware("livingroom", "1.0.0");
  Homie.setup();

  Serial << "Finished setup." << endl;
}

void loop() {
  // run homie loop
  Homie.loop();
}
