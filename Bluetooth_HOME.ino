#define bulb 5
#define fan 6

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(bulb, OUTPUT);
pinMode(fan, OUTPUT); 
digitalWrite(bulb, HIGH);
digitalWrite(fan, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available())
{
  char val = Serial.read();
  Serial.println(val);

  if (val == 'A') 
  {
    digitalWrite(bulb, LOW);
  } 

  else if (val == 'B')
  {
    digitalWrite(bulb, HIGH);
  }
  else if (val == 'C')
  {
    digitalWrite(fan, LOW);
  }
  else if (val == 'D')
  {
    digitalWrite(fan, HIGH);
  }
}
  delay(100);
}
