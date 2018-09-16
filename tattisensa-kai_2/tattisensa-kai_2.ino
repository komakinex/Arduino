//抵抗に触れると、緑が少しずつたされていく

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

//rGBに足す値
int b = 0;
int c = 0;

//タッチセンサー
int buttonPushCounter = 0;
int buttonState = 0; //タッチセンサーの状態
int lastButtonState = 0; //前回のタッチセンサーの状態

void setup()
{
  RGBLED.begin();//RGBLEDライブラリの初期化
  RGBLED.setBrightness(100);//明るさの指定(0-255)を行う
  RGBLED.setPixelColor(0,100+c,b,c);
  RGBLED.show();
}

void loop()
{
  // タッチセンサーの値を取得する
  long touchVal = capSensor.capacitiveSensor(30);

  // 前回の状態と比較
  if( buttonState != lastButtonState)
  {
    // 状態が変化していたらカウンタを1増やす
    if (buttonState == 1) {
      // 現在の状態がなら1
      
      buttonPushCounter++; // インクリメント
//      Serial.println("on");
//      Serial.print("number of button pushes:  ");
      Serial.println(buttonPushCounter);
    } else {
//      Serial.println("off");
    }
    //現在の状態を最後の状態と差し替える
    lastButtonState = buttonState;

    if(buttonPushCounter > 2){
      buttonPushCounter = 0;
    }
  }






//
//  if(touch != true)
//  {
//    RGBLED.setPixelColor(0,100+c,b,c);
//    RGBLED.show();
//  }else{
//    RGBLED.setPixelColor(0,100,b,0);
//    b += 30;
//    RGBLED.show();
//
//    if(b>200)
//    {
//      RGBLED.setPixelColor(0,100+c,b,c);
//      c += 30;
//      RGBLED.show();
//    } 
//  }
//  Serial.println(touch);
//  delay(200);
}
