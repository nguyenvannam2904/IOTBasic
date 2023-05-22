void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(A5);  // value luôn nằm trong khoảng 0-1023 bởi Analog cung cấp giá trị từ 0 -> 2^10 - 1
  Serial.println(value);
  delay(200);
}