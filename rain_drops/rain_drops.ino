#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN            6
#define NUMPIXELS      240  // DEFINE YOUR NUM OF PIXELS!!!11elf
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int delayval = 5; // delay for half a second

int rcolor = 0;
int gcolor = 0;
int bcolor = 100;
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
  newpos=random(0,NUMPIXELS-1);
  if(newpos>1)
  {
    pixels.setPixelColor(newpos-2, pixels.Color(0,0,2*20));
    array[newpos-2]=2;
  }
  if(newpos>0)
  {
    pixels.setPixelColor(newpos-1, pixels.Color(0,0,5*20));
    array[newpos-1]=5;
  }
  pixels.setPixelColor(newpos, pixels.Color(0,0,254));
  array[newpos]=9;
  if(newpos<239)
  {
    pixels.setPixelColor(newpos+1, pixels.Color(0,0,5*20));
    array[newpos+1]=5;
  }
  if(newpos<238)
  {
    pixels.setPixelColor(newpos+2, pixels.Color(0,0,2*20));
    array[newpos+2]=2;
  }
  pixels.show();
  
  for(int i=0;i<NUMPIXELS;i++)
  {
    if(array[i]>0)
    {
      array[i]--;
      pixels.setPixelColor(i, pixels.Color(0,0,array[i]*20));
      pixels.show(); 
    }
    //delay(1); 
  } 
} 



  /*
   
  for(i=0;i<NUMPIXELS;i++)
  {
    //define new random color
    rcolor = 10*random(1,25); //random(1,254);
    gcolor = 10*random(1,25); //random(1,254);
    bcolor = 10*random(1,25); //random(1,254);
    
    // present first color
    pixels.setPixelColor(0, pixels.Color(rcolor,gcolor,bcolor));
    pixels.show();
    delay(10);

    // move color to the end, NUMPIXELS-i: attach to existing colors
    for(j=2;j<NUMPIXELS-i;j=j+2)
    {
      pixels.setPixelColor(j-2, pixels.Color(0,0,0));
      pixels.setPixelColor(j, pixels.Color(rcolor,gcolor,bcolor));
      pixels.show();
      delay(delayval);
      if(j==(NUMPIXELS-i)-2)
      {
        pixels.setPixelColor(j, pixels.Color(0,0,0));
        pixels.setPixelColor(j+1, pixels.Color(rcolor,gcolor,bcolor));
              pixels.show();
      delay(delayval);
      }
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

*/


