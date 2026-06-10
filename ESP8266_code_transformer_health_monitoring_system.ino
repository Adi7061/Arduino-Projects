#define BLYNK_TEMPLATE_ID "TMPL3cykTpdNt"
#define BLYNK_TEMPLATE_NAME "Transformer"
#define BLYNK_AUTH_TOKEN "SC1NcBKJSGpvetIjW6dvH0sVUP3JaZbo"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Sadhana@JIO5G";
char pass[] = "Sadhana@9204";

String inputString = "";

void setup() {
  Serial.begin(9600); // Communication with Arduino Nano
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  Blynk.run();

  if (Serial.available() > 0) {
    char c = Serial.read();
    if (c == '\n') {
      parseData(inputString);
      inputString = "";
    } else {
      inputString += c;
    }
  }
}

void parseData(String data) {
  float temp, hum, volt, curr, oil;
  int idx1 = data.indexOf(',');
  int idx2 = data.indexOf(',', idx1 + 1);
  int idx3 = data.indexOf(',', idx2 + 1);
  int idx4 = data.indexOf(',', idx3 + 1);

  if (idx1 > 0 && idx2 > idx1 && idx3 > idx2 && idx4 > idx3) {
    temp = data.substring(0, idx1).toFloat();
    hum = data.substring(idx1 + 1, idx2).toFloat();
    volt = data.substring(idx2 + 1, idx3).toFloat();
    curr = data.substring(idx3 + 1, idx4).toFloat();
    oil = data.substring(idx4 + 1).toFloat();

    Blynk.virtualWrite(V0, temp);
    Blynk.virtualWrite(V1, hum);
    Blynk.virtualWrite(V2, volt);
    Blynk.virtualWrite(V3, curr);
    Blynk.virtualWrite(V4, oil);
  }
}
