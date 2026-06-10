#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// OLED setup
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// DHT setup
#define DHTPIN D4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Pins
#define SOIL_PIN A0
#define RAIN_PIN D5
#define RELAY_PIN D6
#define Buzz D7

void setup() {
  Serial.begin(115200);

  pinMode(RAIN_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(Buzz, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);

  dht.begin();

  // OLED start
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found");
    while(true);
  }

  display.clearDisplay();
}

void loop() {
  // Read sensors
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int soil = analogRead(SOIL_PIN);
  int rain = digitalRead(RAIN_PIN);

  // Convert soil value (adjust as needed)
  int soilPercent = map(soil, 1023, 300, 0, 100);

  // Pump logic
  if(soilPercent < 30 && rain == HIGH) {
    digitalWrite(RELAY_PIN, LOW); // Pump ON
    digitalWrite(Buzz, HIGH);
    delay(500);
    digitalWrite(Buzz, LOW);
  } else {
    digitalWrite(RELAY_PIN, HIGH); // Pump OFF
    digitalWrite(Buzz, LOW);
  }

  // OLED Display
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0,0);
  display.println("AGRI MONITOR");

  display.setCursor(0,10);
  display.print("Temp: ");
  display.print(temp);
  display.println(" C");

  display.setCursor(0,20);
  display.print("Humidity: ");
  display.print(hum);
  display.println(" %");

  display.setCursor(0,30);
  display.print("Soil: ");
  display.print(soilPercent);
  display.println(" %");

  display.setCursor(0,40);
  display.print("Rain: ");
  display.println(rain == LOW ? "YES" : "NO");

  display.setCursor(0,50);
  display.print("Pump: ");
  if(soilPercent < 30 && rain == HIGH) {
    display.println("ON");
  } else {
    display.println("OFF");
  }

  display.display();

  delay(2000);
}