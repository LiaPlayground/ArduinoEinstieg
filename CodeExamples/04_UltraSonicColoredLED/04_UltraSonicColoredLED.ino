#include <NewPing.h>
 
#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 256 // Maximum distance we want to ping for (in centimeters).

const int redPin = 10;
const int greenPin = 9;
const int bluePin = 8;
 
void setColourRgb(unsigned int red, unsigned int green, unsigned int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

const int ledPin =  13;      // the number of the LED pin

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
// NewPing setup of pins and maximum distance.
 
void setup() {
  Serial.begin(9600); // Open serial monitor at 9600 baud to see ping results.
  setColourRgb(0,0,0);
}
 
void loop() {
  int red, green, blue;
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 
  if ((sonar.ping_cm() <= 10) && (sonar.ping_cm() > 0)){
     Serial.println("Alarm!");
     setColourRgb(255, 0, 0);
  }
  if ((sonar.ping_cm() <= 20) && (sonar.ping_cm() > 10)){
     digitalWrite(ledPin, HIGH);
     Serial.println("Nah dran!");
     setColourRgb(0, 0, 255);
  }
  if ((sonar.ping_cm() <= 30) && (sonar.ping_cm() > 20)){
     digitalWrite(ledPin, HIGH);
     Serial.println("Nah dran!");
     setColourRgb(0, 255, 0);
  }
}

