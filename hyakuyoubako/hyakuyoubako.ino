
// 温度センサの値をシリアルモニターに表示

int sensorPin = A0; //アナログ０番ピンを指定
int sensorValue = 0; //

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  sensorValue = analogRead(sensorPin); //アナログ０番ピンからの入力値を取得

  float temp = modTemp(sensorValue); //温度センサからの入力値を変換

  Serial.println(temp);
  delay(500);

}


// アナログ入力値を摂氏に変換

float modTemp(int analog_val){
  float v = 5; //基準電圧
  float tempC = ((v * analog_val) / 1024) * 100; // 摂氏に変換

  return tempC;
}

