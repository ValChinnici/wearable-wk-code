#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN 1 // <------ This Parameter refers to the DIN pin where the neopixel strip is connected

// This line below provides some useful
//information about your Neopixel strip:
//How many pixels, which pin is connected, etc.
Adafruit_NeoPixel strip = Adafruit_NeoPixel(6, PIN, NEO_GRB + NEO_KHZ800);

int sensorPin = A1;    // select the input pin for the analog sensor ("S" on your sensor module). Che
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {

  strip.begin(); //these 2 commands will initialise your Neopixel strip
  strip.show();

}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  int pixelsLevel = map(sensorValue, 0, 1023, 0, strip.numPixels());

  for (int currentLed = 0; currentLed < strip.numPixels(); currentLed++) {
//the lines embedded into the if/else statement control the color of the bargraph (in this case rainbow)
    if (pixelsLevel >= currentLed) {
      byte myColour = map(currentLed, 0, pixelsLevel, 0, 255);
      strip.setPixelColor(currentLed, Wheel(myColour)); 
    }
    else {
      strip.setPixelColor(currentLed, 0, 0, 0);
    }

    strip.show();
    delay(50);


  }
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
    WheelPos -= 170;
    return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}
