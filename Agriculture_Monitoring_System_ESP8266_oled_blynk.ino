#define BLYNK_TEMPLATE_ID "TMPL3w6nz97fL"
#define BLYNK_TEMPLATE_NAME "Agriculture Monitoring"
#define BLYNK_AUTH_TOKEN "JKEjUSOrNeyUcrP8Coh78K03sWXAcu1w"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

char auth[] = "BLYNK_AUTH_TOKEN";
char ssid[] = "RKJ";
char pass[] = "ritikjha22";

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define DHTPIN D4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define SOIL_PIN A0
#define RAIN_PIN D5
#define RELAY_PIN D6
#define BUZZER_PIN D7

int soilMoisture;
int rainState;
float temp, hum;

BlynkTimer timer;

void pumpON()
{
  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(BUZZER_PIN, HIGH);
  delay(500);
  digitalWrite(BUZZER_PIN, LOW);
  Blynk.virtualWrite(V4, 1);
}

void pumpOFF()
{
  digitalWrite(RELAY_PIN, HIGH);
  Blynk.virtualWrite(V4, 0);
}

void sendSensorData()
{
  soilMoisture = analogRead(SOIL_PIN);
  soilMoisture = map(soilMoisture, 1023, 300, 0, 100);

  rainState = digitalRead(RAIN_PIN);

  temp = dht.readTemperature();
  hum = dht.readHumidity();

  Blynk.virtualWrite(V0, soilMoisture);
  Blynk.virtualWrite(V1, temp);
  Blynk.virtualWrite(V2, hum);
  Blynk.virtualWrite(V3, rainState);

  // Automatic Pump Logic
  if(soilMoisture < 30 && rainState == HIGH)
  {
    pumpON();
  }
  else
  {
    pumpOFF();
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Soil: ");
  display.print(soilMoisture);
  display.println("%");

  display.print("Temp: ");
  display.print(temp);
  display.println("C");

  display.print("Hum: ");
  display.print(hum);
  display.println("%");

  display.print("Rain: ");
  if(rainState==LOW) display.println("YES");
  else display.println("NO");

  display.display();
}

BLYNK_WRITE(V5)
{
  int pumpState = param.asInt();
  if(pumpState == 1)
    pumpON();
  else
    pumpOFF();
}

void setup()
{
  Serial.begin(9600);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(RAIN_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, HIGH);

  dht.begin();

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println("OLED Failed");
    for(;;);
  }

  display.clearDisplay();

  Blynk.begin(auth, ssid, pass);
  timer.setInterval(2000L, sendSensorData);
}

void loop()
{
  Blynk.run();
  timer.run();
}