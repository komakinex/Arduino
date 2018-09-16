int FAN_SOCKET = 5;
int BUTTON1_SOCKET = 3;
int BUTTON2_SOCKET = 4;
int fan_out = 0;

void setup() {
    pinMode(FAN_SOCKET, OUTPUT);
    pinMode(BUTTON1_SOCKET, INPUT);
    pinMode(BUTTON2_SOCKET, INPUT);

    Serial.begin(9600);
}

void loop() {
    if ( digitalRead(BUTTON1_SOCKET) == HIGH ){
        if ( fan_out < 255 ) {
            fan_out = fan_out + 51;
        }
        while ( digitalRead(BUTTON1_SOCKET) == HIGH ){
            delay ( 100 );
        }
    }
    else if ( digitalRead(BUTTON2_SOCKET) == HIGH ){
        if ( fan_out > 0){
            fan_out = fan_out - 51;
        }
        while ( digitalRead(BUTTON2_SOCKET) == HIGH ){
            delay ( 100 );
        }
    }
    
    

    analogWrite( FAN_SOCKET, fan_out );
    //Serial.println(fan_out);


    Serial.write((byte)fan_out);
    
    

    
    delay (100);
}


