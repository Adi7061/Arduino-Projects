#include <SPI.h>
#include <nRF24L01.h>
#include "RF24.h"

int IN_1 = 6;
int IN_2 = 5;
int IN_3 = 4;
int IN_4 = 3;

int data[2];

RF24 radio(8, 7);  //(CE, CSN)
const byte address[] = "node1";

//uint64_t pipe = 0xE8E8F0F0E1LL;

void setup() {
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT);

  Serial.begin(9600);
  // radio.begin();
  // radio.openReadingPipe(1, pipe);
  // radio.startListening();
  radio.begin();  // initializes the operations of the chip
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  if (radio.available() > 0) {
    radio.read(&data, sizeof(data));
    Serial.print("X:");
    Serial.print(data[0]);
    Serial.print("  ");
    Serial.print("Y:");
    Serial.print(data[1]);
    Serial.println("  ");

    if (data[0] > 0 && data[0] < 100 && data[1] > 99 && data[1] < 151)  // Right Turn
    {
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
    }
    if (data[0] > 150 && data[0] < 255 && data[1] > 99 && data[1] < 151)  // Left Turn
    {
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
    }
    if (data[0] > 99 && data[0] < 151 && data[1] > 99 && data[1] < 151)  // Stop
    {
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
    }


    if (data[1] > 0 && data[1] < 100 && data[0] > 99 && data[0] < 151)  //Forward
    {
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
    }
    if (data[1] > 150 && data[1] < 255 && data[0] > 99 && data[0] < 151)  // Backward
    {
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
    }
    if (data[1] > 99 && data[1] < 151 && data[0] > 99 && data[0] < 151)  // Stop
    {
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
    }
  }
}