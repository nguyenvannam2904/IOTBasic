/*
 * This program is property of SME Dehradun. for any query related to this program, contact us at www.smedehradn.com
 * if your want any soluiton related for any IoT Customized Boards and Sensor to www.nuttyengineer.com 
 */
// Fill-in information from your Blynk Template here

#define BLYNK_TEMPLATE_ID "TMPLUbJmzVSo"
#define BLYNK_TEMPLATE_NAME "Smart home Test"
#define BLYNK_FIRMWARE_VERSION "0.1.0"

#define BLYNK_PRINT Serial
#define USE_NODE_MCU_BOARD

#include "BlynkEdgent.h"

int analogInPin = A0;
float sensorValue, temp;
BlynkTimer timer;

void sendSensor() {
  sensorValue = analogRead(analogInPin);
  temp = (sensorValue / 1023.0) * 330; // lưu ý: Analog ở nodeMCU chạy ở mức 3.3V
  Serial.println(temp);
  Blynk.virtualWrite(V1, temp);
}

void setup() {
  Serial.begin(115200);
  delay(100);
  BlynkEdgent.begin();
  delay(2000);
  timer.setInterval(1000L, sendSensor);
}

void loop() {
  BlynkEdgent.run();
  timer.run();  // Initiates SimpleTimer
}
