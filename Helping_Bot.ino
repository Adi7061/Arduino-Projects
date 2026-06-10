// Starting of Program
#define IN_1 5     //  Left forward motor
#define IN_2 4    //  left backward motor
#define IN_3 3    //  right forward motor
#define IN_4 2    //  right backward motor
#define led 6     //  light
#include <Servo.h>
Servo servo;


char val;
void setup()
{
  Serial.begin(9600);
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(led, OUTPUT);
  servo.attach(7);
  servo.write(90);
}
void loop()
{
  digitalWrite(8, LOW);
   while (Serial.available() > 0)
 {
   val = Serial.read();
   Serial.println(val);
 }
  if( val == 'F') // Forward
   {
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      
   }
  else if(val == 'B') // Backward
    {
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      
    }

    else if(val == 'R') //RIGHT
    {
    digitalWrite(IN_1, HIGH);
    digitalWrite(IN_2, LOW);
    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, HIGH);
    
    
    }
    else if(val == 'L') //LEFT
    {
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, HIGH);
    digitalWrite(IN_3, HIGH);
    digitalWrite(IN_4, LOW);
    
    }
    else if(val == 'S') //Stop
    {
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, LOW);
    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, LOW);
    
    }
    else if(val == 'G') //Forward Right

    {
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, HIGH);
    digitalWrite(IN_3, HIGH);
    digitalWrite(IN_4, LOW);
    
    }
    else if(val == 'H') //Backward Right
    {
    digitalWrite(IN_1, HIGH);
    digitalWrite(IN_2, LOW);
    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, HIGH);
    
    }
    else if(val == 'I') //Forward Left
    {
    digitalWrite(IN_1, HIGH);
    digitalWrite(IN_2, LOW);
    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, HIGH);
    
    } 
    else if(val == 'J') //Backward Left
    {
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, HIGH);
    digitalWrite(IN_3, HIGH);
    digitalWrite(IN_4, LOW);
    
    }
    else if (val == 'k')
    {
      digitalWrite(led, HIGH);
    }
    else if (val == 'l')
    {
      digitalWrite(led, LOW);
    }
    else if (val == 'm')
    {
      servo.write(0);
    }
    else if (val == 'n')
    {
      servo.write(180);
    }
    else if (val == 'o')
    {
      servo.write(90);
    }
}
