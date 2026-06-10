//include library for servo
#include <Servo.h>

//define name of the servo motors
Servo upDownServo;
Servo rightLeftServo;

//define position name and value
#define left 50
#define right 140
#define middle 90
#define closed 90
#define Open 180
#define waitTime 1000


void setup(){
  //define pin numbers of the servo motors
  upDownServo.attach(11);
  rightLeftServo.attach(12);

  //starting position of the servo motors
  delay(10);
  upDownServo.write(closed);
  rightLeftServo.write(middle);
}

void loop(){
  
  upDownServo.write(closed);
  delay(waitTime);
  upDownServo.write(Open);
  delay(waitTime);
  rightLeftServo.write(right);
  delay(waitTime);
  rightLeftServo.write(left);
  delay(waitTime);
  rightLeftServo.write(middle);
  delay(waitTime);
  //upDownServo.write(closed);
  
}
