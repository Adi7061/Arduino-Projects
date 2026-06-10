#define BLYNK_TEMPLATE_ID "TMPL3VtaUxyX9"
#define BLYNK_TEMPLATE_NAME "Home Automation"
#define BLYNK_AUTH_TOKEN "a-iSyVA-l9SrJNBJWUIOC0W0PXKcQ5X_"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "POCO M6 Plus 5G";
char pass[] = "00000000";

#define RELAY1 2
#define RELAY2 4

BLYNK_WRITE(V0)
{
  int value = param.asInt();
  digitalWrite(RELAY1, value);
}

BLYNK_WRITE(V1)
{
  int value = param.asInt();
  digitalWrite(RELAY2, value);
}

void setup()
{
  Serial.begin(115200);

  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);

  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();
}