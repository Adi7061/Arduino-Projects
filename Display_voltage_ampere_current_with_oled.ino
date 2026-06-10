#define VT_PIN A1 
//#define AT_PIN A1

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1    // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);



  
void setup()
{
  Serial.begin(9600);
  pinMode(A1, INPUT);
  // Initialize with the I2C addr 0x3C (for the 128x64)
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
  //display.setCursor;

  display.display();
  delay(2000); // Pause for 2 seconds*/

  
  
}
void loop()
{
  int vt_read = analogRead(VT_PIN);
  //int at_read = analogRead(AT_PIN);
delay(0);
  float voltage = vt_read * (5.0 / 1024.0) * 5.0;
  /*float current = at_read * (5.0 / 1024.0) * 2;
  float watts = voltage * current;
  float currentini = 0;
float currentadd = currentini + current;*/


delay(500);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(25, 10);
  display.println("Voltage");
  display.setCursor(35, 40);
  display.println(voltage);
  display.setCursor(90, 40);
  display.println("V");
  /*display.setCursor(0, 30);
  display.println("Current");
  display.setCursor(50, 30);
  display.println(current);
  display.setCursor(75, 30);
  display.println("mA");
  display.setCursor(0, 40);
  display.println("Wattage");
  display.setCursor(50, 40);
  display.println(watts);
  display.setCursor(75, 40);
  display.println("mWh");*/
  
  display.display();
}