
int BLUE_PIN = 9;    // led xanh dương
int GREEN_PIN = 10;  // led xanh lá
int RED_PIN = 11;    // led đỏ
int DELAY_TIME = 1000;  


void setup() {
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
}

void loop() {
  displayAllBasicColors();
  delay(1000);
  showSpectrum();
}

void displayAllBasicColors() {
  // Tắt toàn bộ các led

  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);

  delay(DELAY_TIME);

  // Chỉ bật led đỏ

  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);

  delay(DELAY_TIME);

  // Chỉ bật led xanh lá

  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);

  delay(DELAY_TIME);

  // Chỉ bật led xanh dương

  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);

  delay(DELAY_TIME);

  // Bật màu vàng bắng cách bật led đỏ và xanh

  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);

  delay(DELAY_TIME);

  // Xanh lam (Cyan) bằng cách bật led xanh lá và xanh dương

  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);

  delay(DELAY_TIME);

  // Tím (đỏ + xanh dương)

  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);

  delay(DELAY_TIME);

  // Màu trắng (tất cả các led)

  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);

  delay(DELAY_TIME);
}

void showSpectrum() {

  for (int i = 0; i < 768; i++) {
    showRGB(i);  // Call RGBspectrum() with our new x
    delay(20);   // Delay 10ms
  }
}

void showRGB(int color) {
  int redPWM;
  int greenPWM;
  int bluePWM;



  if (color <= 255)  // phân vùng 1
  {
    redPWM = 255 - color;  // red đi từ sáng về tắt
    greenPWM = color;      // green đi từ tắt thành sáng
    bluePWM = 0;           // blue luôn tắt

  } else if (color <= 511)  // phân vùng 2
  {
    redPWM = 0;                      // đỏ luôn tắt
    greenPWM = 255 - (color - 256);  // green đi từ sáng về tắt
    bluePWM = (color - 256);         // blue đi từ tắt thành sáng
  } else                             // phân vùng 3 với color >= 512
  {
    redPWM = (color - 512);         // red tắt rồi lại sáng
    greenPWM = 0;                   // green luôn tắt nhé
    bluePWM = 255 - (color - 512);  // blue sáng rồi lại tắt
  }
  // Phát xung
  analogWrite(RED_PIN, redPWM);
  analogWrite(BLUE_PIN, bluePWM);
  analogWrite(GREEN_PIN, greenPWM);
}
