#include <ESP8266WiFi.h>
#include <espnow.h>

int button = D5;
// REPLACE WITH RECEIVER MAC Address-----------------------------------------------------
uint8_t broadcastAddress[] = { 0x44, 0x17, 0x93, 0x15, 0x09, 0x29 };

// Set your Board ID
#define BOARD_ID 6

// Structure example to send data
// Must match the receiver structure
typedef struct struct_message {
  int id;
} struct_message;

// Create a struct_message called test to store variables to be sent
struct_message myData;

// Callback when data is sent
void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus) {
}
void setup() {
  pinMode(button, INPUT_PULLUP);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  // Init ESP-NOW
  if (esp_now_init() != 0) {
  }
  // Set ESP-NOW role
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  // Once ESPNow is successfully init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_register_send_cb(OnDataSent);
  // Register peer
  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
}

void loop() {
  int oldStatus = digitalRead(button);
  delay(50);
  if (digitalRead(button) == 0 && oldStatus == 1) {
    delay(50);
    myData.id = BOARD_ID;
    esp_now_send(0, (uint8_t *)&myData, sizeof(myData));
  }
}