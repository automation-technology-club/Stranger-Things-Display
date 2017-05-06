/*Strangerthings with twinkle - based on NeoPixel Color Twinkle by suhajdab
 * https://gist.github.com/suhajdab/9716028
 * 
 * Strangerthing code based on "Stranger Things Interactive Wall Art by Akin Yildiz
 * https://www.instructables.com/id/Stranger-Things-Interactive-Wall-Art/
 * 
 * Modification by LeRoy Miller, 2017 For Stranger Things Escape Room Puzzle
 * Midpointe Library West Chester Ohio
 * 
 * This code is a work in progress. May 5, 2017
 * 
 */

#include <Adafruit_NeoPixel.h>
#define PIN 6
#define Pixels 27

Adafruit_NeoPixel strip = Adafruit_NeoPixel(27, PIN, NEO_GRB + NEO_KHZ800);

float redStates[Pixels];
float blueStates[Pixels];
float greenStates[Pixels];
float fadeRate = 0.96;
    
void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  for(uint16_t l = 0; l < Pixels; l++) {
    redStates[l] = 0;
    greenStates[l] = 0;
    blueStates[l] = 0;
  }
}


void loop() {
  for(int i=0;i<=2000;i++) {
    if (random(20) == 1) {
      uint16_t i = random(Pixels);
      if (redStates[i] < 1 && greenStates[i] < 1 && blueStates[i] < 1) {
        redStates[i] = random(256);
        greenStates[i] = random(256);
        blueStates[i] = random(256);
      }
    }
    
    for(uint16_t l = 0; l < Pixels; l++) {
      if (redStates[l] > 1 || greenStates[l] > 1 || blueStates[l] > 1) {
        strip.setPixelColor(l, redStates[l], greenStates[l], blueStates[l]);
        
        if (redStates[l] > 1) {
          redStates[l] = redStates[l] * fadeRate;
        } else {
          redStates[l] = 0;
        }
        
        if (greenStates[l] > 1) {
          greenStates[l] = greenStates[l] * fadeRate;
        } else {
          greenStates[l] = 0;
        }
        
        if (blueStates[l] > 1) {
          blueStates[l] = blueStates[l] * fadeRate;
        } else {
          blueStates[l] = 0;
        }
        
      } else {
       // strip.setPixelColor(l, 0, 0, 0);
      }
    }
    strip.show();
    delay(10);
  }
  for(int i=0;i<26;i++){
  strip.setPixelColor(0, 105, 105, 105);  //A - white
  strip.setPixelColor(1, 0, 0, 105);      //B - blue
  strip.setPixelColor(2, 105, 0, 0);      //C - red
  strip.setPixelColor(3, 0, 80, 105);     //D - light blue
  strip.setPixelColor(4, 0, 0, 105);      //E - blue
  strip.setPixelColor(5, 105, 105, 25);   //F - yellow
  strip.setPixelColor(6, 105, 0, 0);      //G - red
  strip.setPixelColor(7, 0, 0, 105);      //H - blue
  strip.setPixelColor(8, 0, 0, 105);      //I - blue
  strip.setPixelColor(9, 105, 0, 0);      //J - red
  strip.setPixelColor(10, 0, 0, 105);     //K - blue
  strip.setPixelColor(11, 105, 105, 105); //L - white
  strip.setPixelColor(12, 105, 105, 25);  //M - yellow
  strip.setPixelColor(13, 105, 0, 0);     //N - red
  strip.setPixelColor(14, 105, 0, 0);     //O - red
  strip.setPixelColor(15, 0, 80, 105);    //P - light blue
  strip.setPixelColor(16, 105, 0, 0);     //Q - red
  strip.setPixelColor(17, 0, 80, 105);    //R - light blue
  strip.setPixelColor(18, 105, 105, 105); //S - white
  strip.setPixelColor(19, 105, 105, 25);  //T - yellow
  strip.setPixelColor(20, 0, 0, 105);     //U - blue
  strip.setPixelColor(21, 105, 0, 0);     //V - red
  strip.setPixelColor(22, 0, 0, 105);     //W - blue
  strip.setPixelColor(23, 105, 105, 25);  //X - yellow
  strip.setPixelColor(24, 105, 0, 0);     //Y - red
  strip.setPixelColor(25, 105, 0, 0);     //Z - red
  strip.setPixelColor(26, 255, 0, 255);   //empty - none
  strip.show();
 
  }
   delay(1000);
  for(int i=0;i<26;i++){
  strip.setPixelColor(0, 0, 0, 0);      //A - white
  strip.setPixelColor(1, 0, 0, 0);      //B - blue
  strip.setPixelColor(2, 0, 0, 0);      //C - red
  strip.setPixelColor(3, 0, 0, 0);      //D - light blue
  strip.setPixelColor(4, 0, 0, 0);      //E - blue
  strip.setPixelColor(5, 0, 0, 0);      //F - yellow
  strip.setPixelColor(6, 0, 0, 0);      //G - red
  strip.setPixelColor(7, 0, 0, 0);      //H - blue
  strip.setPixelColor(8, 0, 0, 0);      //I - blue
  strip.setPixelColor(9, 0, 0, 0);      //J - red
  strip.setPixelColor(10, 0, 0, 0);     //K - blue
  strip.setPixelColor(11, 0, 0, 0);     //L - white
  strip.setPixelColor(12, 0, 0, 0);     //M - yellow
  strip.setPixelColor(13, 0, 0, 0);     //N - red
  strip.setPixelColor(14, 0, 0, 0);     //O - red
  strip.setPixelColor(15, 0, 0, 0);     //P - light blue
  strip.setPixelColor(16, 0, 0, 0);     //Q - red
  strip.setPixelColor(17, 0, 0, 0);     //R - light blue
  strip.setPixelColor(18, 0, 0, 0);     //S - white
  strip.setPixelColor(19, 0, 0, 0);     //T - yellow
  strip.setPixelColor(20, 0, 0, 0);     //U - blue
  strip.setPixelColor(21, 0, 0, 0);     //V - red
  strip.setPixelColor(22, 0, 0, 0);     //W - blue
  strip.setPixelColor(23, 0, 0, 0);     //X - yellow
  strip.setPixelColor(24, 0, 0, 0);     //Y - red
  strip.setPixelColor(25, 0, 0, 0);     //Z - red
  strip.setPixelColor(26, 0, 0, 0);     //empty - none
  strip.show();
 
  }
   delay(1000);
  for(int i=0;i<26;i++){
    strip.setPixelColor(17, 0, 80, 105);    //R - light blue
   }
   strip.show();
   delay(600);
   
   for(int i=0;i<26;i++){
    strip.setPixelColor(17, 0, 0, 0);       //R - off
    strip.setPixelColor(8, 0, 0, 105);      //I - blue
   }   
   strip.show();
   delay(600);
   
   for(int i=0;i<26;i++){
    strip.setPixelColor(8, 0, 0, 0);        //I - off
    strip.setPixelColor(6, 105, 0, 0);      //G - red
   }
   strip.show();
   delay(600);
   
   for(int i=0;i<26;i++){
    strip.setPixelColor(6, 0, 0, 0);        //G - off
    strip.setPixelColor(7, 0, 0, 105);      //H - blue
   }
   strip.show();
   delay(600);
   
   for(int i=0;i<26;i++){
    strip.setPixelColor(7, 0, 0, 0);        //H - off
    strip.setPixelColor(19, 105, 105, 15);  //T - yellow
   }
   strip.show();
   delay(600);

   for(int i=0;i<26;i++){
    strip.setPixelColor(19, 0, 0, 0);       //T - off
   }
   strip.show();
   delay(1100);

   // --------------------------------------------------------
   // HERE
   
   for(int i=0;i<26;i++){
    strip.setPixelColor(7, 0, 0, 105);      //H - blue
   }
   strip.show();
   delay(600);
   
   for(int i=0;i<26;i++){
    strip.setPixelColor(7, 0, 0, 0);        //H - off
    strip.setPixelColor(4, 0, 0, 105);      //E - blue
   }   
   strip.show();
   delay(600);
   
   for(int i=0;i<26;i++){
    strip.setPixelColor(4, 0, 0, 0);        //E - off
    strip.setPixelColor(17, 0, 80, 105);    //R - light blue
   }
   strip.show();
   delay(600);
   
   for(int i=0;i<26;i++){
    strip.setPixelColor(17, 0, 0, 0);       //R - off
    strip.setPixelColor(4, 0, 0, 105);      //E - blue
   }
   strip.show();
   delay(600);
   
   for(int i=0;i<26;i++){
    strip.setPixelColor(4, 0, 0, 0);        //E - off
   }
   strip.show();
   delay(2100);

   // --------------------------------------------------------
   // RUN
   
   for(int i=0;i<26;i++){
    strip.setPixelColor(17, 0, 80, 105);    //R - light blue
   }
   strip.show();
   delay(600);
   
   for(int i=0;i<26;i++){
    strip.setPixelColor(17, 0, 0, 0);       //R - off
    strip.setPixelColor(20, 0, 0, 105);     //U - blue
   }   
   strip.show();
   delay(600);
   
   for(int i=0;i<26;i++){
    strip.setPixelColor(20, 0, 0, 0);       //U - off
    strip.setPixelColor(13, 105, 0, 0);     //N - red
   }
   strip.show();
   delay(600);
   
   for(int i=0;i<26;i++){
    strip.setPixelColor(13, 0, 0, 0);       //N - off
   }
   strip.show();
   delay(2100);

  }
