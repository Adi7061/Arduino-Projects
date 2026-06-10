// Starting of Program
#include<Servo.h>
Servo servo;
#define IN_1 5     //  Left forward motor
#define IN_2 4    //  left backward motor
#define IN_3 3    //  right forward motor
#define IN_4 2    //  right backward motor
#define buzz 6
#define WL 12
#define RL 7

char val;
void setup()
{
  servo.attach(6);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(WL, OUTPUT);
  pinMode(RL, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
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
      digitalWrite(buzz, LOW);
      
   }
  else if(val == 'B') // Backward
    {
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      digitalWrite(buzz, HIGH);
      
    }

    else if(val == 'L') //LEFT
    {
    digitalWrite(IN_1, HIGH);
    digitalWrite(IN_2, LOW);
    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, HIGH);
    digitalWrite(buzz, LOW);
    
    
    }
    else if(val == 'R') //RIGHT
    {
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, HIGH);
    digitalWrite(IN_3, HIGH);
    digitalWrite(IN_4, LOW);
    digitalWrite(buzz, LOW);
    
    }
    else if(val == 'S') //Stop
    {
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, LOW);
    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, LOW);
    digitalWrite(buzz, LOW);
    
    
    }
    else if(val == 'G') //Forward Right

    {
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, HIGH);
    digitalWrite(IN_3, HIGH);
    digitalWrite(IN_4, LOW);
    digitalWrite(buzz, LOW);
    
    }
    else if(val == 'H') //Backward Right
    {
    digitalWrite(IN_1, HIGH);
    digitalWrite(IN_2, LOW);
    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, HIGH);
    digitalWrite(buzz, LOW);
    
    }
    else if(val == 'I') //Forward Left
    {
    digitalWrite(IN_1, HIGH);
    digitalWrite(IN_2, LOW);
    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, HIGH);
    digitalWrite(buzz, LOW);
    
    } 
    else if(val == 'J') //Backward Left
    {
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, HIGH);
    digitalWrite(IN_3, HIGH);
    digitalWrite(IN_4, LOW);
    digitalWrite(buzz, LOW);
    
    }
    else if(val == 'W')
    {
      digitalWrite(WL, HIGH);
    }
    else if(val == 'w')
    {
      digitalWrite(WL, LOW);
    }
    else if(val == 'U')
    {
      digitalWrite(RL, HIGH);
    }
    else if(val == 'u')
    {
      digitalWrite(RL, LOW);
    }
    else if(val == 'V')
    {
      servo.write(90);
    }
    else if(val == 'v')
    {
      servo.write(140);
    }
    val2 = map(val1, 0, 1023, 0, 180);

}
