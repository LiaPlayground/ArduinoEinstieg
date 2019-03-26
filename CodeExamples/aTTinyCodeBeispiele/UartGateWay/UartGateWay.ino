int fromFOSDEM = 0; 
int fromPC = 0;

void setup() {
        Serial.begin(19200);    
        Serial3.begin(19200);
}

void loop() {
        if (Serial3.available() > 0) {
                fromFOSDEM = Serial3.read();
                Serial.write(fromFOSDEM);
                Serial.flush();
        }
        if (Serial.available() > 0) {
                fromPC = Serial.read();
                Serial3.write(fromPC);
                Serial3.flush();
        }
}
