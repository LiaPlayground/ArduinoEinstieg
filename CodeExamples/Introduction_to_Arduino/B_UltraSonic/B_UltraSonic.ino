#include <NewPing.h>

#define TRIGGER_PIN  16  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     15  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 30  // Maximum distance we want to ping for (in centimeters).

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
// NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec).
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result
  Serial.println("cm");          //(0 = outside set distance range)
}


// TODO: Serial Plotter
//       Add digital output
