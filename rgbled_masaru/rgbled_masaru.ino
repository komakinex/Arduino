#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUMLED 1

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMLED, PIN, NEO_RGB + NEO_KHZ400);

void setup() {
  pixels.begin();
}

void loop() {
  for (int i = 0; i < 256; i++) {
    setColor( i, 0, 0);
  }

  for (int i = 0; i < 256; i++) {
    setColor( i, i, i);
  }

  for (int i = 0; i < 256; i++) {
    setColor( 0,0, i);
  }
}

void setColor(int r, int g, int b) {
  for (int i = 0 ; i < NUMLED; i++) {
    pixels.setPixelColor(i, pixels.Color(r, g, b));
    pixels.show();
  }
  delay(10);
}
