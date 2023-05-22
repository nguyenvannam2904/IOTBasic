byte led1 = 5;
byte led2 = 6;
unsigned long time1 = 0;
unsigned long time2 = 0;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if ((unsigned long)(millis() - time1) > 2000) {
    if (digitalRead(led1) == LOW) {
      digitalWrite(led1, HIGH);
    } else {
      digitalWrite(led1, LOW);
    }
    time1 = millis();

  if ((unsigned long)(millis() - time2) > 1000) { 
    if (digitalRead(led2) == LOW) {
      digitalWrite(led2, HIGH);
    } else {
      digitalWrite(led2, LOW);
    }
    time2 = millis(); 
  }
}
}