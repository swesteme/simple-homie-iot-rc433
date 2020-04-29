# Simple Homie IOT Esp8266 RC 433 MHz
[![Build Status](https://travis-ci.org/swesteme/simple-homie-iot-rc433.svg?branch=develop)](https://travis-ci.org/swesteme/simple-homie-iot-rc433)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://raw.githubusercontent.com/swesteme/simple-homie-iot-rc433/develop/LICENSE)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square)](http://makeapullrequest.com)
__________

This small library is just a distilled part of code from my use the great Homie IOT Esp8266 library by Marvin Roger and Ian Hubbertz.

You may use it if you have ESPs switching things on and off using 433MHz sensors and transmitters.

**Note:** this is only one of the libraries. If you use other sensors as well you might be interested in the following libraries: [simple-homie-iot-ir](https://github.com/swesteme/simple-homie-iot-ir) or [simple-homie-iot-capacitivebutton](https://github.com/swesteme/simple-homie-iot-capacitivebutton).

## Basics
Please refer to the description in the [base library](https://github.com/swesteme/simple-homie-iot) for details about how switches, senders and receivers work, and how this connects to MQTT topics.

## Example
A simple example containing the `killconfig` Homie node from the parent library. It can be signalled via MQTT to erase the Homie configuration on device and reboot into AccessPoint mode.

The following lines declare a remote control receiver object, which is also connected to a rc 433 MHz transmitter, as well as a few devices that are switched using MQTT commands and sending codes for Intertechno power outlets.

```
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
Switch intertechno(&rcReceiver, "intertechno1", "Intertechno1", 262213, 262212);

// living room 433MHz remote control
RcRemoteButton buttonA(&rcReceiver, "buttonA", "Button A", 5244241, 5244244);

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

## Communication
- If you **have found a bug**, open an issue.
- If you **have a feature request**, open an issue.
- If you **want to contribute**, submit a pull request.

## License
The library is available under the MIT license. See the LICENSE file for more info.

Copyright (c) 2020 Sebastian Westemeyer
