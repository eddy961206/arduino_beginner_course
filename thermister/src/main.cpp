#include <Arduino.h>


const int thermistorPin = A0;  // 서미스터 핀
const float BETA = 3950;       // NTC 서미스터의 BETA 값 (데이터시트 참조)

void setup() {
  Serial.begin(9600);
}

void loop() {
  int rawValue = analogRead(thermistorPin);  // 아날로그 값 읽기
  float resistance = 10000.0 * (1023.0 / rawValue - 1.0);  // 저항값 계산
  float temperature = 1.0 / (log(resistance / 10000.0) / BETA + 1.0 / 298.15) - 273.15;  // 온도 계산
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  delay(1000);
}
