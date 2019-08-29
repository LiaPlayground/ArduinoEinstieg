#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

int state = 0; // 0 Temperatur Anzeige 
               // 1 Feuchtigkeit 
               // 2 Beleuchtung 

const int xPin = A1;

int temperatur = 99;
int humdity = 25;
int sensorValue = 10;
int xvalue = 10;

int lcdi2c = 0x27;
LiquidCrystal_PCF8574 lcd(lcdi2c);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setBacklight(255);
  lcd.clear();
}

void loop() {
   xvalue = analogRead (xPin);

  if (xvalue > 800) {state = state + 1;}
  if (state > 2) {state = 2;}
  if (xvalue < 200) {state = state - 1;}
  if (state < 0) {state = 0;}

  Serial.println(state);
  
  if (state == 0) {
    lcd.print("Temperatur");
    lcd.setCursor(0,1);  
    lcd.print(temperatur);
  }

  if (state == 1) {
    lcd.print("Feuchtigkeit");
    lcd.setCursor(0,1);  
    lcd.print(humdity);
 }

  if (state == 2) {
    lcd.print("Beleuchtung");
    lcd.setCursor(0,1);  
    lcd.print(sensorValue);  
    
  }

  delay(2000);
  
}
