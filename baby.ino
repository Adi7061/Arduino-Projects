#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>
#define IN1 5
#define IN2 6
#define IN3 9
#define IN4 10
#define pot A0
int value, val;

SoftwareSerial mySerial(2, 3); // RX, TX for SoftwareSerial
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  mySerial.begin(9600);  // Initialize SoftwareSerial
  Serial.begin(9600);  // Initialize hardware serial for debugging

  if (!myDFPlayer.begin(mySerial)) {  // Use software serial to communicate with DFPlayer
    Serial.println("Unable to begin:");
    Serial.println("1.Please recheck the connection!");
    Serial.println("2.Please insert the SD card!");
    while (true);
  }

  myDFPlayer.volume(30);  // Set volume level (0-30)
  myDFPlayer.play(1);     // Play the first track (0001.mp3)

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(pot, INPUT);
}

void loop() {
  static unsigned long lastTime = 0;
  unsigned long currentTime = millis();

  // Check if the music has stopped playing, and start it again
  if (myDFPlayer.available()) {
    if (myDFPlayer.readType() == DFPlayerPlayFinished) {
      myDFPlayer.play(1);  // Replay the first track
    }
  }

  delay(100);  // Small delay to prevent excessive checking

  value = analogRead(pot);
 val = map(value, 0, 1023, 0, 255);
 analogWrite(IN1, val);
 analogWrite(IN2, LOW);
 Serial.println(val);
}