#include <Adafruit_NeoPixel.h>

// RGBLEDに出力するピン番号
#define RGBLED_OUTPIN    2
// Arduinoにぶら下がっているRGBLEDの個数
#define NUMRGBLED 2


int b = 0;
int c = 0;

// RGBLEDのライブラリを生成する(色指定はRGBの並びで行う、LEDの速度は800KHzとする)
Adafruit_NeoPixel RGBLED = Adafruit_NeoPixel(NUMRGBLED, RGBLED_OUTPIN, NEO_RGB + NEO_KHZ800);

void setup()
{
     RGBLED.begin() ;                   // RGBLEDのライブラリを初期化する
     RGBLED.setBrightness(50) ;         // 明るさの指定(0-255)を行う
     RGBLED.setPixelColor(0, 0, 0, 0) ; // 適度に明るい緑の色。(R=0,G=150,B=0)
     //RGBLED.setPixelColor(1, 0,0,250) ;
     RGBLED.show() ;                    // LEDにデータを送り出す
}
void loop()
{
      
    RGBLED.setPixelColor(0,100,b,0);
    RGBLED.setPixelColor(1,100,b,0);
    b += 30;
    RGBLED.show();

    if(b>200)
    {
      RGBLED.setPixelColor(0,100+c,b,c);
      RGBLED.setPixelColor(1,100+c,b,c);
      c += 30;
      RGBLED.show();
    }
    delay(1000);
}
