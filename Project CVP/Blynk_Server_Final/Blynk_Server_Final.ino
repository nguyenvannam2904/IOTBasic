#define BLYNK_TEMPLATE_ID "TMPL6uqmXxB0-"
#define BLYNK_TEMPLATE_NAME "Olympeak Bell Competition"

#define BLYNK_FIRMWARE_VERSION "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"

void setup() {
  Serial.begin(9600);
  delay(1000);
  BlynkEdgent.begin();
}

String writeCandidate(int result) {
  String candidate = "";
  if (result == 0) {
    candidate = "..............";
  }
  if (result == 1) {
    candidate = "Phúc Bình";
  }
  if (result == 2) {
    candidate = "Hoàng Anh";
  }
  if (result == 3) {
    candidate = "Thái Sơn";
  }
  if (result == 4) {
    candidate = "Long Phi";
  }
  if (result == 5) {
    candidate = "Trọng Tuệ";
  }
  if (result == 6) {
    candidate = "Hữu Hải";
  }
  if (result == 7) {
    candidate = "Quang Tùng";
  }
  if (result == 8) {
    candidate = "Phương Nam";
  }
  return candidate;
}
void loop() {
  BlynkEdgent.run();
  String data;
  if (Serial.available()) {
    data = Serial.readStringUntil('\n');
    String candidate = writeCandidate(data.toInt());
    Blynk.virtualWrite(V0, candidate);
    if (data.toInt() != 0) {
      Blynk.virtualWrite(V0, candidate);
      Blynk.virtualWrite(V0, candidate);
      Blynk.virtualWrite(V0, candidate);
      Blynk.virtualWrite(V0, candidate);
    }
  }
}
