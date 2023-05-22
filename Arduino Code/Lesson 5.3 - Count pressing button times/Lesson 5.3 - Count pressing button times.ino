const int buttonPin = 11;
const int ledPin = 2;

// Các biến này có thể thay đổi giá trị được
int buttonPushCounter = 0;  // số lần button được nhấn
int buttonState = 0;        // trạng thái hiện tại của button
int lastButtonState = 0;    // trạng thái trước đó của button

void setup() {
  pinMode(buttonPin, INPUT);  // Cài đặt button là INPUT
  pinMode(ledPin, OUTPUT);    // Cài đặt đèn LED là OUTPUT

  Serial.begin(9600);  //Bật cổng Serial ở baudrate 9600
}


void loop() {
  // đọc giá trị hiện tại của button
  buttonState = digitalRead(buttonPin);

  // so sánh với giá trị trước đó
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      // Nếu trạng thái bây giờ là button đang được nhấn
      // thì hiển nhiên trước đó là button chưa được nhấn (điều kiện trên)
      // chúng ta sẽ tăng số lần nhấn button lên 1
      buttonPushCounter++;
      Serial.println("Dang nhan");
      Serial.print("So lan nhan button la: ");
      Serial.println(buttonPushCounter);
    } else {
      // Nếu trạng thái bây giờ là button đang được THẢ
      // thì hiển nhiên trước đó là button đang được nhấn (điều kiện trên)
      // Chúng ta sẽ thông báo là button đang được thả và không làm gì cả
      Serial.println("off");
    }
  }
  // lưu lại trạng thái button cho lần kiểm tra tiếp theo
  lastButtonState = buttonState;

  // Sau cứ cách 4 lần nhấn thì bật đèn
  if (buttonPushCounter % 4 == 0) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
