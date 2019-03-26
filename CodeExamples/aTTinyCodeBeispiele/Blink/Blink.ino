const int LED=1;

// The setup routine is executed once when you power-on the board or press the RST button later
void setup() {
  pinMode(LED, OUTPUT);    // initialize the digital pin as an output.

}

// The loop routine runs over and over again until power-off the board or interrupt occure:
void loop() {
  digitalWrite(LED, HIGH); // Set it in Low state
  delay(500);
  digitalWrite(LED, LOW); // Set it in Low state
  delay(500);
  
}
