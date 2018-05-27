
#include "Keyboard.h"
#include "HID.h"

void setup() {
  Serial1.begin(115200);
  Keyboard.begin();
}

void loop() {
  char c;
  while (Serial1.available() > 0) {
    c = Serial1.read();
    Keyboard.write(c);
  }
}
