#include "BluetoothSerial.h"
BluetoothSerial serialBT;

#define bulb 26
#define fan 27

void setup() {
  // put your setup code here, to run once:
  serialBT.begin("ESP32-BT");
pinMode(bulb, OUTPUT);
pinMode(fan, OUTPUT);
digitalWrite(bulb, HIGH);
digitalWrite(fan, HIGH);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if (serialBT.available())
{
  char val = serialBT.read();
  Serial.println(val);

  if (val == '0') 
  {
    digitalWrite(bulb, LOW);
  }

  else if (val == '1')
  {
    digitalWrite(bulb, HIGH);
  }
  else if (val == '2')
  {
    digitalWrite(fan, LOW);
  }
  else if (val == '3')
  {
    digitalWrite(fan, HIGH);
  }
}
  delay(100);
}
