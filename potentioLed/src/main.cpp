#include <Arduino.h>


void setup() {
  pinMode(11, OUTPUT);
  // pinMode(A0, INPUT); // 아날로그는 항상 입력으로 설정되어 있음
  Serial.begin(9600);
}


void loop() {
  int analogValue = analogRead(A0);
  Serial.println(analogValue);
  int ledValue = map(analogValue, 0, 1023, 0, 255);
  analogWrite(11, ledValue);
  delay(10);
}

