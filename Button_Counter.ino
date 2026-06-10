#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <EEPROM.h>
#include <Servo.h>
Servo servo;
#define RESET LED_BUILTIN
Adafruit_SSD1306 oled(RESET);

#define bt_up A0    // UP Button
#define bt_down A1  // Down Button
#define bt_move A2  // Move Button

long d1 = 2, d2 = 1;  // d1: digit 1 , d2: digit 2
int flag1 = 0, flag2 = 0, timer = 0;
int time, Time;

void setup() {  // put your setup code here, to run once

  pinMode(bt_up, INPUT_PULLUP);
  pinMode(bt_down, INPUT_PULLUP);
  pinMode(bt_move, INPUT_PULLUP);
  servo.attach(4);
  servo.write(90);

  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Configura oled numero columnas y filas
  oled.clearDisplay();
  Titel_display();
  oled.clearDisplay();

  if (EEPROM.read(50) == 0) {
  } else {
    WriteEeprom();
  }

  EEPROM.write(50, 0);

  ReadEeprom();
}

void loop() {

  oled.clearDisplay();
  if (digitalRead(bt_up) == 0) {
    if (flag1 == 0) {
      flag1 = 1;
      d1 = d1 + 1;
      if (d1 > 9) { d1 = 0; }  //d2=d2+1;}
      //if(d2>9){d2=0;}
      WriteEeprom();
    }
  } else {
    flag1 = 0;
  }

  if (digitalRead(bt_down) == 0) {
    if (flag2 == 0) {
      flag2 = 1;
      d1 = d1 - 1;
      if (d1 < 0) { d1 = 9; }  //d2=d2-1;}
      //if(d2<0){d2=9;}
      WriteEeprom();
    }
  } else {
    flag2 = 0;
  }


  if (digitalRead(bt_move) == 0) {
    //oled.clearDisplay();
    //start();
    servo.write(70);
    delay(Time);
    servo.write(110);
    delay(Time);
  }

  Run_display();
}


void ReadEeprom() {
  d1 = EEPROM.read(1);
  time = d1;
  Time = time*1000;
  //d2 = EEPROM.read(2);
}

void WriteEeprom() {
  EEPROM.write(1, d1);
  //EEPROM.write(2, d2);
}

void Titel_display() {
  oled.clearDisplay();       // clear display
  oled.setCursor(12, 0);     // position the cursor
  oled.setTextSize(2);       // medium size font
  oled.setTextColor(WHITE);  // white is not default !
  oled.print("PATANJALI");
  oled.setCursor(10, 23);
  oled.setTextSize(1);  // smallest font
  oled.print("ANULOM VILOM YANTRA");
  oled.display();
  delay(3000);
}

void Run_display() {
  oled.clearDisplay();       // clear display
  oled.setCursor(12, 0);     // position the cursor
  oled.setTextSize(2);       // medium size font
  oled.setTextColor(WHITE);  // white is not default !
  oled.print("PATANJALI");
  oled.setCursor(30, 19);
  oled.setTextSize(2);       // medium size font
  oled.setTextColor(WHITE);  // white is not default !
  oled.print("0");
  oled.print(d1);
  oled.setCursor(70, 19);
  oled.setTextSize(2);  // smallest font
  oled.print("Sec");
  oled.display();
}

void start() {
  oled.clearDisplay();       // clear display
  oled.setCursor(12, 0);     // position the cursor
  oled.setTextSize(2);       // medium size font
  oled.setTextColor(WHITE);  // white is not default !
  oled.print("PATANJALI");
  oled.setCursor(30, 19);
  oled.setTextSize(2);       // medium size font
  oled.setTextColor(WHITE);  // white is not default !
  oled.print("START");
  oled.display();
}
