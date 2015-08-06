#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN 1 // <------ This Parameter refers to the DIN pin where the neopixel strip is connected

// This line below provides some useful
//information about your Neopixel strip:
//How many pixels, which pin is connected, etc.
Adafruit_NeoPixel strip = Adafruit_NeoPixel(3, PIN, NEO_GRB + NEO_KHZ800);

int sensorPin = A0;    // select the input pin for the analog sensor ("S" on your sensor module). Che
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {

  strip.begin(); //these 2 commands will initialise your Neopixel strip
  strip.show();

}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  int pixelsLevel = map(sensorValue, 0, 600, 0, strip.numPixels());

  for (int currentLed = 0; currentLed < strip.numPixels(); currentLed++) {

    if (pixelsLevel >= currentLed) {

      strip.setPixelColor(currentLed, 255, 0, 0); // change the color of your bar graph here, values are Green, Red, Blue
    }
    else {

      strip.setPixelColor(currentLed, 0, 0, 0);


    }


    strip.show();
    delay(50);


  }
}
