#include <Arduino.h>


void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  int analogValue = analogRead(A0);
  Serial.println(analogValue);

  if (analogValue > 500) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
}


