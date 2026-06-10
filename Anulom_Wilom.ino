#include<Adafruit_SSD1306.h>
#define RESET LED_BUILTIN
Adafruit_SSD1306 oled(RESET);

void setup() {
  // put your setup code here, to run once:
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  oled.setTextSize(1.5);
  oled.setTextColor(WHITE);
  oled.display();
  delay(1000);
  oled.clearDisplay();
}

void loop() {
  // put your main code here, to run repeatedly:
  oled.clearDisplay (); // clear display
  oled.setCursor (13, 0); // position the cursor
  oled.setTextSize (2); // medium size font
  oled.setTextColor (WHITE); // white is not default !
  oled.print ("PATANJALI");
  oled.setCursor (8, 23);
  oled.setTextSize (1); // smallest font
  oled.print ("ANULOM VILOM YANTRA");
  oled.display ();
  delay(2000);

}
