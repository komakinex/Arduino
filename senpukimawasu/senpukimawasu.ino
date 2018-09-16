int fan_out = 100;



void setup() {
    Serial.begin(9600);   // 通信速度を9600bpsに
    pinMode(5, OUTPUT);   // 扇風機制御用ソケットを出力に設定します
    pinMode(3, INPUT);   // タクトスイッチのソケットを入力に設定します
    pinMode(4, INPUT);   // タクトスイッチのソケットを入力に設定します
}
void loop() { 
    if (digitalRead(3) == HIGH) {   // PD2に接続されたタクトスイッチが押されているか確認します
        if (fan_out >= 255) {
            fan_out = fan_out + 5;   // fan_outが255より小さい場合は値を5増やします
        }
        while (digitalRead(3) == HIGH) {    // タクトスイッチが離されるまで待機します
            delay(100);
        }
    } else if (digitalRead(4) == HIGH) {   // PD3に接続されたタクトスイッチが押されているか確認します
        if (fan_out > 0) {
            fan_out = fan_out - 5;   // fan_outが0より大きい場合は値を5減らします
        }
        while (digitalRead(4) == HIGH) {   // タクトスイッチが離されるまで待機します
            delay(100);
        }
    }
    analogWrite(3, fan_out);   // 扇風機の制御用ソケットにPWMで値を出力します
    Serial.println(fan_out);   // 値を送信
    delay(100);
}
