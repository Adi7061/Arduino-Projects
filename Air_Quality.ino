// Air quality Monitoring System
#include<LiquidCrystal_I2C.h>
#include<DHT.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(7, DHT11);

#define mq9 A2
#define mq135 A1
#define mq6 A0
#define buzz 3
int val;
int val1;
int val2; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  pinMode(mq9, INPUT);
  pinMode(mq135, INPUT);
  pinMode(mq6, INPUT);
  pinMode(buzz, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("  Air Quality   ");
  lcd.setCursor(0, 1);
  lcd.print("     System     ");
  // lcd.clear();
  delay(2000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(buzz, LOW); 
  val = analogRead(mq9);
  int v1 = map(val, 0, 1023, 0, 100);
  val1 = analogRead(mq135);
  int v2 = map(val1, 0, 1023, 0, 100);
  val2 =  analogRead(mq6);
  int v3 = map(val2, 0, 1023, 0, 100);
  Serial.println(v1);
  Serial.println(v2);
  Serial.println(v3);
  // delay(100);
  int t = dht.readTemperature();
  lcd.setCursor(0, 0);
  lcd.print("MQ9=");
  lcd.print(v1);
  lcd.print("% ");
  lcd.setCursor(9, 0);
  lcd.print("MQ6=");
  lcd.print(v3);
  lcd.print("% ");
  lcd.setCursor(0, 1);
  lcd.print("MQ135=");
  lcd.print(v2);
  lcd.print("% ");
  lcd.setCursor(11, 1);
  lcd.print("T=");
  lcd.print(t);
  lcd.print("C");
  
  if(v1 > 50 || v2 > 80 || v3 > 50){
    digitalWrite(buzz, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("  Harmful Gas   ");
  }
  
}
