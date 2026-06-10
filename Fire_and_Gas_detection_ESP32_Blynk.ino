#define BLYNK_TEMPLATE_ID "TMPL3caKbhxot"
#define BLYNK_TEMPLATE_NAME "Fire and Gas Alert"
#define BLYNK_AUTH_TOKEN "liOi15smoshHaSL-kAliRMH8HObirxF0"


#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Your_SSID";      // Replace with your WiFi Name
char pass[] = "Your_PASSWORD";          // Replace with your WiFi Password

#define MQ2_DOUT_PIN 32    // Digital Output pin for MQ2 DOUT
#define FLAME_PIN 35       // Digital pin for Flame Sensor

BlynkTimer timer;

void checkSensors() {
  int flameValue = digitalRead(FLAME_PIN); // Read Flame Sensor
  int gasValue = digitalRead(MQ2_DOUT_PIN); // Read Gas sensor DOUT (HIGH or LOW)

  // Display gas value in Serial Monitor
  Serial.print("Gas Value: ");
  Serial.println(gasValue == HIGH ? "Gas Detected" : "No Gas Detected");

  // GAS Detection: If gas detected (DOUT HIGH)
  if (gasValue == HIGH) {    
    Blynk.logEvent("gas_alert", "⚠️ Gas Detected!");
  }

  // FIRE Detection: Flame sensor output is LOW when flame is detected
  if (flameValue == LOW) { // LOW = Flame Detected
    Blynk.logEvent("fire_alert", "🔥 Fire Detected!");
  }

  // Debugging (Optional)
  Serial.print("Flame Sensor: ");
  Serial.println(flameValue == LOW ? "Flame Detected" : "No Flame");
}

void setup() {
  Serial.begin(115200);

  pinMode(MQ2_DOUT_PIN, INPUT);  // Set the DOUT pin of MQ2 sensor as input
  pinMode(FLAME_PIN, INPUT);     // Set the flame sensor pin as input

  // Connect to Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Set the interval for checking sensors (every 2 seconds)
  timer.setInterval(2000L, checkSensors);
}

void loop() {
  Blynk.run();    // Keep Blynk app running
  timer.run();    // Run the timer to check sensors periodically
}
