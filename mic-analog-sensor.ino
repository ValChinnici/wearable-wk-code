/* 

This sketch is inspired by this 
http://sizemorelabs.com/neopixels-on-your-drum/

*/



#include <Adafruit_NeoPixel.h>
 
//Variables defining envionrment & hardware setup
#define N_PIXELS         60  // Number of pixels you are using
#define THRESHOLD       100  // threshold value to determine is signal is noise
#define INTERVAL         4  // cycle time in milliseconds - fade out every x ms

 
 
 
const int neopixelPin = 0;  // Neopixel data pin
const int ledPin = 1; // led connected to digital pin 1 - delete this if you don't want the LED on the Gemma board to light up
const int micSensor = 1; // the piezo is connected to analog pin 1
 
int sensorReading = 0; // variable to store the value read from the sensor pin
int ledState = LOW; // variable used to store the last LED status, to toggle the light

unsigned long last_time = 0;
 
Adafruit_NeoPixel  strip = Adafruit_NeoPixel(N_PIXELS, neopixelPin, NEO_GRB + NEO_KHZ800);
 
 
void setup() {
  pinMode(ledPin, OUTPUT); // declare the ledPin as as OUTPUT
  strip.begin();
  strip.setBrightness(255);
}
 
void loop() {
  uint8_t  i;
  unsigned long current_time;
  
  // read the piezo sensor
  sensorReading = analogRead(micSensor); 
 
  // if the sensor reading is greater than the threshold:
  if (sensorReading >= THRESHOLD) {
  
  //Turn the NeoPixels to bright white
 
  for(i=0; i<N_PIXELS; i++) {  
      strip.setPixelColor(0, 0, 255, 0);
      strip.setPixelColor(1, 255, 0, 0);
      strip.setPixelColor(2, 0, 255, 125);
      strip.setPixelColor(3, 125, 0, 255);
      strip.setPixelColor(4, 255, 125, 0);
    } 
 
    digitalWrite(ledPin, HIGH);
    last_time = millis();
  }
  else {
  // Sensor reading is too low, fade the LEDs off
    digitalWrite(ledPin, LOW);
    current_time = millis();
 
  if (current_time - last_time > INTERVAL){
    last_time = current_time;  // reset the timer
 
 
    
      // update the pixels
      for(i=0; i<N_PIXELS; i++) {  
          strip.setPixelColor(i, 0, 0, 0);
      }
  }
  }
    
//Send out the udpates
strip.show(); // Update strip
}
