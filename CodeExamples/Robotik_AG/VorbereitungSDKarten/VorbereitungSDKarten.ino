#include <SPI.h>
#include <SD.h>

File Textdatei;

void setup() {

  Serial.begin(9600);

  Serial.println("Initialisiere SD-Karte");
  if (!SD.begin(5)) {
    Serial.println("Initialisierung fehlgeschlagen!");
    return;
  }
  Serial.println("Initialisierung abgeschlossen");

  SD.remove("test.txt");

  Textdatei = SD.open("test.txt", FILE_WRITE);
  if (Textdatei)
  {

    Serial.println("Schreibe in Textdatei...");
    Textdatei.println("#Robotik AG der TU Bergakademie");
    Textdatei.println("#------------------------------");
    Textdatei.println("#Toll wie schnell Du Dich eingearbeitet hast!");
    Textdatei.println("#");
    Textdatei.println("#Versuch doch diesen Text mit einzelnen Buchstaben");
    Textdatei.println("#im Sekundentakt auszugeben!");

    Textdatei.close();
    Serial.println("Abgeschlossen.");
    Serial.println();
  }
  else
  {
    Serial.println("Textdatei konnte nicht ausgelesen werden");
  }

  Textdatei = SD.open("test.txt");
  if (Textdatei)
  {
    Serial.println("test.txt:");
    int count = 0;
    while (Textdatei.available())
    { 
      //Serial.write(Textdatei.read());
      //delay(100);
      String text = Textdatei.readStringUntil('\n');
      int tubaf_position = text.indexOf("Bergakademie");
      if (tubaf_position != -1){
          Serial.print("'TUBAF' found in line ");
          Serial.print(count);
          Serial.print(" at position ");
          Serial.println(tubaf_position);
      }

      Serial.println(text);
    }

    Textdatei.close();
  }
  else
  {
    Serial.println("Textdatei konnte nicht geoeffnet werden");
  }

}

void loop()
{
}
