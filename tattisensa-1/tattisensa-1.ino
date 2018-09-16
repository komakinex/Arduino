//抵抗に触れると、色が少しずつ足されていく

#include <Adafruit_NeoPixel.h>
#include <CapacitiveSensor.h>
#include <VarSpeedServo.h> 

VarSpeedServo myservo;//任意のクラスを用意

 
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
  myservo.attach(9);//サーボのピンを9番に接続
  
  RGBLED.begin();//RGBLEDライブラリの初期化
  RGBLED.setBrightness(100);//明るさの指定(0-255)を行う
  RGBLED.setPixelColor(0,100+c,b,c);
  RGBLED.show();
}
 
void loop()
{
  
  myservo.write(179, 10, true);//(度, 速度, 待つ)
  myservo.write(0, 10, true);//(度, 速度, 待つ)
  
  
  // タッチセンサーの値を取得する
  long sensorValue = capSensor.capacitiveSensor(30);

  // 500以上ならば
  if (sensorValue > 300)
  { 
    RGBLED.setPixelColor(0,100,b,0);
    b += 30;
    RGBLED.show();

    if(b>200)
    {
      RGBLED.setPixelColor(0,100+c,b,c);
      c += 30;
      RGBLED.show();
    }
  }
  //Serial.println(sensorValue);
  delay(200);
}
