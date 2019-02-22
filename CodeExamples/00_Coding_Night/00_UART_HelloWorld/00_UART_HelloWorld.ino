/*
  00_UART_HelloWorld

  Evaluates the capability of UART communication
*/

char incomingByte = 0;   // for incoming serial data

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 57600 bits per second:
  Serial.begin(57600);
  Serial.print("Coding night in Doberlug \n\r Nächste Zeile");
  Serial.println("Ok, dass haben wir verstanden");
  Serial.print(5);

  // Weitere Datentypen
  float floatValue = 23.3232;
  Serial.println(floatValue);
  Serial.println(floatValue * 2);
  Serial.print(1.23456, 4);

  // Recherchieren Sie die Semantik der For Schleife in
  // C und implmentieren Sie die Ausgabe von 0 bis 10
  for (int counter=0; counter < 10; counter++) {
    Serial.print(counter);
  }
  pinMode(13, OUTPUT);          // sets the digital pin 13 as output
}

// the loop routine runs over and over again forever:
void loop() {
//  if (Serial.available() > 0) {
//    incomingByte = Serial.read();
//    Serial.print("Buchstabe gelesen ");
//    Serial.write(incomingByte);
//  }

//  digitalWrite(13, HIGH);
  if (Serial.available() > 0) {
        incomingByte = Serial.read();
        Serial.write(incomingByte);
        if (incomingByte == 'A'){
          Serial.println("An");
          digitalWrite(13, HIGH);
        }
        if (incomingByte == 'B'){
          digitalWrite(13, LOW);
          Serial.println("Aus");
        }
  }
}
