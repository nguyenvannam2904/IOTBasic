int pin = 0;    // D3
int relay = 2;  // D4
int newValue;
int oldValue = 1;
int state = 0;
int ThermistorPin = A0;


void setup() {
  Serial.begin(9600);
  pinMode(pin, INPUT);  // declare push button as input
  delay(2000);
  pinMode(relay, OUTPUT);
  delay(2000);
  digitalWrite(relay, HIGH);
}

double Thermistor(int RawADC) {
  double Temp;
  Temp = log(10000.0 * RawADC / (1024 - RawADC));
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp)) * Temp);
  Temp = Temp - 273.15;
  return Temp;
}

void buttonSwitch() {
  if (newValue == 1 && oldValue == 0) {
    if (state == 0) {
      digitalWrite(relay, LOW);
      state = 1;
    } else {
      digitalWrite(relay, HIGH);
      state = 0;
    }
  }
  oldValue = newValue;
}

void loop() {
  newValue = digitalRead(pin);
  int readVal = analogRead(ThermistorPin);

  buttonSwitch();
  double temp = Thermistor(readVal);

  if (temp > 30) {
    state = 0;
    digitalWrite(relay, HIGH);
  }
  Serial.println(state);
  Serial.println(temp);
  delay(100);
}