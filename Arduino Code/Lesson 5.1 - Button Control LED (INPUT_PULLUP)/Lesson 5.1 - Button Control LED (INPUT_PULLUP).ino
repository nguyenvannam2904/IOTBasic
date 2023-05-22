void setup() {
  // khởi động cổng Serial ở baudrate 9600
  Serial.begin(9600);
  // Cài đặt các chân digital
  pinMode(8, INPUT_PULLUP);  //INPUT_PULLUP chân button
  pinMode(3, OUTPUT);        // OUTPUT chân led
}

void loop() {
  //đọc tín hiệu chân digital
  int sensorVal = digitalRead(8);

    if (sensorVal == HIGH) {  //nếu chưa nhấn, ở INPUT_PULLUP thì nếu chưa nhấn trạng thái là HIGH, còn đã nhấn là số LOW
    digitalWrite(3, LOW);  // tắt đèn
    Serial.println("UNPRESSED");
  }
  else {                    // nếu đã nhấn
    digitalWrite(3, HIGH);  // bật đèn
    Serial.println("PRESSED");
  }

  delay(500);
}
