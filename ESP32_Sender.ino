#include <esp_now.h>
#include <WiFi.h>

// REPLACE WITH YOUR RECEIVER MAC ADDRESS
uint8_t broadcastAddress[] = {0x10, 0x52, 0x1C, 0xB6, 0xD8, 0x6C};

// Structure to hold joystick data
typedef struct struct_message {
    int x;
    int y;
    int sw;
} struct_message;

struct_message myData;
esp_now_peer_info_t peerInfo;

const int pinX = 34;
const int pinY = 35;
const int pinSW = 32;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void setup() {
  Serial.begin(115200);
  pinMode(pinSW, INPUT_PULLUP);
  
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_send_cb(esp_now_send_cb_t(OnDataSent));
  
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
}

void loop() {
  // Read joystick values
  myData.x = analogRead(pinX);
  myData.y = analogRead(pinY);
  myData.sw = digitalRead(pinSW); // 0 when pressed, 1 when idle

  // Send message via ESP-NOW
  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
   
  if (result == ESP_OK) {
    Serial.printf("Sent: X=%d, Y=%d, SW=%d\n", myData.x, myData.y, myData.sw);
  }
  
  delay(50); // Small delay for stability
}