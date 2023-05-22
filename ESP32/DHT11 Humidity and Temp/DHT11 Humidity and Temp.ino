#include <dht_nonblocking.h>


// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLc25SfGx_"
#define BLYNK_DEVICE_NAME "DHT11 HUMIDITY and  TEMPERATURE in 32"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
#define USE_ESP32S2_DEV_KIT // DOIT ESP32 DEVKIT V1

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
  dht.setup(15, DHTesp::DHT11); // connect to D15
  BlynkEdgent.begin();
  delay(2000);
  timer.setInterval(dht.getMinimumSamplingPeriod(), sendSensor);
}

void loop() {
  BlynkEdgent.run();
  timer.run();  // Initiates SimpleTimer
}

