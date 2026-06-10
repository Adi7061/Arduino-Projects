//Bluetooth Control Edge Avoider
//Created By Ankuram Robo PVT.LTD.
// Starting of Program
#define buzz 7
#define IN_1 6      //  Left forward motor
#define IN_2 5     //  left backward motor
#define IN_3 4     //  right forward motor
#define IN_4 3     //  right backward motor
int distance1;
int duration1;
int distance2;
int duration2;
//Define pins for Ultrasonic sensor 
#define trigPin_Right 9
#define echoPin_Right 8
#define trigPin_Left 11
#define echoPin_Left 10
int Right, Left;

char command; 

void setup() 
{       
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
    pinMode(trigPin_Right, OUTPUT);
    pinMode(echoPin_Right, INPUT);
    pinMode(trigPin_Left, OUTPUT);
    pinMode(echoPin_Left, INPUT);
  pinMode(buzz, OUTPUT);
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT);
    
}

void Sonic1() {
    digitalWrite(trigPin_Right, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_Right, HIGH);  // Transmit Waves For 10us
  delayMicroseconds(10);
  digitalWrite(trigPin_Right, LOW);
  duration1 = pulseIn(echoPin_Right, HIGH);  // Receive Reflected Waves
  distance1 = ((duration1 / 2) * 0.343)/10;
}

void Sonic2() {
    digitalWrite(trigPin_Left, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_Left, HIGH);  // Transmit Waves For 10us
  delayMicroseconds(10);
  digitalWrite(trigPin_Left, LOW);
  duration2 = pulseIn(echoPin_Left, HIGH);  // Receive Reflected Waves
  distance2 = ((duration2 / 2) * 0.343)/10;
}

void loop(){
  Sonic1();
  Sonic2();

    // Serial.print("Right");
    // Serial.println(digitalRead(IR1));
    // Serial.print("Left");
    // Serial.println(digitalRead(IR2));
    
  if(Serial.available() > 0){ 
    command = Serial.read();
    Serial.println(command);
    
    
    switch(command){
    case 'F':forward();
      break;
    case 'B':backward();
      break;
    case 'L':right();
      break;
    case 'R':left();
      break;
    case 'G':FLeft();
      break;
    case 'H':BLeft();
      break;
    case 'I':FRight();
      break;
    case 'J':BRight();
      break;

    }
    
    //int Right = A0;
    //int Left = A1;
    // long distance1 = getDistance(trigPin_Right, echoPin_Right);
    // long distance2 = getDistance(trigPin_Left, echoPin_Left);
    Serial.print("Left Sensor: "); 
    Serial.print(distance1);
    Serial.print(" cm | Right Sensor: "); 
    Serial.print(distance2);
    Serial.println(" cm");
    if(distance1 > 10 || distance2 > 10) {

      backward();
      
    }
    if(distance1 < 10 || distance2 < 10){
      command = Serial.read();
    }
 }
}

void forward()
{
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
}

void backward()
{
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
}

void left()
{
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, HIGH);
    digitalWrite(IN_3, HIGH);
    digitalWrite(IN_4, LOW);
}

void right()
{
    digitalWrite(IN_1, HIGH);
    digitalWrite(IN_2, LOW);
    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, HIGH);
} 

void FRight()
{
    digitalWrite(IN_1, HIGH);
    digitalWrite(IN_2, LOW);
    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, HIGH);
}

void BRight()
{
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, HIGH);
    digitalWrite(IN_3, HIGH);
    digitalWrite(IN_4, LOW);
}

void FLeft()
{
    digitalWrite(IN_1, HIGH);
    digitalWrite(IN_2, LOW);
    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, HIGH);
}

void BLeft()
{
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, HIGH);
    digitalWrite(IN_3, HIGH);
    digitalWrite(IN_4, LOW);
}

void Stop()
{
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, LOW);
    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, LOW);
}
/*
      long distance1 = getDistance(trigPin_Right, echoPin_Right);
    long distance2 = getDistance(trigPin_Left, echoPin_Left);
    Serial.print("Left Sensor: "); Serial.print(distance1);
    Serial.print(" cm | Right Sensor: "); Serial.print(distance2);
    Serial.println(" cm");

    if (distance1 < 10 || distance2 < 15) { // Edge detected
        stopMoving();
        delay(500);
        moveBackward();
        delay(500);
        turnRight();
        delay(500);
    } else {
        moveForward();
    }
*/