/*
  00_UART_HelloWorld

  Evaluates the capability of UART communication
*/

char incomingByte = 0;   // for incoming serial data

void setup() {
  Serial.begin(9600);
  Serial.println("Geben Sie ein Zeichen ein und danach [Enter]");
  pinMode(13, OUTPUT);          // sets the digital pin 13 as output
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    Serial.print("Buchstabe gelesen ");
    Serial.write(incomingByte);
    Serial.println();
  }

  digitalWrite(13, HIGH);
}
