#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7); 
                 
void setup() 
{ 
  lcd.begin(16, 2);
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
