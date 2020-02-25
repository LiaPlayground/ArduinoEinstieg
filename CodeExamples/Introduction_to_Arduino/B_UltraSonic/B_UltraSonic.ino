const int trigPin = 8;
const int echoPin = 9;

float temp = 25;
const float us_speed = (331.3 + (0.606 * temp)) / 1000 / 1000 * 100;

long t;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  t = pulseIn(echoPin, HIGH);
  Serial.println(duration);
  //distance = 
  //Serial.print("Distance = ");
  //Serial.println(distance);
  //Serial.println(" cm");

  delay(50);
}


// Umrechnung Dauer [us] in Distanz [cm]
// Serial plotter
// pulseIn Documentation
