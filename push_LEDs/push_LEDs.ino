#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN            6
#define NUMPIXELS      240  // DEFINE YOUR NUM OF PIXELS!!!11elf
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int delayval = 5; // delay for half a second
void setup() 
{
  pixels.begin();
}

int rcolor = 0;
int gcolor = 0;
int bcolor = 0;

void loop() {
  for(int i=0;i<NUMPIXELS;i++)
  {
    //define new random color
    rcolor = random(1,254);
    gcolor = random(1,254);
    bcolor = random(1,254);
    
    // present first color
    pixels.setPixelColor(0, pixels.Color(rcolor,gcolor,bcolor));
    pixels.show();
    delay(50);

    // move color to the end, NUMPIXELS-i: attach to existing colors
    for(int j=1;j<NUMPIXELS-i;j++)
    {
      pixels.setPixelColor(j-1, pixels.Color(0,0,0));
      pixels.setPixelColor(j, pixels.Color(rcolor,gcolor,bcolor));
      pixels.show();
      delay(delayval);
    }
  }
  
  for(int i=0;i<NUMPIXELS;i++)
  {
    // clear strap
    pixels.setPixelColor(i, pixels.Color(0,0,0));
    pixels.show();
    delay(1); 
  }
}
