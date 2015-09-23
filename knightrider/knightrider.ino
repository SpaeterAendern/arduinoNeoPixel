#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN            6
#define NUMPIXELS      240  // DEFINE YOUR NUM OF PIXELS!!!11elf
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int delayval = 5; // delay for half a second

int rcolor = 110;
int gcolor = 0;
int bcolor = 0;
int i;
int j;
int newpos;
int possible=0;
int counter=0;
int deleter=0;
int array[240];

void setup() 
{
  pixels.begin();
  for(int i=0;i<NUMPIXELS;i++)
  {
    pixels.setPixelColor(i, pixels.Color(0,0,0));
    pixels.show();
    //delay(1); 
  } 
}

void loop() 
{ 
  bla:
  rcolor=random(1,254);
  gcolor=random(1,254);
  bcolor=random(1,254);
  for(int i=0;i<NUMPIXELS;i++)
  {
    if(i>2) pixels.setPixelColor(i-3, pixels.Color(0,0,0));
    if(i>1) pixels.setPixelColor(i-2, pixels.Color(rcolor,gcolor,bcolor));
    if(i>0) pixels.setPixelColor(i-1, pixels.Color(rcolor,gcolor,bcolor));
    pixels.setPixelColor(i, pixels.Color(rcolor,gcolor,bcolor));
    pixels.show();
    delay(1);
  } 


for(int i=NUMPIXELS-3;i<NUMPIXELS;i++)
  {
    pixels.setPixelColor(i, pixels.Color(0,0,0));
    pixels.show();
    delay(1);
  } 
  //goto bla;
  rcolor=random(1,254);
  gcolor=random(1,254);
  bcolor=random(1,254);
  for(int i=NUMPIXELS;i>0;i--)
  {
    pixels.setPixelColor(i, pixels.Color(rcolor,gcolor,bcolor));
    if(i<NUMPIXELS) pixels.setPixelColor(i+1, pixels.Color(rcolor,gcolor,bcolor));
    if(i<NUMPIXELS-1) pixels.setPixelColor(i+2, pixels.Color(rcolor,gcolor,bcolor));
    if(i<NUMPIXELS-2) pixels.setPixelColor(i+3, pixels.Color(0,0,0));
    

    pixels.show(); 
    delay(2);
  } 
} 





