#include <ESP8266WiFi.h>
#include <espnow.h>

// Structure example to receive data
// Must match the sender structure
typedef struct struct_message {
  int id;
} struct_message;

int button = D5;
// Callback function that will be executed when data is received
void buzzBlynk() {
  digitalWrite(D6, HIGH);
  delay(100);
  digitalWrite(D6, LOW);
}

void buzzReset() {
  digitalWrite(D6, HIGH);
  delay(50);
  digitalWrite(D6, LOW);
  delay(50);
  digitalWrite(D6, HIGH);
  delay(50);
  digitalWrite(D6, LOW);
}
void buzzReceived() {
  digitalWrite(D6, HIGH);
  delay(1000);
  digitalWrite(D6, LOW);
}
void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
  pinMode(D6, OUTPUT);
  buzzBlynk();
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  // Init ESP-NOW
  if (esp_now_init() != 0) {
  }
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
}
struct_message myData;
boolean allowed = false;
int firstValue;

void OnDataRecv(uint8_t *mac_addr, uint8_t *incomingData, uint8_t len) {
  memcpy(&myData, incomingData, sizeof(myData));
  firstValue = myData.id;
}

void loop() {
  if (digitalRead(button) == 0) {
    Serial.println("0");
    buzzReset();
    allowed = true;
  }
  if (allowed == true) {
    firstValue = 0;
    esp_now_register_recv_cb(OnDataRecv);
    delay(30);
    if (firstValue != 0) {
      esp_now_unregister_recv_cb();
      allowed = false;
      Serial.println(firstValue);
      buzzReceived();
    }
  }
}