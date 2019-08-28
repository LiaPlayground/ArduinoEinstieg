/*
  00_UART_HelloWorld

  Evaluates the capability of UART communication
*/

void setup() {
  pinMode(13, OUTPUT);          // sets the digital pin 13 as output
                                // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Hallo Week-For-Future! Nice to meet you!");
  Serial.println(10123);
}

void loop() {
}
