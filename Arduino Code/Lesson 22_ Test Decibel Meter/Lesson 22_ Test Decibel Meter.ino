void setup() {
  Serial.begin(9600);
}

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
}