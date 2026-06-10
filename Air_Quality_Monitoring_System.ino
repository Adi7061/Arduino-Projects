// Air Quality Monitoring System
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include<DHT.h>
DHT dht(2, DHT11);
int gas = A3;
int value, value1;
void setup() {
  // put your setup code here, to run once:
  pinMode(gas, INPUT);
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("  AIR QUALITY   ");
  lcd.setCursor(0, 1);
  lcd.print("   MONITORING   ");
  delay(2000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(gas);
  value1 = map(value, 0, 1023, 0, 100);
  int t = dht.readTemperature();
  int h = dht.readHumidity();
  lcd.setCursor(0, 0);
  lcd.print("Gas value = ");
  lcd.print(value1);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("T = ");
  lcd.print(t);
  lcd.print("C");
  lcd.setCursor(8, 1);
    lcd.print("H = ");
  lcd.print(h);
  lcd.print("%");

}
