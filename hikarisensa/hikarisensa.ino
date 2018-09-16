int val = 0; //入力される値を格納するための変数
int ledVal = 0; //LEDに出力する値の変数

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9800); //モニターに出力するための設定
  
}


void loop() {
  // put your main code here, to run repeatedly:

  //Anarlog INの0番ピンからデータを受け取る
  val = analogRead(0);
  ledVal = val / 4; //LED出力用の値を変数に格納
  
  Serial.println(ledVal); //入力値をモニターに出力


  // 明るさを4段階に設定

  if(ledVal < 50){
    analogWrite(3, 0); // 出力が0
  }
  else if(ledVal < 100){
    analogWrite(3, 100);
  }

  else if(ledVal < 150){
    analogWrite(3, 150);
  }

  else if(ledVal < 200){
    analogWrite(3, 200);
  }
  else{
    analogWrite(3, 255); // 入力値が200以上で最大出力
  }
  
  delay(100);
  

}
