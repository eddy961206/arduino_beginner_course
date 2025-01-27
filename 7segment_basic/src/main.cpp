#include <Arduino.h>

// 아두이노의 디지털 핀과 7세그먼트 연결
#define	A	4
#define	B	5
#define C	12
#define D	11
#define	E	10
#define	F	3
#define G	2
#define	DP	13

void setup() {
  
  // 7세그먼트와 연결된 디지털 핀을 출력 모드로 설정
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DP, OUTPUT);

  // 시리얼 통신 시작
  Serial.begin(9600);
  Serial.println("시리얼 모니터 시작");
}

// 7세그먼트 세그먼트 상태 출력 함수
void printSegmentStatus() {
  Serial.print("A:"); Serial.print(digitalRead(A)); Serial.print(" ");
  Serial.print("B:"); Serial.print(digitalRead(B)); Serial.print(" ");
  Serial.print("C:"); Serial.print(digitalRead(C)); Serial.print(" ");
  Serial.print("D:"); Serial.print(digitalRead(D)); Serial.print(" ");
  Serial.print("E:"); Serial.print(digitalRead(E)); Serial.print(" ");
  Serial.print("F:"); Serial.print(digitalRead(F)); Serial.print(" ");
  Serial.print("G:"); Serial.print(digitalRead(G)); Serial.print(" ");
  Serial.print("DP:"); Serial.println(digitalRead(DP));
}

// 7세그먼트로 숫자 0을 표시하는 함수
void number0() {
  Serial.println("number0() 호출");
  // Common Cathode: HIGH on, LOW off
  // Common Anode: LOW on, HIGH off
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(DP, LOW);
  printSegmentStatus();
}

// 7세그먼트로 숫자 1을 표시하는 함수
void number1() {
  Serial.println("number1() 호출");
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(DP, LOW);
  printSegmentStatus();
}

// 7세그먼트로 숫자 2를 표시하는 함수
void number2() {
  Serial.println("number2() 호출");
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(DP, LOW);
  printSegmentStatus();
}

// 7세그먼트로 숫자 3을 표시하는 함수
void number3() {
  Serial.println("number3() 호출");
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(DP, LOW);
  printSegmentStatus();
}

// 7세그먼트로 숫자 4를 표시하는 함수
void number4() {
  Serial.println("number4() 호출");
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(DP, LOW);
  printSegmentStatus();
}

// 7세그먼트로 숫자 5를 표시하는 함수
void number5() {
  Serial.println("number5() 호출");
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(DP, LOW);
  printSegmentStatus();
}

// 7세그먼트로 숫자 6을 표시하는 함수
void number6() {
  Serial.println("number6() 호출");
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(DP, LOW);
  printSegmentStatus();
}

// 7세그먼트로 숫자 7을 표시하는 함수
void number7() {
  Serial.println("number7() 호출");
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(DP, LOW);
  printSegmentStatus();
}

// 7세그먼트로 숫자 8을 표시하는 함수
void number8() {
  Serial.println("number8() 호출");
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(DP, LOW);
  printSegmentStatus();
}

// 7세그먼트로 숫자 9를 표시하는 함수
void number9() {
  Serial.println("number9() 호출");
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(DP, LOW);
  printSegmentStatus();
}


void loop() {
  
  // 7세그먼트로 0부터 9까지 숫자 출력
  
  number0();	delay(1000);
  number1();	delay(1000);
  number2();	delay(1000);
  number3();	delay(1000);
  number4();	delay(1000);
  number5();	delay(1000);
  number6();	delay(1000);
  number7();	delay(1000);
  number8();	delay(1000);
  number9();	delay(1000);
}