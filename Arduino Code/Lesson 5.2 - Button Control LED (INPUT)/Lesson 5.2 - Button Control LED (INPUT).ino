int button = 11;
int led = 2;
void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);  //Cài đặt chân D8 ở trạng thái đọc dữ liệu
  pinMode(led, OUTPUT);    // Cài đặt chân D3 dưới dạng OUTPUT
}

void loop() {
  int buttonStatus = digitalRead(button);  // Ở mode INPUT, nút đã nhấn có trạng thái HIGH, chưa nhấn là LOW, đối nghịch INPUT_PULLUP
  if (buttonStatus == HIGH) {              // Nếu mà button bị nhấn
    digitalWrite(led, HIGH);               // Đèn led sáng
    Serial.println("PRESSED");
  } else {  // ngược lại
    digitalWrite(led, LOW);
    Serial.println("UNPRESSED");
  }
  delay(500);
}