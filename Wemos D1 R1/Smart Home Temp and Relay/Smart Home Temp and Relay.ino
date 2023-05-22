
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLUbJmzVSo"
#define BLYNK_DEVICE_NAME "Smart home Test"

#define BLYNK_FIRMWARE_VERSION "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG
#define APP_DEBUG
#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"
// define the GPIO connected with Relays and switches
#define RelayPin1 D5
#define SwitchPin1 D3

int ThermistorPin = A0;
int RawADC;
double Temp;
int newValue;
int oldValue = 1;
int state_manual;
int temp_setter;
bool value;
BlynkTimer timer;


BLYNK_WRITE(V0) {
  bool value = param.asInt();
  // Check these values and turn the relay2 ON and OFF
  if (value == 1) {
    digitalWrite(RelayPin1, HIGH);
    state_manual = !value;
  } else {
    digitalWrite(RelayPin1, LOW);
    state_manual = !value;
  }
}

void manual_switch() {
  newValue = digitalRead(SwitchPin1);
  if (newValue == 1 && oldValue == 0) {
    if (state_manual == 0) {
      digitalWrite(RelayPin1, LOW);
      Blynk.virtualWrite(V0, state_manual);
      state_manual = 1;
    } else {
      digitalWrite(RelayPin1, HIGH);
      Blynk.virtualWrite(V0, state_manual);
      state_manual = 0;
    }
  }
  oldValue = newValue;
}

void sendSensor() {
  RawADC = analogRead(ThermistorPin);
  Temp = log(10000.0 * RawADC / (1024 - RawADC));
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp)) * Temp);
  Temp = Temp - 273.15;
  Blynk.virtualWrite(V1, Temp);
}


BLYNK_WRITE(V2) {
  temp_setter = param.asInt();
  Serial.println(temp_setter);
}

void setup() {
  Serial.begin(9600);
  pinMode(RelayPin1, OUTPUT);
  pinMode(SwitchPin1, INPUT);
  BlynkEdgent.begin();
  delay(2000);
  digitalWrite(RelayPin1, LOW);
  timer.setInterval(1000L, sendSensor);
}

void loop() {
  BlynkEdgent.run();
  timer.run();
  manual_switch();

  if (temp_setter != 0 && Temp > temp_setter) {
    digitalWrite(RelayPin1, LOW);
    Blynk.virtualWrite(V0, 0);
  }
}