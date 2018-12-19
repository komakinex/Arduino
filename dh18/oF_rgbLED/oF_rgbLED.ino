int redPin = A0;
int greenPin = A1;
int bluePin = A2;

int colorR = 0;
int colorG = 0;
int colorB = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}
void loop() {
  if (Serial.available()) {
      unsigned char command = Serial.read();
      unsigned char value = Serial.read();
      if ('R' == command) {
        colorR = value;
      }else if ('G' == command) {
        colorG = value;
      }else if ('B' == command) {
        colorB = value;
      }else {}
  }
  
  analogWrite(redPin, colorR);
  analogWrite(greenPin, colorG);
  analogWrite(bluePin, colorB);
}
