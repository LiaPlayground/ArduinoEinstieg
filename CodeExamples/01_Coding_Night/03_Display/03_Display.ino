#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

int lcdi2c = 0x27;

void setup()
{
  LiquidCrystal_PCF8574 lcd(lcdi2c); 
 
  lcd.begin(16, 2); 
  lcd.setBacklight(255);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Gymnasium Doki");
  lcd.setCursor(0, 1);
  lcd.print("2. Coding Night");
} 
 
void loop()
{

} 
