//#include <Servo.h>
#include <VarSpeedServo.h> 

VarSpeedServo myservo;//任意のクラスを用意
//Servo servo1;

void setup()
{
  myservo.attach(9);//サーボのピンを9番に接続
}

void loop()
{
 
  myservo.write(179, 20, true);//(度, 速度, 待つ)
  delay(1000);
  myservo.write(0, 20, true);//(度, 速度, 待つ)
  delay(1000);
  
}
