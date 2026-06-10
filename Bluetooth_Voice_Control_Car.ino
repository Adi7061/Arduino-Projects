#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1);  //TX, RX repectively
String command;

#define BUZZ 8
#define FL 7
#define RL 6
#define IN_1 5
#define IN_2 4
#define IN_3 3
#define IN_4 2

void setup() {
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT);
  pinMode(BUZZ, OUTPUT);
  pinMode(FL, OUTPUT);
  pinMode(RL, OUTPUT);
  digitalWrite(RL, LOW);
  mySerial.begin(9600);
}

void loop() {
  if (mySerial.available() == 1) {
    command = mySerial.readString();

    if (command == "go forward")  //forward
    {
      digitalWrite(RL, LOW);
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      //delay(10);
    } 
    else if (command == "go back")  // backward
    {
      digitalWrite(RL, HIGH);
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      delay(3000);
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      digitalWrite(RL, HIGH);
      //delay(10);
    } 
    else if (command == "turn right")  //RIGHT
    {
      digitalWrite(RL, LOW);
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      delay(300);
      digitalWrite(RL, HIGH);
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      //delay(10);
    } 
    else if (command == "turn left")  //LEFT
    {
      digitalWrite(RL, LOW);
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      delay(300);
      digitalWrite(RL, HIGH);
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      //delay(10);
    } 
    else if (command == "stop")  //Stop
    {
      digitalWrite(RL, HIGH);
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      //delay(10);
    } 
    else if (command == "circle") {
      digitalWrite(RL, LOW);
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      //delay(10);
    } 
    else if (command == "zigzag") {
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      delay(500);
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      delay(500);
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      delay(500);
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      delay(500);
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      delay(500);
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      delay(500);
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      delay(500);
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      delay(500);
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      delay(500);
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      delay(500);
    } 
    else if (command == "round")  // rotate on its axis
    {
      digitalWrite(RL, LOW);
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      //delay(10);
    } 
    else if (command == "horn") {
      digitalWrite(BUZZ, HIGH);
      delay(500);
      digitalWrite(BUZZ, LOW);
    } 
    else if (command == "light on") {
      digitalWrite(FL, HIGH);
    } 
    else if (command == "light off") {
      digitalWrite(FL, LOW);
    } 
    
    else if (command == "square") {
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      delay(1000);
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      delay(200);
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      delay(1000);
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      delay(200);
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      delay(1000);
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      delay(200);
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      delay(1000);
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      delay(200);
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      delay(1000);
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      //delay(1000);
    }
  }
}
