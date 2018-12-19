int adcPin = A0; // select the input pin for the potentiometer
int adcIn = 0;   // variable to store the value coming from the sensor
void setup()
{
    Serial.begin(9600); // init serial to 9600b/s
    Serial.println("Sliding Potentiometer Test Code!!");
}
void loop()
{
    // read the value from the sensor:
    adcIn = analogRead(adcPin);//0-1023までの値が出てくる

    //serialByteは0-255までしか送れないので分解する必要がある
    //前後の\x80とかは、データを分割している印なのでなんでも良い
    Serial.write('\x80');

    //ここで分解している
    Serial.write(0x00FF & (adcIn >> 8));
    Serial.write(0x00FF&adcIn);
    
    Serial.write('\x81');
    
    delay(100);
}
