#include <Servo.h> 
Servo Myservo;
#define trigPin 9           // Trig Pin Of HC-SR04
#define echoPin 8        // Echo Pin Of HC-SR04
#define IN1 4                   //left motor 1st pin
#define IN2 5                  //left motor 2nd pin
#define IN3 6               //right motor 1st pin
#define IN4 7               //right motor 2nd pin
long duration, distance;

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);     // Set Motor Pins As O/P
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(trigPin, OUTPUT);       // Set Trig Pin As O/P To Transmit Waves
  pinMode(echoPin, INPUT);        //Set Echo Pin As I/P To Receive Reflected Waves
  Myservo.attach(10);
}
void loop() 
{
  Serial.begin(9600);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);       // Transmit Waves For 10us
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH);        // Receive Reflected Waves
  distance = duration / 58.2;                       // Get Distance
  Serial.println(distance);
  delay(10);
  if (distance > 15)               // Condition For Absence Of Obstacle            
  {
    Myservo.write(90);
    digitalWrite(IN1, HIGH);       // Move Forward
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);                                
    digitalWrite(IN4, LOW);                                                       
  }
  else if ((distance < 10)&&(distance > 0))            // Condition For Presence Of Obstacle
  {
    digitalWrite(IN1, LOW);     //Stop                
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);                                
    digitalWrite(IN4, LOW);
    delay(100);
    
    Myservo.write(0);
    delay(500);
    Myservo.write(180);
    delay(500);
    Myservo.write(90);
    delay(500);
    
    digitalWrite(IN1, LOW);     // Move Backward             
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);                                
    digitalWrite(IN4, HIGH);
    delay(500);
    digitalWrite(IN4, LOW);        //Stop                
    digitalWrite(IN3, LOW);
    digitalWrite(IN2, LOW);                                
    digitalWrite(IN1, LOW);  
    delay(100);  
    digitalWrite(IN4, LOW);     // Move Left     
    digitalWrite(IN3, LOW);   
    digitalWrite(IN1, HIGH);                                 
    digitalWrite(IN2, LOW);  
    delay(500);
  }

}
