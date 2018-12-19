//抵抗に触れると、色が少しずつ足されていく

#include <Adafruit_NeoPixel.h>
#include <CapacitiveSensor.h>

// 4ピン : 電気エネルギーを送信します。
// 2ピン : センサーで変化を感知します。
CapacitiveSensor capSensor = CapacitiveSensor(4, 2);


// RGBLEDに出力するピン番号
#define RGBLED_OUTPIN    12
// Arduinoにぶら下がっているRGBLEDの個数
#define NUMRGBLED        6

// RGBLEDのライブラリを生成する(色指定はRGBの並びで行う、LEDの速度は800KHzとする)
Adafruit_NeoPixel RGBLED = Adafruit_NeoPixel(NUMRGBLED, RGBLED_OUTPIN, NEO_RGB + NEO_KHZ800);


int b = 0;
int c = 0;



void setup()
{
  RGBLED.begin();//RGBLEDライブラリの初期化
  RGBLED.setBrightness(75);//明るさの指定(0-255)を行う
  RGBLED.setPixelColor(0,0,102,255);
  RGBLED.setPixelColor(1,0,102,255);
  RGBLED.setPixelColor(2,0,102,255);
  RGBLED.setPixelColor(3,0,102,255);
  RGBLED.setPixelColor(4,0,102,255);
  RGBLED.setPixelColor(5,0,102,255);
  RGBLED.show();
}
 
void loop()
{
  // タッチセンサーの値を取得する
  long sensorValue = capSensor.capacitiveSensor(30);
  Serial.println(sensorValue);

  // 500以上ならば
  if (sensorValue > 500)
  { 
    RGBLED.setPixelColor(0,51,b,255);
    RGBLED.setPixelColor(1,51,b,255);
    RGBLED.setPixelColor(2,51,b,255);
    RGBLED.setPixelColor(3,51,b,255);
    RGBLED.setPixelColor(4,51,b,255);
    RGBLED.setPixelColor(5,51,b,255);
    b += 80;
    RGBLED.show();

    if(b>200)
    {
      RGBLED.setPixelColor(0,51+c,b,255+c);
      RGBLED.setPixelColor(1,51+c,b,255+c);
      RGBLED.setPixelColor(2,51+c,b,255+c);
      RGBLED.setPixelColor(3,51+c,b,255+c);
      RGBLED.setPixelColor(4,51+c,b,255+c);
      RGBLED.setPixelColor(5,51+c,b,255+c);
      
      c += 50;
      RGBLED.show();
    }
  }
  delay(200);
}
