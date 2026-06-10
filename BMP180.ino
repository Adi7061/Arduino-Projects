#include <LiquidCrystal_I2C.h>
#include <SFE_BMP180.h>
#include <Wire.h>
 
#define ALTITUDE 55 //Enter your country evalution
 
LiquidCrystal_I2C lcd(0x27, 16, 2);
SFE_BMP180 bmp;
double T, P;
char status;
 
void setup() {
  Serial.begin(9600);
  bmp.begin();
  lcd.init();
  lcd.backlight();
}
 
void loop() {
  Serial.println();
  Serial.print("provided altitude: ");
  Serial.print(ALTITUDE, 0);
  Serial.print(" meters, ");
  Serial.print(ALTITUDE * 3.28084, 0);
  Serial.println("feet");
 
  status =  bmp.startTemperature();
  if (status != 0) {
    delay(status);
    status = bmp.getTemperature(T);
    if (status != 0) {
      Serial.print("Temperature :");
      lcd.setCursor(0, 0);
      lcd.print("Temp :");
      lcd.print(T, 2);
      lcd.print("C");
      lcd.print(" ");
      Serial.print(T, 2);
      Serial.println("*c");
    }
    status = bmp.startPressure(3);// 0 to 3
    if (status != 0) {
      delay(status);
      status = bmp.getPressure(P, T);
      if (status != 0) {
        Serial.print("absolute pressure: ");
        lcd.setCursor(0, 1);
        lcd.print("Pres :");
        lcd.print(P, 2);
        lcd.print("mb");
        lcd.print("  ");
        Serial.print(P, 2);
        Serial.println("mb");
      }
 
      delay(3000);
 
    }
  }
}