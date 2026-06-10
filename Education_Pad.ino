#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 4);
#include <Keypad.h>

const char number_of_rows = 4;
const char number_of_columns = 4;

char row_pins[number_of_rows] = {4, 5, 6, 7};
char column_pins[number_of_columns] = {8, 9, 10, 11};

char key_array[number_of_rows][number_of_columns] = {  
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
  };

Keypad k = Keypad(makeKeymap(key_array),row_pins , column_pins, number_of_rows, number_of_columns);


// Use pins 2 and 3 to communicate with DFPlayer Mini
static const uint8_t PIN_MP3_TX = 2; // Connects to module's RX
static const uint8_t PIN_MP3_RX = 3; // Connects to module's TX
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);

// Create the Player object
DFRobotDFPlayerMini player;

void setup() {


  // Init USB serial port for debugging
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  // Init serial port for DFPlayer Mini
  softwareSerial.begin(9600);

  // Start communication with DFPlayer Mini
  if (player.begin(softwareSerial)) {
    Serial.println("OK");

    // Set volume to maximum (0 to 30).
    player.volume(30);

  } else {
    Serial.println("Connecting to DFPlayer Mini failed!");
  }
    delay(1000);
}

void loop() {
  //input_val = digitalRead(PIR);
  char key_pressed = k.getKey();
  if(key_pressed) {
    Serial.println(key_pressed);
  }
  char value = digitalRead(key_pressed);
  Serial.println(value);
  switch (key_pressed) {
    //Serial.println(key_pressed);
    case 1: One(); break;
    case 2: Two(); break;
    case 3: Three(); break;
    case 4: Four(); break;
    case 5: Five(); break;
    case 6: Six(); break;
    case 7: Seven(); break;
    case 8: Eight(); break;
    case 9: Nine(); break;
    case 0: Zero(); break;
    case 'A': AAA(); break;
    case 'B': BBB(); break;
    case 'C': CCC(); break;
    case 'D': DDD(); break;
    case '#': Hash(); break;
    case '*': Astricks(); break;
  }

}

void One() {
  player.play(1);
}

void Two() {
  player.play(2);
}

void Three() {
  player.play(3);
}

void Four() {
  player.play(4);
}

void Five() {
  player.play(5);
}

void Six() {
  player.play(6);
}

void Seven() {
  player.play(7);
}

void Eight() {
  player.play(8);
}

void Nine() {
  player.play(9);
}

void Zero() {
  player.play(10);
}

void AAA() {
  player.play(11);
}

void BBB() {
  player.play(12);
}

void CCC() {
  player.play(13);
}

void DDD() {
  player.play(14);
}

void Hash() {
  player.play(15);
}

void Astricks() {
  player.play(16);
}






