//Bluetooth Control Edge Avoider
//Created By Ankuram Robo PVT.LTD.
// Starting of Program

#define IN_1 5      //  Left forward motor
#define IN_2 4     //  left backward motor
#define IN_3 3     //  right forward motor
#define IN_4 2     //  right backward motor
#define Buzz 6

//#define Buzz 
#define IR1 8
#define IR2 9
int Right, Left;

char command; 

void setup() 
{       
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(Buzz, OUTPUT);
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT);
    
}

void loop(){
  
  Serial.print("Right");
    Serial.println(digitalRead(IR1));
    Serial.print("Left");
    Serial.println(digitalRead(IR2));
    
  if(Serial.available() > 0){ 
    command = Serial.read(); 
    Stop(); 
    
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
    
    if(digitalRead(IR1) == 1 || digitalRead(IR2) == 1) {

      digitalWrite(Buzz, HIGH);
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      
    }else if(digitalRead(IR1) == 0 && digitalRead(IR2) == 0) {

      digitalWrite(Buzz, LOW);
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
    digitalWrite(IN_2, LOW);
    digitalWrite(IN_3, HIGH);
    digitalWrite(IN_4, LOW);
}

void right()
{
    digitalWrite(IN_1, HIGH);
    digitalWrite(IN_2, LOW);
    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, LOW);
} 

void FRight()
{
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, LOW);
    digitalWrite(IN_3, HIGH);
    digitalWrite(IN_4, LOW);
}

void BRight()
{
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, LOW);
    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, HIGH);
}

void FLeft()
{
    digitalWrite(IN_1, HIGH);
    digitalWrite(IN_2, LOW);
    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, LOW);
}

void BLeft()
{
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, HIGH);
    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, LOW);
}

void Stop()
{
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, LOW);
    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, LOW);
}