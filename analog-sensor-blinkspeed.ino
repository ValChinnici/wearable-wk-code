#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN 1 // <------ This Parameter refers to the DIN pin where the neopixel strip is connected

Adafruit_NeoPixel strip = Adafruit_NeoPixel(5, PIN, NEO_GRB + NEO_KHZ800); // This line provides some useful
//information about your Neopixel strip:
//How many pixels, which pin is connected, etc.

int sensorPin = A0;    // select the input pin for the analog sensor ("S" on your sensor module). Check it on your board
int sensorValue = 0;  // variable to store the value coming from the sensor (Do not touch this value)

void setup() {

  strip.begin(); //these 2 commands will initialise your Neopixel strip
  strip.show();

}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);

  //this is one of the multiple light options with your Neopixels
  //rainbow Cycle
  //starts here
  uint16_t i, j;
  for (j = 0; j < 256; j++) {
    for (int i = 0; i < strip.numPixels(); i++) {

      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
  }
 
//finishes here

/* //this is another possible visual effect
  colorWipe(strip.Color(255, 0, 0), 50); // Red
  colorWipe(strip.Color(0, 255, 0), 50); // Green
  colorWipe(strip.Color(0, 0, 255), 50); // Blue
*/

//this will turn your Neopixels off
  strip.setPixelColor(0, strip.Color(0, 0, 0));
  strip.setPixelColor(1, strip.Color(0, 0, 0));
  strip.setPixelColor(2, strip.Color(0, 0, 0));
  strip.setPixelColor(3, strip.Color(0, 0, 0));
  strip.setPixelColor(4, strip.Color(0, 0, 0));

  delay(sensorValue);
  strip.show();

 
}


// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
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

/* Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(sensorValue);
  }
}
*/
