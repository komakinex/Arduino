
void setup() {
  // put your setup code here, to run once:

  pinMode(3, OUTPUT); //デジタル13pinを使用
  pinMode(6, OUTPUT); //デジタル13pinを使用
  pinMode(9, OUTPUT); //デジタル13pinを使用
  pinMode(12, OUTPUT); //デジタル13pinを使用

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(3, HIGH); //デジタル13pinの出力をON
  digitalWrite(6, LOW); //デジタル13pinの出力をOFF
  digitalWrite(9, LOW); //デジタル13pinの出力をOFF
  digitalWrite(12, LOW); //デジタル13pinの出力をOFF
  delay(1000); //1秒待つ

  digitalWrite(3, LOW); //デジタル13pinの出力をON
  digitalWrite(6, HIGH); //デジタル13pinの出力をOFF
  digitalWrite(9, LOW); //デジタル13pinの出力をOFF
  digitalWrite(12, LOW); //デジタル13pinの出力をOFF
  delay(1000); //1秒待つ


  digitalWrite(3, LOW); //デジタル13pinの出力をON
  digitalWrite(6, LOW); //デジタル13pinの出力をOFF
  digitalWrite(9, HIGH); //デジタル13pinの出力をOFF
  digitalWrite(12, LOW); //デジタル13pinの出力をOFF
  delay(1000); //1秒待つ

  digitalWrite(3, LOW); //デジタル13pinの出力をON
  digitalWrite(6, LOW); //デジタル13pinの出力をOFF
  digitalWrite(9, LOW); //デジタル13pinの出力をOFF
  digitalWrite(12, HIGH); //デジタル13pinの出力をOFF
  delay(1000); //1秒待つ

 

}
