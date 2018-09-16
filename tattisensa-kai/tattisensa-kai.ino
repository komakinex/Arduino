//抵抗に触れると、緑が少しずつたされていく
//触ってる間中色が変わり続けてしまう
//ので判定をつけてみたけどうまくいかず

#include <Adafruit_NeoPixel.h>
#include <CapacitiveSensor.h>
 
// 4ピン : 電気エネルギーを送信します。
// 2ピン : センサーで変化を感知します。
CapacitiveSensor capSensor = CapacitiveSensor(4, 2);


// RGBLEDに出力するピン番号
#define RGBLED_OUTPIN    8
// Arduinoにぶら下がっているRGBLEDの個数
#define NUMRGBLED        5

// RGBLEDのライブラリを生成する(色指定はRGBの並びで行う、LEDの速度は800KHzとする)
Adafruit_NeoPixel RGBLED = Adafruit_NeoPixel(NUMRGBLED, RGBLED_OUTPIN, NEO_RGB + NEO_KHZ800);


int b = 0;
int c = 0;

void setup() {
  RGBLED.begin();//RGBLEDライブラリの初期化
  RGBLED.setBrightness(100);//明るさの指定(0-255)を行う
  RGBLED.setPixelColor(0,100+c,b,c);
  RGBLED.show();
}
 
void loop(){
  // タッチセンサーの値を取得する
  long sensorValue = capSensor.capacitiveSensor(30);

  boolean touch = false;

  // 500以上ならば
  if (sensorValue > 500)
  {
    touch = true;
  } else if(sensorValue <= 500)
  {
    touch = false;
  }

  if(touch != true)
  {
    RGBLED.setPixelColor(0,100+c,b,c);
    RGBLED.show();
  }else{
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
  Serial.println(touch);
  delay(200);
}
