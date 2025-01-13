#include <Arduino.h>

// HC-SR04 핀 설정
const int TRIG_PIN = 9;
const int ECHO_PIN = 10;

const int GREEN_LED = 12;
const int YELLOW_LED = 8;
const int RED_LED = 6;

// 초음파의 속도 (공기 중에서 약 343m/s)
#define SOUND_SPEED 0.034  // cm/µs (1초에 34cm 이동)
#define CM_DIVIDER 2       // 초음파 왕복 거리 보정

void setup() {
  pinMode(TRIG_PIN, OUTPUT);  // TRIG 핀을 출력으로 설정
  pinMode(ECHO_PIN, INPUT);   // ECHO 핀을 입력으로 설정

  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  Serial.begin(9600);         // 시리얼 통신 시작
}

void loop() {
  // 초음파 송신
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);  // 안정화
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10); // 10µs 펄스 송신
  digitalWrite(TRIG_PIN, LOW);

  // 초음파 수신
  long duration = pulseIn(ECHO_PIN, HIGH);  // ECHO 핀에서 HIGH 신호 지속 시간 측정

  // 거리 계산
  float distance = (duration * SOUND_SPEED) / CM_DIVIDER;

  // 결과 출력
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 15) {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);
  } else if (distance > 10) {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, LOW);
  } else {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, HIGH);
  }

  delay(500);  // 0.5초 대기
}
