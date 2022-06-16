#include <SPI.h>
#include <SD.h>

#define echoPin 2
#define trigPin 3

long duration;
int distance;

const int chipSelect = 5;
File Textdatei;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  if (!SD.begin(5)) {
    Serial.println("Initialisierung fehlgeschlagen!");
    return;
  }
  SD.remove("us_data.txt");
  Serial.println("Initialisierung abgeschlossen");
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.println(distance);

  Textdatei = SD.open("us_data.txt", FILE_WRITE);
  if (Textdatei)
  {
    Textdatei.println(distance);
    Textdatei.close();
  }
  else
  {
    Serial.println("Textdatei konnte gefunden werden");
  }
}
