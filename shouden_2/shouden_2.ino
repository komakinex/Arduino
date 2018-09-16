const int PIRpin = 2;
const int LEDpin = 13;

void setup()
{
  pinMode(LEDpin, OUTPUT);
  pinMode(PIRpin, INPUT_PULLUP);  
}

void loop()
{
   if (digitalRead(PIRpin) == LOW) {
     digitalWrite(LEDpin, HIGH);
     
     Serial.println("1");
   } else {
     digitalWrite(LEDpin, LOW);
     Serial.println("0");
   }
   delay(1000);
}
