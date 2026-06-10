#include <esp_now.h>
#include <WiFi.h>

// Define Pins
const int motorL1 = 33;
const int motorL2 = 32;
const int motorR1 = 26;
const int motorR2 = 25;
const int hornPin = 27;

// Structure must match the Transmitter
typedef struct struct_message {
    int x;
    int y;
    int sw;
} struct_message;

struct_message inputData;

// Function to move motors
void controlMotors(int xVal, int yVal) {
  // Map 0-4095 to -255 to 255
  inputData.x = map(inputData.x, 0, 4095, 0, 100);
  inputData.y = map(inputData.y, 0, 4095, 0, 100);
  Serial.print("X: ");
  Serial.print(inputData.x);
  Serial.print("   ");
  Serial.print("Y: ");
  Serial.println(inputData.y);

  if ((inputData.x > 50 && inputData.x <= 100)&&(inputData.y >= 40 && inputData.y <= 50)){
    digitalWrite(motorL1, HIGH);
    digitalWrite(motorL2, LOW);
    digitalWrite(motorR1, HIGH);
    digitalWrite(motorR2, LOW);
  }
  // BACKWARD
  else if ((inputData.x < 40 && inputData.x >= 0)&&(inputData.y >= 40 && inputData.y <= 50)){
    digitalWrite(motorL1, LOW);
    digitalWrite(motorL2, HIGH);
    digitalWrite(motorR1, LOW);
    digitalWrite(motorR2, HIGH);
  }
  // Left
  else if ((inputData.y < 40 && inputData.y >= 0)&&(inputData.x >= 40 && inputData.x <= 50)){
    digitalWrite(motorL1, LOW);
    digitalWrite(motorL2, HIGH);
    digitalWrite(motorR1, HIGH);
    digitalWrite(motorR2, LOW);
  }
  // Right
  else if ((inputData.y > 50 && inputData.y <= 100)&&(inputData.x >= 40 && inputData.x <= 50)){
    digitalWrite(motorL1, HIGH);
    digitalWrite(motorL2, LOW);
    digitalWrite(motorR1, LOW);
    digitalWrite(motorR2, HIGH);
  }
  // STOP
  else{
    digitalWrite(motorL1, LOW);
    digitalWrite(motorL2, LOW);
    digitalWrite(motorR1, LOW);
    digitalWrite(motorR2, LOW);
  }
  // int forwardBackward = map(yVal, 0, 4095, 255, -255);
  // int leftRight = map(xVal, 0, 4095, -255, 255);

  // // Differential Steering Logic
  // int leftSpeed = forwardBackward + leftRight;
  // int rightSpeed = forwardBackward - leftRight;

  // // Constrain values to PWM range
  // leftSpeed = constrain(leftSpeed, -255, 255);
  // Serial.print("leftSpeed:");
  // Serial.print(leftSpeed);
  // rightSpeed = constrain(rightSpeed, -255, 255);
  // Serial.print("rightSpeed:");
  // Serial.println(rightSpeed);

  // // Left Motor Control
  // if (leftSpeed > 20) {
  //   analogWrite(motorL1, leftSpeed);
  //   analogWrite(motorL2, 0);
  // } else if (leftSpeed < -20) {
  //   analogWrite(motorL1, 0);
  //   analogWrite(motorL2, abs(leftSpeed));
  // } else {
  //   analogWrite(motorL1, 0);
  //   analogWrite(motorL2, 0);
  // }

  // // Right Motor Control
  // if (rightSpeed > 20) {
  //   analogWrite(motorR1, rightSpeed);
  //   analogWrite(motorR2, 0);
  // } else if (rightSpeed < -20) {
  //   analogWrite(motorR1, 0);
  //   analogWrite(motorR2, abs(rightSpeed));
  // } else {
  //   analogWrite(motorR1, 0);
  //   analogWrite(motorR2, 0);
  // }
}

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&inputData, incomingData, sizeof(inputData));

  // Control Horn (Switch is active LOW usually)
  if (inputData.sw == 0) {
    digitalWrite(hornPin, HIGH);
  } else {
    digitalWrite(hornPin, LOW);
  }

  controlMotors(inputData.x, inputData.y);
}

void setup() {
  Serial.begin(115200);
  
  pinMode(motorL1, OUTPUT);
  pinMode(motorL2, OUTPUT);
  pinMode(motorR1, OUTPUT);
  pinMode(motorR2, OUTPUT);
  pinMode(hornPin, OUTPUT);

  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK) return;
  
  esp_now_register_recv_cb(esp_now_recv_cb_t(OnDataRecv));
}

void loop() {
  // Logic is handled in the callback
}