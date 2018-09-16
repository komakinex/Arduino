const int LED = 13;
const int sensor = 2;


void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(sensor, INPUT);
}

void loop()
{
  //2ピンのお知らせを読んで、HIGHかLOWを入れておく
  int sensorState = digitalRead(sensor);

  //もしHIGHなら
  if(sensorState == HIGH)
  {
    digitalWrite(LED, HIGH);//LEDがひか～る
    delay(1000);
    
    digitalWrite(LED, LOW);//LEDがきえる！
    delay(1000);//消えたまま１秒キープ！

    Serial.println("1"); 
  }
  //LOWなら
  else
  {
    digitalWrite(LED, LOW);//LEDはきえる！
    Serial.println("0");
  }

}
