/* Strangerthings with twinkle - based on NeoPixel Color Twinkle by suhajdab
 * https://gist.github.com/suhajdab/9716028
 * 
 * Strangerthing code based on "Stranger Things Interactive Wall Art by Akin Yildiz
 * https://www.instructables.com/id/Stranger-Things-Interactive-Wall-Art/
 * 
 * Modification by LeRoy Miller, 2017 For Stranger Things Escape Room Puzzle
 * Midpointe Library West Chester Ohio
 * 
 * This code is a work in progress. May 5, 2017
 * Revised May 11, 2017 - for ESP8266, Changed Colors to array, 
 * function to spell any word you'd like (see code)
 * modified twinkle routine to just "twinkle" red, moved to it's 
 * own function.
 *  
 *  This code no long works on the UNO, it may work on the MEGA * 
 *  
 *  May 13, 17 - updated code for WS2811 Pixel strip, these are RGB and 400khz
 *  
 */


#include <Adafruit_NeoPixel.h>
#define PIN 2
int pixels=50; //total pixels
int redPixels = 25; //total pixels - 26 = left over pixels for border
int wait = 600; //delay for pixel display
float redStates[25]; //this should be the same number as redPixels
float fadeRate = 0.96;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(pixels, PIN, NEO_RGB + NEO_KHZ400);

uint32_t colorArray[26] = {
  strip.Color(105,105,105), //A - white
  strip.Color(0, 0, 105),   //B - blue
  strip.Color(105, 0, 0),   //C - red
  strip.Color(0, 80, 105),     //D - light blue
  strip.Color(0, 0, 105),      //E - blue
  strip.Color(105, 105, 25),   //F - yellow
  strip.Color(105, 0, 0),      //G - red
  strip.Color(0, 0, 105),      //H - blue
  strip.Color(0, 0, 105),      //I - blue
  strip.Color(105, 0, 0),      //J - red
  strip.Color(0, 0, 105),     //K - blue
  strip.Color(105, 105, 105), //L - white
  strip.Color(105, 105, 25),  //M - yellow
  strip.Color(105, 0, 0),     //N - red
  strip.Color(105, 0, 0),     //O - red
  strip.Color(0, 80, 105),    //P - light blue
  strip.Color(105, 0, 0),     //Q - red
  strip.Color(0, 80, 105),    //R - light blue
  strip.Color(105, 105, 105), //S - white
  strip.Color(105, 105, 25),  //T - yellow
  strip.Color(0, 0, 105),     //U - blue
  strip.Color(105, 0, 0),     //V - red
  strip.Color(0, 0, 105),     //W - blue
  strip.Color(105, 105, 25),  //X - yellow
  strip.Color(105, 0, 0),     //Y - red
  strip.Color(105, 0, 0),     //Z - red
};

void setup() {
  
  Serial.begin(9600);
  strip.begin();
  strip.show();
  
}

void loop() {

  initTwinkle();
  twinkle();
  
  for (int i=0; i<=pixels; i++) {
    strip.setPixelColor(i, colorArray[i]);
  }
  strip.show();

  delay(1000);
  displayLetter('R');
  displayLetter('I');
  displayLetter('G');
  displayLetter('H');
  displayLetter('T');
  delay(wait * 2);
  displayLetter('H');
  displayLetter('E');
  displayLetter('R');
  displayLetter('E');
  
}

void clearDisplay() {
  for (int i=0; i<=pixels; i++) {
    strip.setPixelColor(i, 0,0,0);
  }
  strip.show();
  }

void displayLetter(int letter) {
  clearDisplay();
 
  int dletter = letter - 65;
  
  if (letter == 73) {dletter = 16;} //I
  if (letter == 74) {dletter = 15;} //J
  if (letter == 75) {dletter = 14;} //K
  if (letter == 76) {dletter = 13;} //L
  if (letter == 77) {dletter = 12;} //M
  if (letter == 78) {dletter = 11;} //N
  if (letter == 79) {dletter = 10;} //O
  if (letter == 80) {dletter = 9;} //P
  if (letter == 81) {dletter = 8;} //Q
  
  strip.setPixelColor(dletter, colorArray[dletter]);
  strip.show();
  delay(wait);
  strip.setPixelColor(dletter, 0,0,0);
  strip.show();
}

void twinkle() {
  for(int i=0;i<=1000;i++) {
    if (random(20) == 1) {
      uint16_t i = random(redPixels);
      if (redStates[i] < 1 ) {
        redStates[i] = random(256);
      }
    }
    for(uint16_t l = 0; l < pixels; l++) {
      if (redStates[l] > 1 ) {
        strip.setPixelColor(l+26, redStates[l], 0, 0);
        
        if (redStates[l] > 1) {
          redStates[l] = redStates[l] * fadeRate;
        } else {
          redStates[l] = 0;
        }
         strip.show();
    delay(5);
  }
}
  }
}

void initTwinkle() {
  for (int i=0; i<=redPixels; i++) {
    
    redStates[i] = 2;
  }
}

