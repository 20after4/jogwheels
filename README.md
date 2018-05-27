# Overview

![Encoders](https://github.com/20after4/jogwheels/raw/master/images/encoders.png)

This is my 2 axis rotary encoder cnc pendant for CNC.js.

The rotary encoders send keystrokes to the host machine by emulating a USB HID
keyboard.  Each single-notch rotation on an encoder sends a single keystroke:

* The X-axis encoder sends *LEFT_ARROW* for counter-clockwise and *RIGHT_ARROW*
  for clockwise rotations.
* The Y-axis encoder sends *UP_ARROW* for counter-clockwise and *DOWN_ARROW*
  for clockwise rotations.

## Hardware

* 1x Arduino Uno
* 2x Rotary Encoders - I'm using two of these: [SMO 100PPR Electronic Hand
  Wheel Manual Pulse Encoder]<https://www.amazon.com/gp/product/B00PIAMLO0>

## Dependencies

* [HoodLoader2 Bootloader & USB Firmware]
  <https://github.com/NicoHood/HoodLoader2>
* [Arduino RotaryEncoder Library]
  <http://www.mathertel.de/Arduino/RotaryEncoderLibrary.aspx>
