#include <arduinoFFT.h>
#include <LiquidCrystal_I2C.h>
#include <avr/wdt.h>

#define SAMPLES 128                  //SAMPLES-pt FFT. Must be a base 2 number. Max 128 for Arduino Uno.
#define SAMPLING_FREQUENCY 4434.922  //Ts = Based on Nyquist, must be 2 times the highest expected frequency. // 2*2217.461(C#7 note)
LiquidCrystal_I2C lcd(0x27, 16, 2);
arduinoFFT FFT = arduinoFFT();

unsigned int samplingPeriod;
unsigned long microSeconds;

double vReal[SAMPLES];  //create vector of size SAMPLES to hold real values
double vImag[SAMPLES];  //create vector of size SAMPLES to hold imaginary values
const char* noteLS[12] = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };
const char* noteLF[12] = { "C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab", "A", "Bb", "B" };
const char* noteWS[12] = { "Do", "Do#", "Re", "Re#", "Mi", "Fa", "Fa#", "Sol", "Sol#", "La", "La#", "Si" };
const char* noteWF[12] = { "Do", "Re(b)", "Re", "Mi(b)", "Mi", "Fa", "Sol(b)", "Sol", "La(b)", "La", "Si(b)", "Si" };

float getLoudness() {
  unsigned int sample;
  unsigned long startMillis = millis();  // Start of sample window
  float peakToPeak = 0;                  // peak-to-peak level
  unsigned int signalMax = 0;            //minimum value
  unsigned int signalMin = 1024;         //maximum value
  // collect data for 50 mS
  while (millis() - startMillis < 50) {
    sample = analogRead(A0);  //get reading from microphone
    if (sample < 1024)        // toss out spurious readings
    {
      if (sample > signalMax) {
        signalMax = sample;  // save just the max levels
      } else if (sample < signalMin) {
        signalMin = sample;  // save just the min levels
      }
    }
  }
  return peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
  delay(100);
}

void outPrintNote(double NOTE_INPUT) {
  String printNote = "Note: ";
  String frequency = "Freq: ";
  int a = (int)(((log10(NOTE_INPUT / 16.35)) / (log10(1.059463094))));  // 16.35 is frequency of C0 note, 1.0594... is same as 2^(1/12)
  int b = a % 12;
  int c = (a - b) / 12;
  if (digitalRead(8) == 0 && digitalRead(9) == 0) {
    printNote = printNote + noteLS[b] + c + "            ";
  }
  if (digitalRead(8) == 0 && digitalRead(9) == 1) {
    printNote = printNote + noteLF[b] + c + "            ";
  }
  if (digitalRead(8) == 1 && digitalRead(9) == 0) {
    printNote = printNote + noteWS[b] + c + "            ";
  }
  if (digitalRead(8) == 1 && digitalRead(9) == 1) {
    printNote = printNote + noteWF[b] + c + "            ";
  }
  frequency = frequency + NOTE_INPUT + "Hz  ";
  lcd.setCursor(0, 0);
  lcd.print(printNote);
  lcd.setCursor(0, 1);
  lcd.print(frequency);
}

double getFrequency() {
  double peak = 0;
  /*Sample SAMPLES times*/
  for (int i = 0; i < SAMPLES; i++) {
    microSeconds = micros();   //Returns the number of microseconds since the Arduino board began running the current script
    vReal[i] = analogRead(0);  //Reads the value from analog pin   0 (A0), quantize it and save it as a real term.
    vImag[i] = 0;              //Makes imaginary term 0 always
    /*remaining wait time between samples if necessary*/
    while (micros() < (microSeconds + samplingPeriod)) {
    }
  }
  /*Perform FFT on samples*/
  FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
  FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD);
  FFT.ComplexToMagnitude(vReal, vImag, SAMPLES);
  /*Find peak frequency and print peak*/
  return peak = FFT.MajorPeak(vReal, SAMPLES, SAMPLING_FREQUENCY);
}

void setup() {
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
  samplingPeriod = int(1000000 / SAMPLING_FREQUENCY);  //Period in microseconds
}

void loop() {
  float loudness = getLoudness();
  if (loudness > 70) {
    double peak = getFrequency();
    outPrintNote(peak/1.03);  // adjust accuracy
    wdt_reset();
  } else {
    lcd.setCursor(0, 1);
    lcd.print("Sound too small!");
  }
}
