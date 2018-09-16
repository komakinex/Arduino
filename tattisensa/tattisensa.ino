//抵抗に触れると、色が少しずつ足されていく

#include <Adafruit_NeoPixel.h>
#include <CapacitiveSensor.h>
 
// 4ピン : 電気エネルギーを送信します。
// 2ピン : センサーで変化を感知します。
CapacitiveSensor capSensor = CapacitiveSensor(6, 4);


// RGBLEDに出力するピン番号
#define RGBLED_OUTPIN    12
// Arduinoにぶら下がっているRGBLEDの個数
#define NUMRGBLED        6

// RGBLEDのライブラリを生成する(色指定はRGBの並びで行う、LEDの速度は800KHzとする)
Adafruit_NeoPixel RGBLED = Adafruit_NeoPixel(NUMRGBLED, RGBLED_OUTPIN, NEO_RGB + NEO_KHZ800);


int b = 0;
int c = 0;

boolean touch = false;



void setup()
{
  RGBLED.begin();//RGBLEDライブラリの初期化
  RGBLED.setBrightness(255);//明るさの指定(0-255)を行う
  RGBLED.setPixelColor(0,100+c,b,c);
  RGBLED.setPixelColor(1,100+c,b,c);
  RGBLED.setPixelColor(2,100+c,b,c);
  RGBLED.setPixelColor(3,100+c,b,c);
  RGBLED.setPixelColor(4,100+c,b,c);
  RGBLED.setPixelColor(5,100+c,b,c);
  RGBLED.show();
}
 
void loop()
{
  // タッチセンサーの値を取得する
  long sensorValue = capSensor.capacitiveSensor(30);

  // 500以上ならば
  if (sensorValue > 500)
  { 
    RGBLED.setPixelColor(0,100,b,0);
    RGBLED.setPixelColor(1,100,b,0);
    RGBLED.setPixelColor(2,100,b,0);
    RGBLED.setPixelColor(3,100,b,0);
    RGBLED.setPixelColor(4,100,b,0);
    RGBLED.setPixelColor(5,100,b,0);
    b += 30;
    RGBLED.show();

    if(b>200)
    {
      RGBLED.setPixelColor(0,100+c,b,c);
  RGBLED.setPixelColor(1,100+c,b,c);
  RGBLED.setPixelColor(2,100+c,b,c);
  RGBLED.setPixelColor(3,100+c,b,c);
  RGBLED.setPixelColor(4,100+c,b,c);
  RGBLED.setPixelColor(5,100+c,b,c);
      
      c += 30;
      RGBLED.show();
    }
  }
  Serial.println(sensorValue);
  delay(200);
}
