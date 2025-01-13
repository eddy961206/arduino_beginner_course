#include <Arduino.h>

int leds[] = {11, 9, 6, 5, 3};

// const int RED = 12;
// const int GREEN = 8;
// const int BLUE = 7;
// const int YELLOW = 4;
// const int WHITE = 2;

void setup() {

  for (int i = 0; i < 5; i++)
    pinMode(leds[i], OUTPUT);

  Serial.begin(9600);
}

void setRandomLedStates() {
  int numLeds = sizeof(leds) / sizeof(leds[0]);

  for (int i = 0; i < numLeds; i++) {
    if (random(2) == 0) {
      analogWrite(leds[i], random(256));
    } else {
      analogWrite(leds[i], random(256));
    }
  }
  delay(500);
}

void setSequentialLedStates() {
  int numLeds = sizeof(leds) / sizeof(leds[0]);

  for (int i = 0; i < numLeds; i++) {
    analogWrite(leds[i], random(256));
    delay(200);
    analogWrite(leds[i], random(256));
  }
}

void setRed0to256() {
  for (int i = 0; i < 256; i++) {
    analogWrite(leds[0], i);
    delay(10);
  }
  for (int i = 256; i >= 0; i--) {
    analogWrite(leds[0], i);
    delay(10);
  }
}

void loop() {
  // setRandomLedStates();
  // setSequentialLedStates();
  setRed0to256();
}


