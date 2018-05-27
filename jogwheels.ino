/*
    Copyright (c) 2018 Mukunda Modell
 
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <Encoder.h>


Encoder knobLeft(2, 5);
Encoder knobRight(3, 4);

#define KEY_LEFT_SHIFT 129
#define KEY_LEFT_ALT 130
#define KEY_RIGHT_ARROW 215
#define KEY_LEFT_ARROW 216
#define KEY_DOWN_ARROW 217
#define KEY_UP_ARROW 218


void setup() {
  Serial.begin(115200);
}

long positionLeft  = -999;
long positionRight = -999;

void loop() {
  long newLeft, newRight, i;

  delay(30);
  newLeft = knobLeft.read();
  if (newLeft / 4 != 0) {
    knobLeft.write(0);
    jog(KEY_LEFT_ARROW, KEY_RIGHT_ARROW, newLeft);
  }
  
  delay(30);
  newRight = knobRight.read();
  if (newRight / 4 != 0) {
    knobRight.write(0);
    jog(KEY_UP_ARROW, KEY_DOWN_ARROW, newRight );
  }
}

void jog(char moveDown, char moveUp, long newVal) {
  long i;
  if (newVal > 0) {
    newVal = newVal / 4;
    if (newVal == 0) {
      newVal = 1;
    }
    for (i=newVal; i > 0; i--) {
      Serial.write(moveDown);
      delay(1);
    }
  } else if (newVal < 0) {
    newVal = newVal / 4;
    if (newVal == 0) {
      newVal = -1;
    }
    for (i=newVal; i < 0; i++) {
      Serial.write(moveUp);
    }
  }
}

