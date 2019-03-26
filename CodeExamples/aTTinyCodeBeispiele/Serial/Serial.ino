#include "SoftwareSerial.h"

SoftwareSerial mySerial(0,2);  //rx, tx
int incommingByte;
x

void setup()
{
    mySerial.begin(19200);
    pinMode(1, OUTPUT); //LED on Model A   
    mySerial.println("Glück auf!");
}

void loop()
{
    if (mySerial.available() > 0){
      incommingByte = mySerial.read();
      if (incommingByte == 'A') digitalWrite(1, HIGH);
      if (incommingByte == 'B') digitalWrite(1, LOW);
    }
}
