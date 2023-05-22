/*
 * This program is property of SME Dehradun. for any query related to this program, contact us at www.smedehradn.com
 * if your want any soluiton related for any IoT Customized Boards and Sensor to www.nuttyengineer.com 
 */
// Fill-in information from your Blynk Template here

#define BLYNK_TEMPLATE_ID "TMPLIusYLFFw"
#define BLYNK_DEVICE_NAME "DHT11 Humidity and Temperature Sensor"
#define BLYNK_FIRMWARE_VERSION "0.1.0"

#define BLYNK_PRINT Serial
#define USE_NODE_MCU_BOARD

#include "BlynkEdgent.h"
#include "DHTesp.h"
DHTesp dht;

BlynkTimer timer;
float t, h;

void sendSensor() {
  h = dht.getHumidity();
  t = dht.getTemperature();
  Blynk.virtualWrite(V0, h);
  Blynk.virtualWrite(V1, t);
}

void setup() {
  Serial.begin(115200);
  delay(100);
  dht.setup(14, DHTesp::DHT11); // connect to D5 - GPIO14
  BlynkEdgent.begin();
  delay(2000);
  timer.setInterval(dht.getMinimumSamplingPeriod(), sendSensor);
}

void loop() {
  BlynkEdgent.run();
  timer.run();  // Initiates SimpleTimer
}
