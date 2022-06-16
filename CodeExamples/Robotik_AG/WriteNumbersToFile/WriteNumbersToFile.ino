#include <SPI.h>
#include <SD.h>

const int chipSelect = 5;
File Textdatei;

void setup() {
  Serial.begin(9600);

  Serial.println("Initialisiere SD-Karte");
  if (!SD.begin(5)) {
    Serial.println("Initialisierung fehlgeschlagen!");
    return;
  }
  Serial.println("Initialisierung abgeschlossen");


  // Schreiben
  SD.remove("data.txt");
  Textdatei = SD.open("data.txt", FILE_WRITE);
  if (Textdatei)
  {

    Serial.println("Schreibe in Textdatei...");
    for (int i = 0; i < 100; i++)
    {
      Textdatei.print(i);
      Textdatei.print(",");
      if (i % 10 == 0) Textdatei.println("");
    }
    Textdatei.close();
  }
  else
  {
    Serial.println("Textdatei konnte nicht ausgelesen werden");
  }

  // Lesen
  Textdatei = SD.open("data.txt");
  if (Textdatei)
  {
    Serial.println("test.txt:");
    int count = 0;
    while (Textdatei.available())
    {
      String text = Textdatei.readStringUntil('\n');
      Serial.println(text);
    }

    Textdatei.close();
  }
  else
  {
    Serial.println("Textdatei konnte nicht geoeffnet werden");
  }
}


void loop() {
}
