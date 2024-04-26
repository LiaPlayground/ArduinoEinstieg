<!--

author:   Sebastian Zug & André Dietrich
email:    sebatian.zug@informatik.tu-freiberg.de & andre.dietrich@informatik.tu-freiberg.de
version:  0.0.1
language: de
narrator: Deutsch Female

-->

[![LiaScript](https://raw.githubusercontent.com/LiaScript/LiaScript/master/badges/course.svg)](https://liascript.github.io/course/?https://raw.githubusercontent.com/liaScript/ArduinoEinstieg/master/Course_02b.md#1)


# Mikrocontroller Einführung III

Prof. Dr. Sebastian Zug,
Technische Universität Bergakademie Freiberg

------------------------------

![Welcome](images/WorkingDesk.jpg "Experiments")<!-- width="80%" -->

<h2>Herzlich Willkommen!</h2>

> Die interaktive Ansicht dieses Kurses ist unter folgendem [Link](https://liascript.github.io/course/?https://raw.githubusercontent.com/liaScript/ArduinoEinstieg/master/Course_02b.md#1) verfügbar.

Der Quellcode der Materialien ist unter https://github.com/liaScript/ArduinoEinstieg/blob/master/Course_02b.md zu finden.

## Einstiegs-/Auffrischungsübung

> **Aufgabe:** Ihr Programmierer hat Ihnen einen Code geschrieben, der das *SOS* Morsesignal über die
> Led ausgibt!
>
> Probieren Sie den Code aus und erklären Sie die verwendeten Programmierkonstrukte. Hat er alles richtig gemacht?

```c
const int ledPin = 13;
const int shortDelay = 1000;
const int longDelay = 1000;

const sos char [] = "ssslllsss";

void setup() {
  // initialize digital pin ledPin as an output.
  pinMode(ledPin, OUTPUT);
}

void blink(int duration){
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(duration);              // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
}

void short(){
  blink(shortDelay);
}

void long(){
  blink(longDelay)  
}

void loop() {
  for(int i = 0; sos[i] != '\0'; ++i) {
      if sos[i] == 's' long();
      else short();
  }
}
```

## Aufgaben A

Integration einer Mehrfarben LED als Erweiterung der Ausgabe

![RGB](images/rgb-farbmodell.png "RGB [^1]")<!-- width="60%" -->   

![Diode](images/KY016.png)<!-- width="60%" -->


```c     LedDifferentColors.ino
// Methoden aus dem Lösungsvorschlag der MangoLabs
const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

void setColourRgb(unsigned int red, unsigned int green, unsigned int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

void setup() {
  // Start off with the LED off.
  setColourRgb(0,0,0);
}

void loop() {
  setColourRgb(255, 0, 0);
  delay(1000);
}
```

> **Aufgabe:** Nutzen Sie die Kodierung von aus dem vorherigen Beispiel und erweitern Sie diese um die Ansteuerung einer RGB-LED.

## Aufgabe B 

Wir wollen mit dem Arduino einen LED Ring ansteuern.

!?[](https://www.youtube.com/watch?v=_6LXKuo28M0)

```c   LedRing.ino
#include <Adafruit_NeoPixel.h>
#define PIN        6
#define NUMPIXELS 24

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500

void setup() {
  pixels.begin();
}

void loop() {
  pixels.clear();

  for(int i=0; i<NUMPIXELS; i++) {

    pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    pixels.show();
    delay(DELAYVAL);
  }
}
```

> Lassen Sie Ihrer Kreativität freien Lauf und erweitern Sie das Beispiel um eine Animation. Integrieren Sie den Distanzsensor aus einer vorangegangenen Aufgabe oder senden Sie Steuersignale über die Serielle Schnittstelle.
