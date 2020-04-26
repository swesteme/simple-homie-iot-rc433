# Simple Homie IOT Esp8266 RC 433 MHz
[![Build Status](https://travis-ci.org/swesteme/simple-homie-iot-rc433.svg?branch=develop)](https://travis-ci.org/swesteme/simple-homie-iot-rc433)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://raw.githubusercontent.com/swesteme/simple-homie-iot-rc433/develop/LICENSE)
__________

This small library is just a distilled part of code from my use the great Homie IOT Esp8266 library by Marvin Roger and Ian Hubbertz.

You may use it if you have ESPs switching things on and off using 433MHz sensors and transmitters.

**Note:** this is only one of the libraries. If you use other sensors as well you might be interested in the following libraries: `simple-homie-infrared` or `simple-homie-capacitivebutton`.

## Example
A simple example containing the `killconfig` Homie node from the parent library. It can be signalled via MQTT to erase the Homie configuration on device and reboot into AccessPoint mode.

The following lines declare a remote control receiver object, which is also connected to a rc 433 MHz transmitter, as well as a few devices that are switched using MQTT commands and sending codes for Intertechno power outlets.


```
#include <Arduino.h>
#include <KillConfigNode.h>
#include <RcReceiver.h>
#include <Switch.h>

// Homie node receiving the signal to kill the Homie configuration and reboot.
KillConfigNode killConfigNode;

// RC sender/receiver object
RcReceiver rcReceiver(D1, D2, "Funk-Sensor");

// Use intertechno remote controlled (433Mhz) power switches
Switch intertechno1(&rcReceiver, "intertechno1", "Intertechno1", 262213,
                    262212);
Switch intertechno2(&rcReceiver, "intertechno2", "Intertechno2", 262229,
                    262228);
Switch intertechno3(&rcReceiver, "intertechno3", "Intertechno3", 282709,
                    282708);

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
```

## Installation
Install the library by adding it to your project's platformio.ini:

```
lib_deps =
    simple-homie-iot-rc433
```
