//可変抵抗でサーボの角度変える


//サーボモーターを制御するためのライブラリ
#include<Servo.h>

//可変抵抗に接続したアナログピン
const int potentiometerPin = 0;

//任意のサーボモータークラスを用意
Servo servo;


void setup(){
  //サーボを使用するデジタルピン
  servo.attach(9); 
}

void loop(){
  //可変抵抗の値
  int value = analogRead(potentiometerPin);

  //読み取った値を0-179に変換
  int angle = map(value, 0, 1023, 0, 179);

  //サーボの角度
  servo.write(angle);
  //Serial.write(value);
  //Serial.println(value);
  Serial.println(angle);

  delay(15);

}

