#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

int lcdi2c = 0x27;
LiquidCrystal_PCF8574 lcd(lcdi2c);

String names [] = {"Anja", "Alexander", 
                   "Adrian", "Alfons", 
                   "Alois", "Ariadne"};
int number = 5;

void setup()
{
  lcd.begin(16, 2);
  lcd.setBacklight(255);
}

void loop()
{
  for (int i=1; i< number; i++){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(names[i-1]);
    lcd.setCursor(0, 1);
    lcd.print(names[i]); 
    delay(1000);
   }
}
