#include <LiquidCrystal.h>
#include <NewPing.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7); 

#define TRIGGER_PIN  16  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     15  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 100  // Maximum distance we want to ping for (in centimeters).

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

float result = 0;

void showMeanDistance(){
  lcd.setCursor(0, 0);
  lcd.print("Distanz");
  lcd.setCursor(9, 0);
  lcd.print(result);
}

void readMeanDistance(){
  // Todo Messungen und Mittelwertgenerierung integrieren
  result = 12.3;
}

void setup() 
{ 
  lcd.begin(16, 2);
}

void loop()
{
  readMeanDistance();
  showMeanDistance();
  delay(50);
}
