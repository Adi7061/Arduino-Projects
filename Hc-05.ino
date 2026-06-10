char Command;
void setup() {
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(7,OUTPUT);
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
while (Serial.available() > 0){
  Command = Serial.read();
  Serial.println(Command);
}

if (Command == 1){
  digitalWrite(4,HIGH);
  }
  if (Command == 2){
    digitalWrite(4,LOW);
  }
  if (Command == 3){
    digitalWrite(5,HIGH);
  }
  if (Command == 4){
    digitalWrite(5,LOW);
  }
  if (Command == 5){
    digitalWrite(6,HIGH);
  }
  if (Command == 6){
    digitalWrite(6,LOW);
  }
  if (Command == 7){
    digitalWrite(7,HIGH);
  }
  if (Command == 8){
    digitalWrite(7,LOW);
  }
}
