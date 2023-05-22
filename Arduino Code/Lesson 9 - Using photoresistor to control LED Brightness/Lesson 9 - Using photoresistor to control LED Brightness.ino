int led = 11;
int value = 0;


void setup() {
  Serial.begin(9600);
}
void loop() {
  value = analogRead(A2);
  Serial.println(value, DEC);  // light intensity, LOW value = BRIGHT environment, HIGH value = DARK environment
  // value range on 0-1023

  int valueLED = map(value, 0, 1023, 0, 255);  // due to the fact that PWM range from 0-255, so we have to convert it
  analogWrite(led, valueLED);
  delay(100);
}