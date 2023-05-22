#include <IRremote.h>
const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
const int redPin = 10;
const int greenPin = 11;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
}
void loop() {
  controlLED();
}

void getHexSignalfromButton() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    delay(200);
    irrecv.resume();
  }
}

void getProtocolName() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    switch (results.decode_type) {
      case NEC: Serial.println("NEC"); break;
      case SONY: Serial.println("SONY"); break;
      case RC5: Serial.println("RC5"); break;
      case RC6: Serial.println("RC6"); break;
      case DISH: Serial.println("DISH"); break;
      case SHARP: Serial.println("SHARP"); break;
      case JVC: Serial.println("JVC"); break;
      case SANYO: Serial.println("SANYO"); break;
      case MITSUBISHI: Serial.println("MITSUBISHI"); break;
      case SAMSUNG: Serial.println("SAMSUNG"); break;
      case LG: Serial.println("LG"); break;
      case PANASONIC: Serial.println("PANASONIC"); break;
      default:
      case UNKNOWN: Serial.println("UNKNOWN"); break;
    }
    irrecv.resume();
  }
}

void controlLED() {
  if (irrecv.decode(&results)) {
    switch (results.value) {
      case 0xFFA25D:  //Keypad button "1"
        digitalWrite(redPin, HIGH);
        digitalWrite(greenPin, LOW);
    }
    switch (results.value) {
      case 0xFFE21D:  //Keypad button "3"
        digitalWrite(redPin, LOW);
        digitalWrite(greenPin, HIGH);
    }
    irrecv.resume();
  }
}
