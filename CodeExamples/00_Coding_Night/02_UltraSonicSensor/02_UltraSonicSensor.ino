#define TRIGGER_PIN  6  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     7  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 400 // Maximum distance we want to ping for (in centimeters).

const int ledPin =  13;      // the number of the LED pin

unsigned long getDuration(int tPin,int ePin){
  digitalWrite(tPin, LOW);  // Reset the trigger pin.
  delayMicroseconds(2); 
  digitalWrite(tPin, HIGH);  // Start a measurement.
  delayMicroseconds(10); // 
  digitalWrite(tPin, LOW);   // Complete the pulse.
  return pulseIn(ePin, HIGH);  // Wait for a reflection pulse.
}

void setup() {
  Serial.begin(9600); // Open serial monitor at 9600 baud to see ping results.
  pinMode(ledPin, OUTPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.println("Los gehts!");
}
 
void loop() {
  long duration = getDuration(TRIGGER_PIN, ECHO_PIN);
  Serial.print((float)duration/2,2);
  Serial.print(" ");
  Serial.println((float)duration/2/29.3,2);
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 
}
