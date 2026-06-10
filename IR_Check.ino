#define IR 7
void setup() {
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int Sensor;
  Sensor = digitalRead(IR);
  Serial.println(Sensor);
}
