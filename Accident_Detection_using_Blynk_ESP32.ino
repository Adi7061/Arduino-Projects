#define BLYNK_TEMPLATE_ID "TMPL3x-F7MhHd"
#define BLYNK_TEMPLATE_NAME "Accident Detection"
#define BLYNK_AUTH_TOKEN "o7TT6BVWRsMijFc0BGoQoTDgjuD6sJxp"
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <TinyGPS++.h>
#include <HardwareSerial.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ======== BLYNK CREDENTIALS =========
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Sadhana@JIO5G";
char pass[] = "Sadhana@9204";

// ======== GPS SETUP =========
TinyGPSPlus gps;
HardwareSerial gpsSerial(1); // Using UART1

// ======== ACCELEROMETER PINS =========
const int xPin = 34;
const int yPin = 35;
const int zPin = 32;

// ======== ACCIDENT DETECTION THRESHOLD =========
const float thresholdG = 3.0;  // Adjust based on testing
unsigned long lastAlertTime = 0;
const unsigned long alertCooldown = 60000; // 1 min cooldown

void setup() {
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Accident Detect ");
  lcd.setCursor(0, 1);
  lcd.print("    Msg Alert   ");
  delay(2000);

  Serial.begin(115200);
  gpsSerial.begin(9600, SERIAL_8N1, 16, 17); // RX=16, TX=17
  
  Blynk.begin(auth, ssid, pass);
  
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(zPin, INPUT);

  Serial.println("System Ready: Accident Detection with GPS and Blynk");
}

void loop() {
  Blynk.run();
  readAccelerometer();
  readGPS();
}

// ======== READ ACCELEROMETER =========
void readAccelerometer() {
  int xRaw = analogRead(xPin);
  int yRaw = analogRead(yPin);
  int zRaw = analogRead(zPin);

  // Convert raw to voltage (assuming 3.3V ref, 12-bit ADC)
  float xVoltage = (xRaw * 3.3) / 4095.0;
  float yVoltage = (yRaw * 3.3) / 4095.0;
  float zVoltage = (zRaw * 3.3) / 4095.0;

  // Simulate acceleration (basic, no calibration)
  float magnitude = sqrt(xVoltage * xVoltage + yVoltage * yVoltage + zVoltage * zVoltage);

  // Send raw values to Blynk (optional)
  Blynk.virtualWrite(V1, xVoltage);
  Blynk.virtualWrite(V2, yVoltage);
  Blynk.virtualWrite(V3, zVoltage);

  Serial.printf("Acceleration Magnitude: %.2f g\n", magnitude);
  lcd.setCursor(0, 0);
  lcd.print("Acceleration    ");
  lcd.setCursor(0, 1);
  lcd.print("Magnitude  ");
  lcd.setCursor(11, 1);
  lcd.print(magnitude);
  lcd.setCursor(15, 1);
  lcd.print("g");

  if (magnitude > thresholdG && millis() - lastAlertTime > alertCooldown) {
    sendAccidentAlert();
    lastAlertTime = millis();
  }
}

// ======== READ GPS DATA =========
void readGPS() {
  while (gpsSerial.available()) {
    gps.encode(gpsSerial.read());
  }

  if (gps.location.isUpdated()) {
    float lat = gps.location.lat();
    float lon = gps.location.lng();
    Serial.printf("GPS: Lat: %.6f, Lon: %.6f\n", lat, lon);

    Blynk.virtualWrite(V4, lat);
    Blynk.virtualWrite(V5, lon);
    Blynk.virtualWrite(V6, String(lat, 6) + "," + String(lon, 6));
  }
}

// ======== SEND ALERT =========
void sendAccidentAlert() {
  float lat = gps.location.lat();
  float lon = gps.location.lng();

  String msg = "🚨 Accident Detected!\nLocation: " + String(lat, 6) + "," + String(lon, 6);
  lcd.setCursor(0, 0);
  lcd.print("Accident Detect!");
  lcd.setCursor(0, 1);
  lcd.print(lat);
  lcd.setCursor(8, 1);
  lcd.print(lon);

  Blynk.logEvent("accident_alert", msg); // Requires event named `accident_alert`

  Serial.println("ALERT SENT TO BLYNK!");
}
