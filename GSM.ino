void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  /*Serial.println("ATD+919470798679");
  delay(1000);*/

  Serial.println("AT+CMGF=1");
  delay(1000);
  Serial.println("AT+CMGF=\"+919470798679\"\r");
  delay(1000);
  Serial.println("Hello");
  delay(1000);
  Serial.println("Good Morning");
  delay(1000);
  Serial.println((char)26);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
