#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

int lcdi2c = 0x27;

LiquidCrystal_PCF8574 lcd(lcdi2c);  // autoset the LCD address

void setup()
{
  lcd.begin(16, 2);
  lcd.setBacklight(100);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Hello World");
}

void loop()
{

}

// ToDo: Cursor aktivieren
//       Schreiben auf nächster Zeile, einzelnes Zeichen
//       scrollDisplayLeft()
