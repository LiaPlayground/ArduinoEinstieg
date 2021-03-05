#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 13, 9, 4, 5, 6, 7); // diese Pins werden benutzt

void setup()
{
  lcd.clear();        // LCD löschen
  lcd.begin(16, 2);   // verfügbare Spalten und Zeilen
  lcd.setCursor(0,0); // 0. Spalte (= ganz links) und 0. Zeile (= oben)
  lcd.print("Hello World!");
  lcd.setCursor(0,1);
  lcd.print("TU Freiberg");
}

void loop()
{
  // Hier passiert nichts
}

// ToDo: Cursor aktivieren  lcd.blink();
//       Schreiben auf nächster Zeile, einzelnes Zeichen
//       scrollDisplayLeft()
//  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
//    lcd.scrollDisplayLeft();
    // wait a bit:
//    delay(150);
//  } 
