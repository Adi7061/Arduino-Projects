#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int flame = D3;
int gas = A0;
int bled = D4;
int yled = D5;
int rled = D6;
int buzz = D7;
int fval, gval;

void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  lcd.backlight();
  pinMode(flame, INPUT);
  pinMode(gas, INPUT);
  pinMode(bled, OUTPUT);
  pinMode(yled, OUTPUT);
  pinMode(rled, OUTPUT);
  pinMode(buzz, OUTPUT);
  lcd.setCursor(0, 0);
  lcd.print("Fire & Gas Alert");
  lcd.setCursor(0, 1);
  lcd.print("   GROUP - 06   ");
  delay(3000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  fval = digitalRead(flame);
  gval = analogRead(gas);
  gval = map(gval, 0, 1023, 0, 100);
  lcd.setCursor(0, 0);
  lcd.print("Gas Value:");
  lcd.print(gval);
  if (gval < 30 && fval == 1) {
    lcd.setCursor(0, 1);
    lcd.print("                ");
    digitalWrite(bled, HIGH);
    digitalWrite(yled, LOW);
    digitalWrite(rled, LOW);
    digitalWrite(buzz, LOW);
  }
  if ((gval > 30 && gval < 60) && fval == 1) {
    lcd.setCursor(0, 1);
    lcd.print("                ");
    digitalWrite(bled, LOW);
    digitalWrite(yled, HIGH);
    digitalWrite(rled, LOW);
    digitalWrite(buzz, LOW);
  }
  if (gval > 60) {
    lcd.setCursor(0, 1);
    lcd.print("Gas is Detected!");
    digitalWrite(bled, LOW);
    digitalWrite(yled, LOW);
    digitalWrite(rled, HIGH);
    digitalWrite(buzz, HIGH);
  }
  if (fval == 0) {
    lcd.setCursor(0, 1);
    lcd.print("Fire is Detected!");
    digitalWrite(bled, HIGH);
    digitalWrite(yled, LOW);
    digitalWrite(rled, LOW);
    delay(50);
    digitalWrite(bled, LOW);
    digitalWrite(yled, HIGH);
    digitalWrite(rled, LOW);
    delay(50);
    digitalWrite(bled, LOW);
    digitalWrite(yled, LOW);
    digitalWrite(rled, HIGH);
    delay(50);
    digitalWrite(buzz, HIGH);
  }
}
