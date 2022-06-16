const int ledPin = 13;

void setup() {
  Serial.begin(9600);
  Serial.println("Zerlege das Befehlswort:");
  pinMode(ledPin, OUTPUT);
  
  String SteeringCommand_1 = "7, 12";
  //string SteeringCommand_1 = "-5, 12";
  Serial.println(SteeringCommand_1);
  int Comma_position = SteeringCommand_1.indexOf(",");
  String speed = SteeringCommand_1.substring(0, Comma_position);
  Serial.println(speed);
  if (speed.toFloat() < 0) digitalWrite(ledPin, HIGH);  
}

void loop() {
}
