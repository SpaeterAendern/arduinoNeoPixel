#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN            6
#define NUMPIXELS      240  // DEFINE YOUR NUM OF PIXELS!!!11elf
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int delayval = 5; // delay for half a second




String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  
  pixels.begin();
}

int rcolor = 1;
int gcolor = 1;
int bcolor = 1;
char c;
int i;
int j;

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

void loop() {
  serialEvent();
  //Serial.println("NOPE");
  if (stringComplete) { 
    Serial.println(inputString);
    if(inputString.length()==5)
    {
    c=inputString.charAt(0);
    rcolor= (c - 48)*24;
    c=inputString.charAt(1);
    gcolor= (c - 48)*24;
    c=inputString.charAt(2);
    bcolor= (c - 48)*24;
    }
    else
    Serial.println("Woppi!");
    // clear the string:
    inputString = "";
    stringComplete = false;
  }

    for(i=0;i<NUMPIXELS;i++)
    {
      pixels.setPixelColor(i, pixels.Color(rcolor,gcolor,bcolor));
      //pixels.show();
      //delay(10);
    }
      pixels.show();
      delay(100);
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


