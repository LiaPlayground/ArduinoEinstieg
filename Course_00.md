<!--

author:   Sebastian Zug & André Dietrich
email:    zug@ovgu.de   & andre.dietrich@ovgu.de
version:  0.0.4
language: de
narrator: Deutsch Female

link:     https://cdnjs.cloudflare.com/ajax/libs/animate.css/3.7.0/animate.min.css

import: https://raw.githubusercontent.com/LiaTemplates/Rextester/master/README.md
        https://raw.githubusercontent.com/LiaTemplates/WebDev/master/README.md
        https://github.com/LiaTemplates/AVR8js/main/README.md#10
        https://raw.githubusercontent.com/LiaTemplates/NetSwarm-Simulator/master/README.md
-->

[![LiaScript](https://raw.githubusercontent.com/LiaScript/LiaScript/master/badges/course.svg)](https://liascript.github.io/course/?https://raw.githubusercontent.com/liaScript/ArduinoEinstieg/master/Course_00.md#1)


# Mikrocontroller Einführung

**Eingebette Systeme**

Prof. Dr. Sebastian Zug,
Technische Universität Bergakademie Freiberg

------------------------------

![Welcome](images/WorkingDesk.jpg "Experiments")<!-- width="80%" -->

<h2>Herzlich Willkommen!</h2>

> Die interaktive Ansicht dieses Kurses ist unter folgendem [Link](https://liascript.github.io/course/?https://raw.githubusercontent.com/liaScript/ArduinoEinstieg/master/Course_00.md#1) verfügbar.

Der Quellcode der Materialien ist unter https://github.com/liaScript/ArduinoEinstieg/blob/master/Course_00.md zu finden.

## Kennenlernen

> Wer bin ich?

![Husky](images/Husky_on_tour.png "Autonomer Roboter der Arbeitsgruppe")

![Husky](images/Schwimmroboter.png "TUBAF Schwimmroboter mit Windmessungsaufsatz")

> Wer sind Sie? Was erwarten Sie vom heutigen Tutorial?

## Einführung

![Welcome](images/PassatMitInnenleben.png "Motivation")<!-- width="50%" -->

**Was heißt das eigentlich "Eingebettetes System"?**

                              {{1-2}}
*******************************************************************************
> _... ein elektronischer Rechner ..., der in einen technischen Kontext_
> _eingebunden ist. Dabei übernimmt der (Kleinst-)Rechner entweder_
> _Überwachungs-, Steuerungs- oder Regelfunktionen ... weitestgehend unsichtbar_
> _für den Benutzer .. \[nach Wikipedia "Eingebettete Systeme"\]._
*******************************************************************************

**Wie programmiere ich einen Mikrocontroller?**

                              {{2-3}}
*******************************************************************************
> _Compiler wird eine Software genannt, die einen in einer Programmiersprache_
> _geschrieben Quellcode so übersetzt, dass sie von Maschinen verstanden_
> _werden können._
*******************************************************************************

**Was ist das Arduino Projekt?**

                                 {{3}}
*******************************************************************************
> _Arduino ist eine aus Soft- und Hardware bestehende_
> _Physical-Computing-Plattform. Beide Komponenten sind im Sinne von Open_
> _Source quelloffen. Die Hardware besteht aus einem einfachen E/A-Board mit_
> _einem Mikrocontroller und analogen und digitalen Ein- und Ausgängen._

  https://www.arduino.cc/

![Arduino Hardwarefamilie](images/ArduinoGallery.jpg "ArduinoFamilie [^3]")

*******************************************************************************

[^3]: aus entsprechendem Artikel "Spiegel Online" http://www.spiegel.de/netzwelt/gadgets/arduino-erklaert-das-kann-der-microcontroller-a-1105328.html

## 2. Arduino Programmierung

Arduino nutzt eine C/C++ Semantik für die Programmierung, die folgende
Grundelemente bedient

+ Alle Anweisungen enden mit einem `;`
+ Variabeln sind typbehaftet (`int`, `char`, `float`, etc.)
+ wichtige Schlüsselwörter sind `for`, `if`, `while`, etc.
+ Kommentare werden durch `//` eingeleitet

![Cheat-Sheet](images/Arduino-Cheat-Sheet_v0.1.png "Cheat-Sheet")

### 2.1 Aufbau eines Arduino-Programmes



Jedes Arduinoprogramm umfasst 2 grundlegende Funktionen `setup()` und `loop()`.

<div>
  <wokwi-led color="red" pin="13" port="B" label="13"></wokwi-led>
  <span id="simulation-time"></span>
</div>
```cpp       arduino.cpp
const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);  
  delay(1000);                
  digitalWrite(ledPin, LOW);
  delay(1000);  
}
```
@AVR8js.sketch

### 2.2 Arduino IDE



![Bildtext](images/ArduinoIDE_Screenshot.jpg "Arduino IDE")

Wichtige Grundeinstellungen:

+ Richtigen Port für den Programmiervorgang auswählen (Tools -> Port)
+ Richtigen Controller auswählen (Tools -> Board)
+ Richtige Baudrate für die Serielle Schnittstellen

### 2.3 Hello World



*Und jetzt sind Sie dran!*

Laden Sie das Beispielprogramm "Blink" in Ihren Editor:

Datei -> Beispiele -> Basics -> Blink

Kompilieren und flashen Sie das Programm! Wichtige Tastaturbefehle sind dabei

| Tastenkombination | Bedeutung                |
| ----------------- | ------------------------ |
| Strg-R            | Kompilieren (Ve**R**ify) |
| Strg-U            | Flashend (**U**pload)    |
| Strg-T            | Code korrekt einrücken   |
| Strg-Shift-M      | Seriellen Monitor öffnen |
| Strg-L            | Cursor auf Zeile setzen  |

### 2.4 C++ Basiskonstrukte und die Serielle Schnittstelle



                              {{0-1}}
*******************************************************************************

Was fehlt? Ich möchte irgendwie in den Rechner schauen können :-)

Die Serielle Schnittstelle (häufig auch als UART) bezeichnet ermöglicht das
Versenden und den Empfang von Textnachrichten. Damit können Sie zum Beispiel
Messwerte ausgeben oder das Erreichen bestimmter Programmpositionen anzeigen.

Die folgenden Beispiele vermitteln grundlegende Programmierkonstrukte in C++.
Diese können in der Simulation ausgeführt werden.  

<div>
  <span id="simulation-time"></span>
</div>
```cpp       arduino.cpp
void setup() {
  Serial.begin(9600);
  Serial.println("Hello World");
}

void loop() {
}
```
@AVR8js.sketch


Arduino kennt zwei Varianten der Ausgabe mit `print` - das einfache `print` und `println`. Welchen Unterschied vermuten Sie?

*******************************************************************************

                              {{1-2}}
*******************************************************************************

**Schleifen**

Was müssen wir tuen, um die Zahlen von 1 bis 10 auf dem Terminal anzuzeigen?

<div>
  <span id="simulation-time"></span>
</div>
```cpp       arduino.cpp
void setup() {
  Serial.begin(9600);
  int counter = 0;
  for (int i = 0; i < 10; i++){
    Serial.println(counter);  
    counter = counter + 1;
  }
}

void loop() {
}
```
@AVR8js.sketch

Welche "Einsparmöglichkeiten" sehen Sie als erfahrener Programmierer in dem Beispiel? Wie kann der Code, mit der gleichen Ausgabe kürzer gestaltet werden?

*******************************************************************************

                              {{2-3}}
*******************************************************************************

**Verzweigungen**

Verzweigungen folgen dem Muster

```c
if (Bedingung) {
  // Anweisungen
}
else{               
  // Anweisungen       
}                      
```

wobei der `else` Abschnitt optional ist.

<div>
  <span id="simulation-time"></span>
</div>
```cpp       arduino.cpp
void setup() {
  Serial.begin(9600);
  float value = 5.234;
  Serial.print(value);
  if (value > 10){
    Serial.println(" - Der Wert ist größer als 10!");
  }else{
    Serial.println(" - Der Wert ist kleiner als 10!");
  }
}

void loop() {
}
```
@AVR8js.sketch


*******************************************************************************


                              {{3-4}}
*******************************************************************************

Bedingungen werden dabei wie folgt formuliert:

<div>
  <span id="simulation-time"></span>
</div>
```c      ardunino.cpp
void setup() {
  Serial.begin(9600);
  int a = 2;
  if (a == 2) {Serial.println("a ist gleich zwei!");}
  if (a <= 5) {Serial.println("a ist kleiner oder gleich fünf!");}
  if (a != 3) {Serial.println("a ist ungleich drei!");}
  char b = 'g';
  if (b == 'z') {Serial.println("In b ist ein z gespeichert!");}
  else {Serial.println("In b ist kein z gespeichert!");}
}

void loop() {
}
```
@AVR8js.sketch

Für die Ausgabe von komplexeren, vorformatierten Ausdrücken können Sie auf einen
Befehl aus der C++ Standard-Bibliothek zurückgreifen `sprintf`

Eine anschauliche Dokumentation findet sich unter: [link](https://arduinobasics.blogspot.com/2019/05/sprintf-function.html)

*******************************************************************************

## 3. Einstiegsübung

> **Aufgabe 1:** Schreiben Sie einen Code, der das *SOS* Morsesignal über die
> Led ausgibt!

Welche Anpassungen sind dafür an unserem Beispiel vornehmen?

```c
const int ledPin = 13;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin ledPin as an output.
  pinMode(ledPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                  // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                  // wait for a second
}
```

## 4. Aufgabenkomplexe


![MangoLabsSet](images/MangoLabsSet.jpg "MangoLabsSet")<!-- width="80%" -->

* Referenzübersicht Arduino

  + deutsch (unvollständig) https://www.arduino.cc/reference/de/
  + englisch https://www.arduino.cc/reference/en/


### 4a. Serielle Schnittstelle als Eingabe


Die Arbeit mit der seriellen Schnittstelle vom Arduino zum PC kennen Sie bereits. Aber das Ganze funktioniert auch umgekehrt.

<div>
  <span id="simulation-time"></span>
</div>
```c      ardunino.cpp
char incomingByte;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
        incomingByte = Serial.read();
        Serial.write(incomingByte);
        if (incomingByte == 'A'){
          Serial.println("A gelesen");
        }
    }
}
```
@AVR8js.sketch

> **Aufgabe:** Erweitern Sie den Code, so dass wir die LED über 'A' an- und
> 'B' ausschalten können. Dazu "mischen" Sie den Code aus dieser und der vorangegangen Aufgabe.

### 4b. Taster als Erweiterung

*Langweilig ... ! Das ist doch kein echtes eingebettetes System!*

![BildSchalterlogik](images/Microswitch_bb.png)<!-- width="60%" -->

```c               ActivateLed.ino
const int buttonPin = 2;     // Pin des Buttons
const int ledPin =  13;      // Pin der LED

// variables will change:
int buttonState = 0;         // Variable für die Speicherung

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
```

> **Aufgabe:** Der Taster schaltet die LED ein und nach 3 Sekunden geht sie von
> selbst wieder aus.

### 4c. Distanzsensor als Input

*Langweilig ... ! Wir wollen einen echten Sensor!*

> **Aufgabe:** Schalten Sie die LED mittels Ultraschallsensor an und aus
> (distanzabhäniger Lichtschalter)

Verbinden Sie den Ultraschallsensor mit Ihrem Board entsprechend dieser Belegung:

<!-- data-type="none" -->
| Sensor IO | Pin am Board |
| --------- | ------------ |
| VCC       | 5V           |
| GND       | GND          |
| Echo      | 11           |
| Trigger   | 12           |


ACHTUNG: Sie müssen für die Integration des Sensors noch die Bibliothek
`NewPing` installieren. Finden Sie dafür allein einen Weg? Recherchieren sie in
den Arduino Foren zur Frage "How to install a library for Arduino?"

```c               Sonar.ino
// Loesung
#include <NewPing.h>

const int triggerPin = 12;   
const int echoPin = 11;     
const int maxDistance = 400;
const int ledPin =  13;

NewPing sonar(triggerPin, echoPin, maxDistance);

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  delay(50);
  Serial.println(sonar.ping_cm());
}
```

Erweitern Sie das Programm so, dass eine Aktivierung der LED erfolgt, wenn ein Hindernis näher als 10cm kommt.

### 4d. Es wird bunt

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

> **Aufgabe:** Wechseln Sie die Farben der LED in Abhängigkeit von der Entfernung

[^1] https://www.informatikzentrale.de/rgb-farbmodell.html
[^2]: https://arduinomodules.info/ky-016-rgb-full-color-led-module/
