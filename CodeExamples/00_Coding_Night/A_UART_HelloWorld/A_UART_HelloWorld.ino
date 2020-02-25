/*
  00_UART_HelloWorld

  Evaluates the capability of UART communication
*/

byte incomingByte = 0; // for incoming serial data

void setup() {
  pinMode(13, OUTPUT);          // sets the digital pin 13 as output
                                // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Hi! Nice to meet you!");
}

void loop() {
}
