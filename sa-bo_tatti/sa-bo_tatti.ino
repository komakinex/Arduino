//サーボ+タッチセンサー

#include<Servo.h>
#include <Adafruit_NeoPixel.h>
#include <CapacitiveSensor.h>

//可変抵抗に接続したアナログピンA0
const int potentiometerPin = 0;

//任意のサーボモータークラスを用意
Servo servo;



//4ピン : 電気エネルギーを送信します。
//2ピン : センサーで変化を感知します。
CapacitiveSensor capSensor = CapacitiveSensor(4, 2);

// RGBLEDに出力するピン番号
#define RGBLED_OUTPIN    8
// Arduinoにぶら下がっているRGBLEDの個数
#define NUMRGBLED        1

// RGBLEDのライブラリを生成する(色指定はRGBの並びで行う、LEDの速度は800KHzとする)
Adafruit_NeoPixel RGBLED = Adafruit_NeoPixel(NUMRGBLED, RGBLED_OUTPIN, NEO_RGB + NEO_KHZ800);


int b = 0;
int c = 0;


void setup(){
  //サーボを使用するデジタルピン
  servo.attach(10);

  //RGBLED
  RGBLED.begin();//RGBLEDライブラリの初期化
  RGBLED.setBrightness(100);//明るさの指定(0-255)を行う
  RGBLED.setPixelColor(0,100+c,b,c);
  RGBLED.show();
}

void loop(){
  //可変抵抗の値
  int value = analogRead(potentiometerPin);

  //読み取った値を0-179に変換
  int angle = map(value, 0, 1023, 0, 179);

  //サーボの角度
  servo.write(angle);


  // タッチセンサーの値を取得する
  long sensorValue = capSensor.capacitiveSensor(30);

  // 500以上ならば
  if (sensorValue > 500)
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
  Serial.println(angle);
  delay(200);


}

