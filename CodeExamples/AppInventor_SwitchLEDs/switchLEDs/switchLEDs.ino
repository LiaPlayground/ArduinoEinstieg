#include <SoftwareSerial.h>

char Incoming_value = 0;

const byte rxPin = 2;
const byte txPin = 3;
const byte yellowLedPin = 5;
const byte redLedPin = 11;

// Set up a new SoftwareSerial object
SoftwareSerial mySerial (rxPin, txPin);

void setup()
{
  mySerial.begin(9600);   
  Serial.begin(9600);
  Serial.println("Los gehts");     
  pinMode(yellowLedPin, OUTPUT);  
  pinMode(redLedPin, OUTPUT);     
}

void loop()
{
  if(mySerial.available() > 0)  
  {
    Incoming_value = mySerial.read();     
    Serial.println(Incoming_value);     
    if(Incoming_value == 'Y')             
      digitalWrite(yellowLedPin, HIGH);  
    if(Incoming_value == 'y')       
      digitalWrite(yellowLedPin, LOW);   
    if(Incoming_value == 'R')             
      digitalWrite(redLedPin, HIGH);  
    if(Incoming_value == 'r')       
      digitalWrite(redLedPin, LOW);   
  }                            
}
