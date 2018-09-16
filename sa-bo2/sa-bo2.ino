//サーボモーターを制御するためのライブラリをインクルード
#include<Servo.h>
 
Servo servo1; //任意のサーボモータークラスを用意。
 
void setup(void){  
  servo1.attach(4); //デジタル4番ピンをサーボモーターの出力ピンとして設定
}
 
void loop(void){
  //定義したモーターに回転角度となる引数を入れる。
  servo1.write(179);
  delay(3000);
 
  servo1.write(0);
  delay(3000);
 
}

