// define led pin is 5 and interrupt pin is 0, that mean we will use pin 2 for interrupt
const int ledPin = 5, button = 2;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

  // setup for interrupt 0 with rising mode; ISR is blink function.
  attachInterrupt(digitalPinToInterrupt(button), blink, HIGH);
}

void loop() {
  Serial.println("1");
  digitalWrite(ledPin, !digitalRead(ledPin));
  delay(1000);
}

void blink() {
  digitalWrite(ledPin, LOW);  // Toggle LED on/off if interrupt happen.
  Serial.println("Button Pressed");
}
