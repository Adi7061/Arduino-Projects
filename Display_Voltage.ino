#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define BV A3   //Battery Voltage
#define SV A2   //Solar Voltage
#define MV A1   //Motor Voltage
#define BR 3    //Battery Relay
#define SR 4    //Solar Relay
#define MR 5    //Motor Relay

float vOUT1 = 0.0;
float vIN1 = 0.0;
float vOUT2 = 0.0;
float vIN2 = 0.0;
float vOUT3 = 0.0;
float vIN3 = 0.0;
float R1 = 30000.0;
float R2 = 7500.0;

void setup() {
  Serial.begin(9600);
  pinMode(BV, INPUT);
  pinMode(SV, INPUT);
  pinMode(MV, INPUT);
  pinMode(BR, OUTPUT);
  pinMode(SR, OUTPUT);
  pinMode(MR, OUTPUT);
  digitalWrite(BR, HIGH);
  digitalWrite(SR, HIGH);
  digitalWrite(MR, HIGH);

  lcd.init();
  lcd.backlight();
}

void loop() {
  int value1 = analogRead(BV);
  vOUT1 = (value1 * 5.0) / 1024.0;
  vIN1 = vOUT1 / (R2 / (R1 + R2));

  int value2 = analogRead(SV);
  vOUT2 = (value2 * 5.0) / 1024.0;
  vIN2 = vOUT2 / (R2 / (R1 + R2));

  int value3 = analogRead(MV);
  vOUT3 = (value3 * 5.0) / 1024.0;
  vIN3 = vOUT3 / (R2 / (R1 + R2));

  lcd.setCursor(0, 0);
  lcd.print("BV:");
  lcd.print(vIN1);
  lcd.print("v");
  
  lcd.setCursor(9, 0);
  lcd.print("SV:");
  lcd.print(vIN2);
  lcd.print("v");
  
  lcd.setCursor(5, 1);
  lcd.print("MV:");
  lcd.print(vIN3);
  lcd.print("v ");
  

  Serial.print("BV : ");
  Serial.println(vIN1);
  Serial.print("SV : ");
  Serial.println(vIN2);
  Serial.print("MV : ");
  Serial.println(vIN3);
  
  delay(3000);

  if (Serial.available())
{
  int val = Serial.read();
  Serial.println(val);

  if (val == '0') 
  {
    digitalWrite(MR, LOW);
    digitalWrite(SR, HIGH);
    digitalWrite(BR, HIGH);
  }

  else if (val == '1')
  {
    digitalWrite(MR, HIGH);
    
  }
  else if (val == '2')
  {
    digitalWrite(MR, HIGH);
    digitalWrite(SR, LOW);
    digitalWrite(BR, HIGH);
  }
  else if (val == '3')
  {
    
    digitalWrite(SR, HIGH);
    
  }
  else if (val == '4')
  {
    digitalWrite(MR, HIGH);
    digitalWrite(SR, HIGH);
    digitalWrite(BR, LOW);
  }
  else if (val == '5')
  {
    digitalWrite(BR, HIGH);
    
  }
}
  delay(100); 
}