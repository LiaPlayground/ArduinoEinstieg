#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

int lcdi2c = 0x27;
LiquidCrystal_PCF8574 lcd(lcdi2c);

const int trigPin = 8;
const int echoPin = 9;
float temp = 25;
const float us_speed = (331.3 + (0.606 * temp)) / 1000 / 1000 * 100;

float distance;

void showMeanDistance(){
  lcd.setCursor(0, 0);
  lcd.print("Distanz ");
  lcd.print(distance, 2);
  // Todo Positionskorrektur
  lcd.setCursor(0, 1);
  lcd.print("Temperatur ");
  lcd.print(temp, 0);
}

void readMeanDistance(){
  long duration = 0;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * us_speed / 2;
  // Todo Mittelwertbildung
}

void setup()
{
  lcd.begin(16, 2);
  lcd.setBacklight(10);
  lcd.clear();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  readMeanDistance();
  showMeanDistance();
  delay(50);
}
