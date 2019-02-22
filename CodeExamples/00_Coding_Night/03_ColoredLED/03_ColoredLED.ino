const int redPin = 10;
const int greenPin = 9;
const int bluePin = 8;
 
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
  unsigned int rgbColour[3];

  // Start off with red.
  rgbColour[0] = 255;
  rgbColour[1] = 255;
  rgbColour[2] = 255;

  setColourRgb(rgbColour[0], rgbColour[1], rgbColour[2]);
  delay(1000);
}
