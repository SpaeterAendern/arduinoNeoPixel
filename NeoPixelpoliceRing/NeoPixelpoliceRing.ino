// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
#include <Adafruit_NeoPixel.h>

#define PIN            6
#define NUMPIXELS      64

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 80;
const int buttonPin = 2;       // the number of the pushbutton pin
int buttonState = 0;          // variable for reading the pushbutton status

void setup() {
  pixels.begin();     // This initializes the NeoPixel library.  
  pinMode(buttonPin, INPUT);       
}

void loop() 
{ 
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) 
  {     
  
    for(int i=0;i<NUMPIXELS;i=i+1)
    {   
      pixels.setPixelColor(i, pixels.Color(0,0,254)); 
    }
    pixels.show();   
    delay(delayval*2); 
   
    for(int i=0;i<NUMPIXELS;i=i+1)
    {   
      pixels.setPixelColor(i, pixels.Color(254,254,254)); 
    }
    pixels.show();   
    delay(delayval);   
    
    for(int i=0;i<NUMPIXELS;i=i+1)
    {   
      pixels.setPixelColor(i, pixels.Color(254,0,0)); 
    }
    pixels.show();   
    delay(delayval*2);  
   
    for(int i=0;i<NUMPIXELS;i=i+1)
    {   
      pixels.setPixelColor(i, pixels.Color(254,254,254)); 
    }
    pixels.show();   
    delay(delayval); 
  }
  else
  {
    for(int i=0;i<NUMPIXELS;i=i+1)
    { 
      pixels.setPixelColor(i, pixels.Color(0,0,0));
      pixels.show();   
    }
  }
}
