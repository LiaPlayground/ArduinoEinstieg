#define  Delay_time_ms    5
#define  Led              1  // Select the pin where the led is attached. Options: from 0 to 4

// The setup routine is executed once when you power-on the board or press the RST button later
void setup() {
  
  pinMode(Led, OUTPUT);    // initialize the digital pin as an output.
  digitalWrite(Led, LOW);  // Set it in Low state
  
}

// The loop routine runs over and over again until power-off the board or interrupt occure:
void loop() {
  
  for (int i=0; i<256; i++) {
    analogWrite(Led, i);  // PWM the LED from 0 to 255 (max)
    delay(Delay_time_ms);
  }
  for (int i=255; i>=0; i--) {
    analogWrite(Led, i);  // PWM the LED from 255 (max) to 0
    delay(Delay_time_ms);
  }
  delay(500);
  
}
