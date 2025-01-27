#include <Arduino.h>
//**********************************************//
//********* I2C 가 아닌 일반 LCD 사용시 **********//
//**********************************************//
// #include <LiquidCrystal.h>
// // LiquidCrystal lcd (rs, enable, d4, d5, d6, d7);
// LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// void setup() {
//   lcd.begin(16, 2); // LCD의 컬럼 수와 로우 수를 설정합니다.
//   lcd.print("Hello, Arduino!");
// }
//***********************************************//

//**********************************************//
//************** I2C LCD 사용시 *****************//
//**********************************************//
#include <Wire.h> // I2C 통신 라이브러리
#include <LiquidCrystal_I2C.h>  // I2C LCD 라이브러리

// LiquidCrystal_I2C lcd(I2C 주소, 가로 글자 수, 세로 줄 수);
// LiquidCrystal_I2C lcd(0x3F, 16, 2);  // I2C 주소 0x27, 16x2 LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C 주소 0x27, 16x2 LCD

void setup() {
  lcd.init();       // LCD 초기화 (I2C LCD는 init() 함수 필요)
  lcd.backlight();  // 백라이트 켜기 (선택 사항, 필요 없으면 lcd.noBacklight(); 사용)
  lcd.setCursor(0, 0);  // 커서를 0번째 줄, 0번째 칸으로 이동
  // lcd.begin(16, 2);  // I2C LCD에서는 begin() 함수 불필요 (삭제)
  lcd.print("Hello, Arduino!");
}
 
void loop() {
  lcd.setCursor(0, 1);  // 커서를 0번째 줄, 1번째 칸으로 이동
  lcd.print(millis() / 1000);  // 현재 시간을 출력
  delay(1000);  // 1초 대기
}

// #include <Wire.h>
// void setup() {
//   Wire.begin();

//   Serial.begin(9600);
//   while (!Serial);             // Leonardo: wait for serial monitor
//   Serial.println("\nI2C Scanner");
// }

// void loop() {
//   byte error, address;
//   int nDevices;

//   Serial.println("Scanning...");

//   nDevices = 0;
//   for(address = 1; address < 127; address++ )
//   {
//     // The i2c_scanner uses return values of
//     // the Wire.endTransmission to see if
//     // a device did acknowledge to the address.
//     Wire.beginTransmission(address);
//     error = Wire.endTransmission();

//     if (error == 0)
//     {
//       Serial.print("I2C device found at address 0x");
//       if (address<16)
//         Serial.print("0");
//       Serial.print(address,HEX);
//       Serial.println("  !");

//       nDevices++;
//     }
//     else if (error==4)
//     {
//       Serial.print("Unknown error at address 0x");
//       if (address<16)
//         Serial.print("0");
//       Serial.println(address,HEX);
//     }
//   }
//   if (nDevices == 0) {
//     Serial.println("No I2C devices found\n");
//     Serial.println("error : ");
//     Serial.println(error);
//   } else {
//     Serial.println("done\n");
//   }

//   delay(5000);           // wait 5 seconds for next scan
// }