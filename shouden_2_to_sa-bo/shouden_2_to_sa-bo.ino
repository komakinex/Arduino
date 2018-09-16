#include <VarSpeedServo.h> 

VarSpeedServo myservo;//任意のクラスを用意

const int PIRpin = 2;
const int LEDpin = 13;

void setup()
{
  //pinMode(LEDpin, OUTPUT);
  pinMode(PIRpin, INPUT_PULLUP);
  myservo.attach(9);//サーボのピンを9番に接続
  myservo.write(0, 30, true);//(度, 速度, 待つ)
  delay(5000);
}

void loop()
{
   if (digitalRead(PIRpin) == LOW) {
     digitalWrite(LEDpin, HIGH);
     myservo.write(180, 30, true);//(度, 速度, 待つ)
     
     Serial.println("1");
   } else {
     digitalWrite(LEDpin, LOW);
     //myservo.write(0, 30, true);//(度, 速度, 待つ)
     Serial.println("0");
   }
   delay(1000);
}
