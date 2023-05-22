int button = 2;

void setup() {
  Serial.begin(9600);      //Mở cổng Serial ở baudrate 9600 để giao tiếp với máy tính
  pinMode(button, INPUT);  //Cài đặt chân D2 ở trạng thái đọc dữ liệu
}

void loop() {
  int buttonStatus = digitalRead(button);  //Đọc trạng thái button
  if (buttonStatus == 1) {
    Serial.println("PRESSED");
  }
  if (buttonStatus == 0) {
    Serial.println("UNPRESSED");
  }
  delay(500);  //Chờ 200ms
}