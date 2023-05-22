
int pinLED[] = { 2, 3, 4, 5, 6, 7, 8, 9 };
// tương ứng với index 0,1,2,3,4,5,6,7

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(pinLED[i], OUTPUT);
  }
}

void loop() {

  linearON();
  linearOFF();
  resetLED();
  delay(500);
  //////////////////////
  blinkLED();
  blinkLED();
  blinkLED();
  blinkLED();
  resetLED();
  delay(500);
  //////////////////////
  runLEDFromLeftToRight();
  resetLED();
  delay(500);
  //////////////////////
  runLEDFromRightToLeft();
  resetLED();
  delay(500);
  //////////////////////
  stepbystepLED();
  stepbystepLED();
  stepbystepLED();
  stepbystepLED();
  resetLED();
  delay(500);
}

void resetLED() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(pinLED[i], LOW);
  }
}

void linearON() {
  // Bật tuần tự các đèn LED sáng dồn
  for (int i = 0; i < 8; i++) {
    digitalWrite(pinLED[i], HIGH);  //Bật đèn
    delay(500);                     // Dừng để các đèn LED sáng dần
  }
}

void linearOFF() {
  //Tắt tuần tự các đèn LED sáng dồn
  for (int i = 0; i < 8; i++) {
    digitalWrite(pinLED[i], LOW);  // Tắt đèn
    delay(500);                    // Dừng để các đèn LED tắt dần
  }
}

void blinkLED() {
  // Cả 8 đèn nhấp nháy liên tục
  for (int i = 0; i < 8; i++) {
    digitalWrite(pinLED[i], LOW);  // Tắt đèn
  }
  delay(500);
  for (int i = 0; i < 8; i++) {
    digitalWrite(pinLED[i], HIGH);  // Tắt đèn
  }
  delay(500);
}

void runLEDFromLeftToRight() {
  digitalWrite(pinLED[7], LOW);
  // Bật tuần tự LED cá nhân từ trái sang phải
  for (int i = 0; i < 8; i++) {
    digitalWrite(pinLED[i], HIGH);  //Bật đèn
    digitalWrite(pinLED[i - 1], LOW);
    delay(500);  // Dừng để các đèn LED sáng dần
  }
}

void runLEDFromRightToLeft() {
  // Bật tuần tự LED cá nhân từ phải sang trái
  digitalWrite(pinLED[0], LOW);
  for (int i = 7; i >= 0; i--) {
    digitalWrite(pinLED[i + 1], LOW);  //Bật đèn
    digitalWrite(pinLED[i], HIGH);
    delay(500);  // Dừng để các đèn LED sáng dần
  }
}

void stepbystepLED() {
  // Điều khiển LED sáng xen kẽ
  for (int i = 0; i < 8; i++) {
    if (i % 2 == 0) { digitalWrite(pinLED[i], HIGH); }
    if (i % 2 == 1) { digitalWrite(pinLED[i], LOW); }
  }
  delay(200);
  for (int i = 0; i < 8; i++) {
    if (i % 2 == 0) { digitalWrite(pinLED[i], LOW); }
    if (i % 2 == 1) { digitalWrite(pinLED[i], HIGH); }
  }
  delay(200);
}
