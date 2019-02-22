// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
 
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
 
int setup() {
  pinMode(ledPin, INPUT);
  pinMode(buttonPin, INPUT);
}
 
void loop() {
  buttonState = digitalRead(buttonPin);
 
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH)
  } else {
    digitalWrite(buttonPin, LOW);
  }
}
