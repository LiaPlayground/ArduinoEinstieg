#include <NewPing.h>
 
#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 400 // Maximum distance we want to ping for (in centimeters).

const int ledPin =  13;      // the number of the LED pin

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
// NewPing setup of pins and maximum distance.
 
void setup() {
  Serial.begin(9600); // Open serial monitor at 9600 baud to see ping results.
  pinMode(ledPin, OUTPUT);
}
 
void loop() {
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 
  if ((sonar.ping_cm() < 10) && (sonar.ping_cm() > 0)){
     digitalWrite(ledPin, HIGH);
     Serial.println("Alarm!");
  }
  else
     digitalWrite(ledPin, LOW);
}
