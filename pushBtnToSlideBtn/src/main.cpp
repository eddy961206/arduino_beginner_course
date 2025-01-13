#include <Arduino.h>

int flag = 0; // 0: 초기상태, 1: Pressed

void setup() {
  pinMode(8, OUTPUT);
  pinMode(7, INPUT);
  Serial.begin(9600);
}

void loop() {
  int value = digitalRead(7);

  Serial.println(value);
  Serial.print(" ");
  Serial.println(flag);

  if (value == HIGH) {  // 버튼이 눌렸을 때
    if (flag == 0) {  // 만약 이전에 버튼이 눌리지 않았으면
      flag = 1; // 버튼이 눌렸음을 기록
    }
  } else {  // 버튼이 놓였을 때
    if (flag == 1) { // 만약 이전에 버튼이 눌렸었으면
      flag = 0; // 버튼 놨으니까 flag 0으로 초기화 후 LED 토글
      if (digitalRead(8) == HIGH) {
        digitalWrite(8, LOW);
      } else {
        digitalWrite(8, HIGH);
      }
    }
  }

}