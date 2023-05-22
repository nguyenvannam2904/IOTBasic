#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to LOAD(CS)
 pin 10 is connected to the CLK 
 We have only a single MAX72XX.
 */
LedControl lc = LedControl(12, 10, 11, 1);
byte ALL[] = { B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111 };
byte EX[] = { B00000000, B00010000, B00010000, B00010000, B00010000, B00000000, B00010000, B00000000 };
byte A[] = { B00000000, B00111100, B00100100, B00100100, B00111100, B00100100, B00100100, B00000000 };
byte B[] = { B01111000, B01001000, B01001000, B01110000, B01001000, B01000100, B01000100, B01111100 };
byte C[] = { B00000000, B00011110, B00100000, B01000000, B01000000, B01000000, B00100000, B00011110 };
byte D[] = { B00000000, B00111000, B00100100, B00100010, B00100010, B00100100, B00111000, B00000000 };
byte E[] = { B00000000, B00111100, B00100000, B00111000, B00100000, B00100000, B00111100, B00000000 };
byte F[] = { B00000000, B00111100, B00100000, B00111000, B00100000, B00100000, B00100000, B00000000 };
byte G[] = { B00000000, B00111110, B00100000, B00100000, B00101110, B00100010, B00111110, B00000000 };
byte H[] = { B00000000, B00100100, B00100100, B00111100, B00100100, B00100100, B00100100, B00000000 };
byte I[] = { B00000000, B00111000, B00010000, B00010000, B00010000, B00010000, B00111000, B00000000 };
byte J[] = { B00000000, B00011100, B00001000, B00001000, B00001000, B00101000, B00111000, B00000000 };
byte K[] = { B00000000, B00100100, B00101000, B00110000, B00101000, B00100100, B00100100, B00000000 };
byte L[] = { B00000000, B00100000, B00100000, B00100000, B00100000, B00100000, B00111100, B00000000 };
byte M[] = { B00000000, B00000000, B01000100, B01101100, B01010100, B01000100, B01000100, B00000000 };
byte N[] = { B00000000, B00100010, B00110010, B00101010, B00100110, B00100010, B00000000, B00000000 };
byte O[] = { B00000000, B00111100, B01000010, B01000010, B01000010, B01000010, B00111100, B00000000 };
byte P[] = { B00000000, B00111000, B00100100, B00100100, B00111000, B00100000, B00100000, B00000000 };
byte Q[] = { B00000000, B00111100, B01000010, B01000010, B01000010, B01000110, B00111110, B00000001 };
byte R[] = { B00000000, B00111000, B00100100, B00100100, B00111000, B00100100, B00100100, B00000000 };
byte S[] = { B00000000, B00111100, B00100000, B00111100, B00000100, B00000100, B00111100, B00000000 };
byte T[] = { B00000000, B01111100, B00010000, B00010000, B00010000, B00010000, B00010000, B00000000 };
byte U[] = { B00000000, B01000010, B01000010, B01000010, B01000010, B00100100, B00011000, B00000000 };
byte V[] = { B00000000, B00100010, B00100010, B00100010, B00010100, B00010100, B00001000, B00000000 };
byte W[] = { B00000000, B10000010, B10010010, B01010100, B01010100, B00101000, B00000000, B00000000 };
byte X[] = { B00000000, B01000010, B00100100, B00011000, B00011000, B00100100, B01000010, B00000000 };
byte Y[] = { B00000000, B01000100, B00101000, B00010000, B00010000, B00010000, B00010000, B00000000 };
byte Z[] = { B00000000, B00111100, B00000100, B00001000, B00010000, B00100000, B00111100, B00000000 };



void displayLetter(byte a[]) {
  lc.setRow(0, 0, a[0]);
  lc.setRow(0, 1, a[1]);
  lc.setRow(0, 2, a[2]);
  lc.setRow(0, 3, a[3]);
  lc.setRow(0, 4, a[4]);
  lc.setRow(0, 5, a[5]);
  lc.setRow(0, 6, a[6]);
  lc.setRow(0, 7, a[7]);
}

/*
 This method will display the characters for the
 word "Arduino" one after the other on the matrix. 
 (you need at least 5x7 leds to see the whole chars)
 */
void writeArduinoOnMatrix() {
  displayLetter(A);
  delay(500);
  displayLetter(B);
  delay(500);
  displayLetter(C);
  delay(500);
  displayLetter(D);
  delay(500);
  displayLetter(E);
  delay(500);
  displayLetter(F);
  delay(500);
  displayLetter(G);
  delay(500);
  displayLetter(H);
  delay(500);
  displayLetter(I);
  delay(500);
  displayLetter(J);
  delay(500);
  displayLetter(K);
  delay(500);
  displayLetter(L);
  delay(500);
  displayLetter(M);
  delay(500);
  displayLetter(N);
  delay(500);
  displayLetter(O);
  delay(500);
  displayLetter(P);
  delay(500);
  displayLetter(Q);
  delay(500);
  displayLetter(R);
  delay(500);
  displayLetter(S);
  delay(500);
  displayLetter(T);
  delay(500);
  displayLetter(U);
  delay(500);
  displayLetter(V);
  delay(500);
  displayLetter(W);
  delay(500);
  displayLetter(X);
  delay(500);
  displayLetter(Y);
  delay(500);
  displayLetter(Z);
  delay(500);
  displayLetter(EX);
  delay(500);
  displayLetter(ALL);
  delay(500);
}


void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0, false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0, 8);
  /* and clear the display */
  lc.clearDisplay(0);
}
void loop() {
  writeArduinoOnMatrix();
}