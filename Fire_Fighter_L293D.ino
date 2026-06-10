#include <AFMotor.h>

// Motors
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

// Pins
const int flameSensor = 18;
const int relayPin = 19;

void setup()
{
  pinMode(flameSensor, INPUT);
  pinMode(relayPin, OUTPUT);

  digitalWrite(relayPin, HIGH);

  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);

  Serial.begin(9600);
}

void loop()
{
  int flame = digitalRead(flameSensor);

  if (flame == LOW)   // Fire detected
  {
    Serial.println("Fire Detected!");

    stopRobot();
    delay(500);

    digitalWrite(relayPin, LOW);  // Pump ON
    delay(5000);                   // Spray water

    digitalWrite(relayPin, HIGH);   // Pump OFF
    delay(1000);
  }
  else
  {
    moveForward();  // Patrol mode
  }
}

// Forward
void moveForward()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

// Stop
void stopRobot()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}