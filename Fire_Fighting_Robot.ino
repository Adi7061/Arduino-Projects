
#include <Servo.h>  //include servo.h library
Servo myservo;
 
int pos = 0;    
boolean fire = false;
 
#define Left 8      // left sensor
#define Forward 9   //front sensor
#define Right 10    // right sensor

#define IN_1 2       // left motor
#define IN_2 3       // left motor
#define IN_3 4       // right motor
#define IN_4 5       // right motor
#define pump 6
 
void setup()
{
  digitalWrite(pump, HIGH);
  pinMode(Left, INPUT);
  pinMode(Right, INPUT);
  pinMode(Forward, INPUT);
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT);
  pinMode(pump, OUTPUT);
 
  myservo.attach(11);
  myservo.write(90); 
}

void horn()
{
  digitalWrite(12, HIGH);
  delay(500);
  digitalWrite(12, LOW);
  delay(500);
}
 
void put_off_fire()
{
    delay (500);
 
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, LOW);
    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, LOW );
    
   digitalWrite(pump, LOW);
   delay(500);
    
    for (pos = 50; pos <= 130; pos++) { 
    myservo.write(pos); 
    delay(20);  
  }
  for (pos = 130; pos >= 50; pos--) { 
    myservo.write(pos); 
    delay(20);
  }
  
  digitalWrite(pump,HIGH);
  myservo.write(90);
  
  fire=false;
}
 
void loop()
{
   myservo.write(90); //Sweep_Servo();  
 
    if (digitalRead(Left) ==1 && digitalRead(Right)==1 && digitalRead(Forward) ==1) 
    {
    
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, LOW);
    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, LOW);
    }
    
    else if (digitalRead(Forward) ==0) 
    {
    digitalWrite(IN_1, HIGH);
    digitalWrite(IN_2, LOW);
    digitalWrite(IN_3, HIGH);
    digitalWrite(IN_4, LOW);
    fire = true;
    }
    
    else if (digitalRead(Left) ==0)
    {
    digitalWrite(IN_1, HIGH);
    digitalWrite(IN_2, LOW);
    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, LOW);
    }
    
    else if (digitalRead(Right) ==0) 
    {
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, LOW);
    digitalWrite(IN_3, HIGH);
    digitalWrite(IN_4, LOW);
    }
    
delay(300);//change this value to increase the distance
 
     while (fire == true)
     {
      horn();
      put_off_fire();
     }


}
