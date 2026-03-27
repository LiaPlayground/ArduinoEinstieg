<!--

author:   Sebastian Zug & André Dietrich
email:    sebatian.zug@informatik.tu-freiberg.de & andre.dietrich@informatik.tu-freiberg.de
import:   https://github.com/LiaTemplates/AVR8js/main/README.md#10
          https://raw.githubusercontent.com/liaScript/mermaid_template/master/README.md
          https://raw.githubusercontent.com/LiaTemplates/Tikz-Jax/main/README.md
version:  0.0.1
language: de
narrator: Deutsch Female

-->

[![LiaScript](https://raw.githubusercontent.com/LiaScript/LiaScript/master/badges/course.svg)](https://liascript.github.io/course/?https://raw.githubusercontent.com/liaScript/ArduinoEinstieg/master/Course_06.md#1)


# Exkurs: Wall Plotter

Prof. Dr. Sebastian Zug,
Technische Universität Bergakademie Freiberg

------------------------------

![Welcome](images/WorkingDesk.jpg "Experiments")<!-- width="80%" -->

<h2>Herzlich Willkommen!</h2>

> Die interaktive Ansicht dieses Kurses ist unter folgendem [Link](https://liascript.github.io/course/?https://raw.githubusercontent.com/liaScript/ArduinoEinstieg/master/Course_06.md#1) verfügbar.

Der Quellcode der Materialien ist unter https://github.com/liaScript/ArduinoEinstieg/blob/master/Course_06.md zu finden.

## Was ist ein Wall Plotter?

{{0-1}}
!?[Beispielvideo](https://www.youtube.com/watch?v=byBueGMv4J8 "Wall Plotter in Aktion")

            {{1-2}}
*****************************************************************

Ein Wall Plotter (auch V-Plotter oder Seilplotter genannt) ist ein Zeichenroboter, der an einer Wand montiert wird und mit zwei Seilen einen Stift über eine Fläche bewegt.

``` latex  @tikz
\begin{tikzpicture}[scale=0.8]

  % Wand
  \fill[gray!15] (0,0) rectangle (12,9);
  \draw[thick] (0,0) rectangle (12,9);
  \node at (6, 9.4) {\textbf{Wand}};

  % Motoren
  \fill[blue!60] (1,8) circle (0.4);
  \fill[blue!60] (11,8) circle (0.4);
  \node[above] at (1,8.5) {\textbf{Motor A}};
  \node[above] at (11,8.5) {\textbf{Motor B}};

  % Spulen andeuten
  \draw[thick] (1,8) circle (0.25);
  \draw[thick] (11,8) circle (0.25);

  % Seile
  \draw[red, thick] (1,8) -- (5.5,4);
  \draw[red, thick] (11,8) -- (5.5,4);

  % Stifthalter
  \fill[orange!80] (5.5,4) circle (0.3);
  \node[below=0.4] at (5.5,4) {\textbf{Stift}};

  % Bemaßung
  \draw[<->, blue, thick] (1,7.5) -- (5.5,3.7) node[midway, left=0.3] {$L_A$};
  \draw[<->, blue, thick] (11,7.5) -- (5.5,3.7) node[midway, right=0.3] {$L_B$};
  \draw[<->, green!60!black, thick] (1.5,8.0) -- (10.5,8.0) node[midway, above] {$d$ (Abstand der Motoren)};

  % Gezeichneter Stern
  \draw[thick, purple] (4,3) -- (7,3) -- (4.8,1.2) -- (5.5,4) -- (6.2,1.2) -- cycle;

\end{tikzpicture}
```

Das System besteht aus wenigen Komponenten:

+ **Zwei Schrittmotoren** (oben links und rechts an der Wand befestigt)
+ **Zwei Seile/Ketten**, die von den Motoren zum Stifthalter führen
+ **Ein Stifthalter** mit Gewicht, das die Seile unter Spannung hält
+ **Ein Servo** zum Anheben und Absenken des Stifts

> Durch gezieltes Aufwickeln und Abwickeln der beiden Seile kann der Stift an jede Position auf der Wand bewegt werden.

****************************************************

            {{2-3}}
****************************************************

> Wall Plotter sind ein hervorragendes Projekt, um Mechanik, Mathematik und Programmierung zu verbinden!

> Welche Probleme sehen Sie bei der Umsetzung?

****************************************************

## Die Mathematik dahinter

> Mathematik hat nichts mit Rechnen zu tuen, sondern mit Abstraktion und Modellbildung. Um den Wall Plotter zu bauen, müssen wir dessen Funktionsprinzip technisch beschreiben.

### Das Koordinatensystem

Wir definieren unser Koordinatensystem wie folgt:

+ Motor A befindet sich bei $(0, 0)$
+ Motor B befindet sich bei $(d, 0)$
+ Die y-Achse zeigt **nach unten** (Schwerkraft!)
+ Der Stift befindet sich bei $(x, y)$

``` latex  @tikz
\begin{tikzpicture}[scale=0.9]

  % Achsen
  \draw[->, thick] (0,0) -- (11,0) node[right] {$x$};
  \draw[->, thick] (0,0) -- (0,-6) node[below] {$y$};

  % Motoren
  \fill[blue!60] (0,0) circle (0.2);
  \fill[blue!60] (10,0) circle (0.2);
  \node[above left] at (0,0) {$A(0, 0)$};
  \node[above right] at (10,0) {$B(d, 0)$};

  % Abstand d
  \draw[<->, green!60!black, thick] (0,0.5) -- (10,0.5) node[midway, above] {$d$};

  % Stiftposition
  \fill[red] (4,-5) circle (0.15);
  \node[below right] at (4,-5) {$P(x, y)$};

  % Seile
  \draw[red, thick, dashed] (0,0) -- (4,-5) node[midway, left] {$L_A$};
  \draw[red, thick, dashed] (10,0) -- (4,-5) node[midway, right] {$L_B$};

  % Projektionen
  \draw[dotted, gray] (4,0) -- (4,-5);
  \draw[dotted, gray] (0,-5) -- (4,-5);
  \draw[->, gray, thick] (0,-5) -- (4,-5) node[midway, below] {$x$};
  \draw[->, gray, thick] (4,0) -- (4,-5) node[midway, right] {$y$};

\end{tikzpicture}
```

> **Warum zeigt die y-Achse nach unten?** Die Motoren sitzen oben (y=0), der Stift hängt darunter. Damit sind alle y-Werte im Arbeitsbereich **positiv** und die Seillängenformeln $L_A = \sqrt{x^2 + y^2}$ funktionieren direkt ohne Vorzeichenprobleme. Würde y nach oben zeigen, müssten wir entweder mit negativen Koordinaten arbeiten oder den Ursprung nach unten verlegen — beides weniger intuitiv.

### Vorwärtskinematik: Von Seillängen zur Position

Gegeben: Die Seillängen $L_A$ und $L_B$ sowie der Motorabstand $d$.

Gesucht: Die Position $(x, y)$ des Stifts. $(x,y) = f(L_A, L_B, d)$

Aus dem Satz des Pythagoras ergeben sich zwei Gleichungen:

$$
L_A^2 = x^2 + y^2
$$

$$
L_B^2 = (d - x)^2 + y^2
$$

{{1}}
*******************************************************************************

Durch Subtraktion der beiden Gleichungen erhalten wir $x$:

$$
L_A^2 - L_B^2 = x^2 - (d - x)^2 = x^2 - d^2 + 2dx - x^2 = 2dx - d^2
$$

$$
\boxed{x = \frac{L_A^2 - L_B^2 + d^2}{2d}}
$$

Und daraus $y$. Wir stellen die erste Gleichung nach $y^2$ um:

$$
L_A^2 = x^2 + y^2 \quad \Rightarrow \quad y^2 = L_A^2 - x^2
$$

Da $y$ eine Länge (positiv) ist, ziehen wir die Wurzel:

$$
\boxed{y = \sqrt{L_A^2 - x^2}}
$$

*******************************************************************************

### Inverse Kinematik: Von Position zu Seillängen

> Die inverse Kinematik ist die für den Wall Plotter **entscheidende** Berechnung: Wir kennen die gewünschte Stiftposition und müssen die nötigen Seillängen berechnen.

Gegeben: Die gewünschte Position $(x, y)$ und der Motorabstand $d$.

Gesucht: Die Seillängen $L_A$ und $L_B$ oder anders formuliert $(L_A, L_B) = g(x, y, d) = f^{-1}(x, y, d)$

$$
\boxed{L_A = \sqrt{x^2 + y^2}}
$$

$$
\boxed{L_B = \sqrt{(d - x)^2 + y^2}}
$$

> Diese Formeln sind erstaunlich einfach - das ist ein großer Vorteil des Wall Plotters gegenüber anderen Roboterkinematiken!


                           {{1-2}}
*******************************************************************************

Angenommen: $d = 100\,\text{cm}$, gewünschte Position $P(30, 40)$.

**Berechnung der Seillängen:**

$$
L_A = \sqrt{30^2 + 40^2} = \sqrt{900 + 1600} = \sqrt{2500} = 50\,\text{cm}
$$

$$
L_B = \sqrt{(100-30)^2 + 40^2} = \sqrt{70^2 + 40^2} = \sqrt{4900 + 1600} = \sqrt{6500} \approx 80{,}6\,\text{cm}
$$


**Gegenprobe - Vorwärtskinematik:**

$$
x = \frac{50^2 - 80{,}6^2 + 100^2}{2 \cdot 100} = \frac{2500 - 6500 + 10000}{200} = \frac{6000}{200} = 30 \checkmark
$$

$$
y = \sqrt{50^2 - 30^2} = \sqrt{2500 - 900} = \sqrt{1600} = 40 \checkmark
$$

*******************************************************************************


## Von der Mathematik zum Motor

> Die inverse Kinematik liefert uns die benötigten Seillängen $L_A$ und $L_B$ für eine gewünschte Position. Aber wie steuern wir die Motoren an, um diese Längen zu erreichen?

### Seillänge zu Motorschritten

Ein Schrittmotor dreht sich nicht kontinuierlich, sondern in diskreten **Schritten**. Typischerweise hat ein Schrittmotor 200 Schritte pro Umdrehung (1,8 Grad pro Schritt).

Die Seillänge pro Umdrehung hängt vom Durchmesser der Spule ab:

$$
\text{Seil pro Umdrehung} = \pi \cdot d_{Spule}
$$

$$
\text{Seil pro Schritt} = \frac{\pi \cdot d_{Spule}}{\text{Schritte pro Umdrehung}}
$$

> Bei einem Spulendurchmesser von 10 mm und 200 Schritten pro Umdrehung ergibt sich:
>
> $\frac{\pi \cdot 10\,\text{mm}}{200} \approx 0{,}157\,\text{mm pro Schritt}$

### Ablauf einer Bewegung

Um den Stift von Position $P_1(x_1, y_1)$ nach $P_2(x_2, y_2)$ zu bewegen:

1. Berechne $L_{A1}, L_{B1}$ für die aktuelle Position
2. Berechne $L_{A2}, L_{B2}$ für die Zielposition
3. Berechne die Differenz: $\Delta L_A = L_{A2} - L_{A1}$, $\Delta L_B = L_{B2} - L_{B1}$
4. Wandle die Differenzen in Motorschritte um
5. Bewege beide Motoren gleichzeitig

```mermaid @mermaid
graph LR
    A[Zielposition] --> B[Inverse Kinematik]
    B --> C[Seillängen-Differenz]
    C --> D[Motorschritte]
    D --> E[Motoren bewegen]
```

> Welches Problem sehen Sie?

### Bresenham-Interpolation

Wenn der Stift eine gerade Linie zeichnen soll, müssen sich beide Motoren **synchron** bewegen. Dabei müssen wir sicherstellen, dass der eine Motor nicht schneller fertig wird als der andere.

> Der **Bresenham-Algorithmus** (bekannt aus der Computergrafik für das Zeichnen von Linien auf einem Pixelraster) löst genau dieses Problem: Er verteilt die Schritte beider Motoren gleichmäßig über die Zeit.


``` latex  @tikz
\begin{tikzpicture}[scale=0.6]

  % Achsen
  \draw[->, thick] (0,0) -- (11,0) node[right] {Zeit};
  \draw[->, thick] (0,0) -- (0,7) node[above] {Schritte};

  % Motor A - 8 Schritte
  \draw[blue, thick] (0,0) -- (1,1) -- (2,1) -- (3,2) -- (4,3) -- (5,3) -- (6,4) -- (7,5) -- (8,5) -- (9,6) -- (10,6);
  \node[blue, right] at (10,6) {Motor A (6 Schritte)};

  % Motor B - 10 Schritte
  \draw[red, thick] (0,0) -- (1,1) -- (2,2) -- (3,3) -- (4,3) -- (5,4) -- (6,5) -- (7,6) -- (8,7) -- (9,8) -- (10,8);
  \node[red, right] at (10,8) {Motor B (8 Schritte)};

  % Schrittmarkierungen
  \foreach \y in {1,...,8} {
    \draw[dotted, gray] (0,\y) -- (10,\y);
  }

\end{tikzpicture}
```


## Technische Herausforderungen

> Obwohl die Mathematik elegant ist, gibt es in der Praxis viele Herausforderungen, die die Genauigkeit und Qualität der Zeichnung beeinflussen.

### 1. Auflösung und Genauigkeit

Die Auflösung des Wall Plotters ist **nicht überall gleich**! Sie hängt von der Position des Stifts ab.

+ **Mitte der Zeichenfläche**: Beide Seile ziehen schräg nach oben $\rightarrow$ Änderungen in $x$ und $y$ werden gut aufgelöst
+ **Nahe einem Motor**: Ein Seil ist fast senkrecht $\rightarrow$ Kleine Winkeländerungen führen zu großen Positionsänderungen
+ **Oberer Rand**: Beide Seile sind fast horizontal $\rightarrow$ Vertikale Bewegungen sind schwer zu kontrollieren

### 2. Schwerkraft und Seilspannung

Die Schwerkraft wirkt auf den Stifthalter und beeinflusst die Zeichengenauigkeit:

+ Das Gewicht des Stifthalters sorgt dafür, dass die Seile gespannt bleiben
+ **Zu leicht**: Seile hängen durch, Position wird ungenau
+ **Zu schwer**: Zu viel Reibung auf der Zeichenfläche, Stift kratzt

``` latex  @tikz
\begin{tikzpicture}[scale=0.8]

  % Setup links - durchhängende Seile
  \node at (3,1) {\textbf{Zu leichter Stifthalter}};
  \fill[blue!60] (0,0) circle (0.15);
  \fill[blue!60] (6,0) circle (0.15);

  % Durchhängende Seile (Katenare approximiert)
  \draw[red, thick] (0,0) .. controls (1,-1.5) and (2,-2.5) .. (3,-3);
  \draw[red, thick] (6,0) .. controls (5,-1.5) and (4,-2.5) .. (3,-3);

  \fill[orange] (3,-3) circle (0.15);
  \node[below] at (3,-3.3) {Ungenau!};

  % Setup rechts - gespannte Seile
  \node at (11,1) {\textbf{Richtige Gewichtung}};
  \fill[blue!60] (8,0) circle (0.15);
  \fill[blue!60] (14,0) circle (0.15);

  % Gespannte Seile
  \draw[red, thick] (8,0) -- (11,-3);
  \draw[red, thick] (14,0) -- (11,-3);

  \fill[orange] (11,-3) circle (0.15);
  \draw[->, thick] (11,-3) -- (11,-4.5) node[below] {Gewicht};

\end{tikzpicture}
```

### 3. Seildehnung und -wicklung

+ Seile können sich unter Last **dehnen** (vor allem Nylonseile)
+ Beim Aufwickeln auf eine Spule ändert sich der **effektive Durchmesser**
+ Lösung: Ketten oder Zahnriemen statt Seile, oder Umlenkrollen

``` latex  @tikz
\begin{tikzpicture}[scale=1.0]

  % Spule mit wenig Seil
  \draw[thick] (0,0) circle (0.5);
  \draw[thick] (0,0) circle (0.6);
  \node at (0,-1.2) {Wenig aufgewickelt};
  \node at (0,-1.7) {$d_{eff}$ klein};
  \draw[<->] (0,0) -- (0.55,0) node[midway, above] {\tiny $r$};

  % Spule mit viel Seil
  \draw[thick] (5,0) circle (0.5);
  \draw[thick] (5,0) circle (0.7);
  \draw[thick] (5,0) circle (0.9);
  \draw[thick] (5,0) circle (1.1);
  \node at (5,-1.5) {Viel aufgewickelt};
  \node at (5,-2.0) {$d_{eff}$ gross};
  \draw[<->] (5,0) -- (6.1,0) node[midway, above] {\tiny $r$};

  % Pfeil
  \draw[->, very thick] (1.5,0) -- (3.5,0) node[midway, above] {Mehr Seil};

\end{tikzpicture}
```

> Bei zunehmender Wicklung ändert sich die Seillänge pro Motorschritt - das verfälscht die Positionsberechnung!

### 4. Dynamik und Trägheit

Bei schnellen Bewegungen oder Richtungswechseln schwingt der Stifthalter nach (Pendelbewegung):

+ Der Stifthalter ist ein **Pendel** an zwei Seilen
+ Schnelle Richtungswechsel regen Schwingungen an
+ Die Schwingungen verfälschen die Zeichnung

**Gegenmaßnahmen:**

+ Langsame Bewegungen (Beschleunigungs- und Bremsrampen)
+ Wartezeiten nach Richtungswechseln
+ Schwerer Stifthalter (mehr Trägheit, aber auch mehr Reibung)


## Eine Figur zeichnen

### G-Code als Eingabeformat

Professionelle CNC-Maschinen und auch Wall Plotter verwenden **G-Code** als Steuersprache. Die wichtigsten Befehle:

| Befehl      | Bedeutung                                  |
| ----------- | ------------------------------------------ |
| `G0 X30 Y40`  | Schnell zu Position (30, 40) fahren (ohne Zeichnen) |
| `G1 X50 Y60`  | Linie zu Position (50, 60) zeichnen        |
| `M3`        | Stift absenken (Zeichnen beginnen)         |
| `M5`        | Stift anheben (Zeichnen beenden)           |

### Beispiel: Ein Quadrat zeichnen

```
G0 X20 Y20     ; Zur Startposition fahren
M3              ; Stift absenken
G1 X60 Y20     ; Linie nach rechts
G1 X60 Y60     ; Linie nach unten
G1 X20 Y60     ; Linie nach links
G1 X20 Y20     ; Linie nach oben (zurück zum Start)
M5              ; Stift anheben
```

> <div>
``` latex  @tikz
\begin{tikzpicture}[scale=0.08]

  % Motoren
  \fill[blue!60] (0,0) circle (1.5);
  \fill[blue!60] (100,0) circle (1.5);
  \node[above] at (0,2) {A};
  \node[above] at (100,2) {B};

  % Quadrat
  \draw[very thick, purple, ->] (20,20) -- (60,20) node[midway, below] {1};
  \draw[very thick, purple, ->] (60,20) -- (60,60) node[midway, right] {2};
  \draw[very thick, purple, ->] (60,60) -- (20,60) node[midway, above] {3};
  \draw[very thick, purple, ->] (20,60) -- (20,20) node[midway, left] {4};

  % Seile zum Startpunkt
  \draw[red, dashed] (0,0) -- (20,20);
  \draw[red, dashed] (100,0) -- (20,20);

\end{tikzpicture}
```
</div>

### G-Code Interpreter

Ein einfacher G-Code Interpreter für den Arduino liest Befehle über die serielle Schnittstelle:

```cpp
void verarbeite_gcode(String zeile) {
  zeile.trim();

  if (zeile.startsWith("G0") || zeile.startsWith("G1")) {
    // Position extrahieren
    float x = extrahiere_wert(zeile, 'X');
    float y = extrahiere_wert(zeile, 'Y');

    if (zeile.startsWith("G0")) {
      stift_heben();
    }

    fahre_zu(x, y);
  }
  else if (zeile == "M3") {
    stift_senken();
  }
  else if (zeile == "M5") {
    stift_heben();
  }
}

float extrahiere_wert(String zeile, char achse) {
  int pos = zeile.indexOf(achse);
  if (pos == -1) return 0;

  String wert = "";
  pos++;
  while (pos < zeile.length() && (isDigit(zeile[pos]) || zeile[pos] == '.' || zeile[pos] == '-')) {
    wert += zeile[pos];
    pos++;
  }
  return wert.toFloat();
}

void loop() {
  if (Serial.available()) {
    String zeile = Serial.readStringUntil('\n');
    verarbeite_gcode(zeile);
    Serial.println("OK");  // Bestätigung an den PC
  }
}
```


## Zusammenfassung

### Was haben wir gelernt?

1. **Konzept**: Ein Wall Plotter bewegt einen Stift über zwei Seile an einer Wand
2. **Mathematik**: Die inverse Kinematik berechnet aus $(x, y)$ die benötigten Seillängen $L_A$ und $L_B$
3. **Motoransteuerung**: Schrittmotoren bewegen die Seile in diskreten Schritten
4. **Interpolation**: Der Bresenham-Algorithmus synchronisiert die beiden Motoren
5. **Herausforderungen**: Auflösung, Schwerkraft, Seildehnung und Dynamik beeinflussen die Zeichenqualität

### Weiterführende Ideen

+ Kalibrierungsroutine implementieren (automatische Vermessung des Arbeitsbereichs)
+ SVG-Dateien in G-Code umwandeln (z.B. mit Inkscape + G-Code Plugin)
+ Beschleunigungs- und Bremsrampen für sanftere Bewegungen
+ Mehrfarbiges Zeichnen mit automatischem Stiftwechsel

```mermaid @mermaid
graph LR
    A[SVG-Datei] -->|Inkscape Plugin| B[G-Code]
    B -->|Serielle Schnittstelle| C[Arduino]
    C -->|Schrittmotoren| D[Wall Plotter]
    D --> E[Zeichnung an der Wand]
```

!?[Beispiel](https://www.youtube.com/watch?v=Yg7z5wKEo0o)
