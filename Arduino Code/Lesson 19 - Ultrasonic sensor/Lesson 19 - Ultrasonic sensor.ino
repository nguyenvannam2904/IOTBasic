const unsigned int TRIG_PIN = 13;
const unsigned int ECHO_PIN = 12;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  const unsigned long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration / 34.3 / 2;
  if (duration == 0) {
    Serial.println("Warning: no pulse from sensor");
  } else {
    Serial.print("Distance to nearest object: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}
