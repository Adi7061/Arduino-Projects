#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "Wire.h"
#include "I2Cdev.h"
#include <MPU6050.h>

MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;

int data[2];

RF24 radio(8, 7);  // (CE, CSN)
const byte address[] = "00001";

//uint64_t pipe = 0xE8E8F0F0E1LL;

void setup() {

  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();
  // radio.begin();
  // radio.openWritingPipe(pipe);

  radio.begin();  // initializes the operations of the chip
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {

  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);  //With this function, the acceleration and gyro values of the axis are taken.

  data[0] = map(ax, -17000, 17000, 0, 255);  //Send X axis data
  data[1] = map(ay, -17000, 17000, 0, 255);  //Send Y axis data

  radio.write(&data, sizeof(data));

  Serial.print("X:");
  Serial.print(data[0]);
  Serial.print("  ");

  Serial.print("Y:");
  Serial.print(data[1]);
  Serial.print("  ");
  Serial.println(" ");
}