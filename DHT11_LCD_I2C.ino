// Air Quality Monitoring System
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include<DHT.h>
DHT dht(7, DHT11);
void setup() {
  // put your setup code here, to run once:
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("     WEATHER    ");
  lcd.setCursor(0, 1);
  lcd.print("   MONITORING   ");
  delay(2000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  int t = dht.readTemperature();
  int h = dht.readHumidity();
  lcd.setCursor(0, 0);
  lcd.print("Temperature=");
  lcd.print(t);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Humidity=");
  lcd.print(h);
  lcd.print("%");
}

9
