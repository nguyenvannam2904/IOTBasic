int val;
int tempPin = 0;

void setup() {
  Serial.begin(9600);
}
void loop() {
  val = analogRead(tempPin);
  float cel = (val / 1023.0) * 500;
  float farh = (cel * 9) / 5 + 32;

  Serial.print("TEMPRATURE = ");
  Serial.print(cel);
  Serial.print("*C");
  Serial.println();
  delay(500);

  /* uncomment this to get temperature in farenhite 
Serial.print("TEMPRATURE = ");
Serial.print(farh);
Serial.print("*F");
Serial.println();
*/
}
