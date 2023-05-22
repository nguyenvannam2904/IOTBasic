const int PIN_DOT = 2;
const int PIN_A = 3;
const int PIN_B = 4;
const int PIN_C = 5;
const int PIN_D = 6;
const int PIN_E = 7;
const int PIN_F = 8;
const int PIN_G = 9;
const int LED_1 = 10;
const int LED_2 = 11;
const int LED_3 = 12;
const int LED_4 = 13;
unsigned char led7HEX[] = { 0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xD8, 0x80, 0x90};

void LED_NumWrite(unsigned char b) {
  // Đọc PIN_A phép OR BITWISE với 0xFE (11111110), nếu ra (11111110) thì bật đèn (LOW)
  if (((b >> 0) | 0xFE) == 0xFE) {
    digitalWrite(PIN_A, LOW);
  } else {
    digitalWrite(PIN_A, HIGH);
  }

  // Đọc PIN_B phép OR BITWISE với 0xFE (11111110), nếu ra (11111110) thì bật đèn (LOW)
  if (((b >> 1) | 0xFE) == 0xFE) {
    digitalWrite(PIN_B, LOW);
  } else {
    digitalWrite(PIN_B, HIGH);
  }

  // Đọc PIN_C phép OR BITWISE với 0xFE (11111110), nếu ra (11111110) thì bật đèn (LOW)
  if (((b >> 2) | 0xFE) == 0xFE) {
    digitalWrite(PIN_C, LOW);
  } else {
    digitalWrite(PIN_C, HIGH);
  }

  // Đọc PIN_D phép OR BITWISE với 0xFE (11111110), nếu ra (11111110) thì bật đèn (LOW)
  if (((b >> 3) | 0xFE) == 0xFE) {
    digitalWrite(PIN_D, LOW);
  } else {
    digitalWrite(PIN_D, HIGH);
  }

  // Đọc PIN_E phép OR BITWISE với 0xFE (11111110), nếu ra (11111110) thì bật đèn (LOW)
  if (((b >> 4) | 0xFE) == 0xFE) {
    digitalWrite(PIN_E, LOW);
  } else {
    digitalWrite(PIN_E, HIGH);
  }

  // Đọc PIN_F phép OR BITWISE với 0xFE (11111110), nếu ra (11111110) thì bật đèn (LOW)
  if (((b >> 5) | 0xFE) == 0xFE) {
    digitalWrite(PIN_F, LOW);
  } else {
    digitalWrite(PIN_F, HIGH);
  }

  // Đọc PIN_G phép OR BITWISE với 0xFE (11111110), nếu ra (11111110) thì bật đèn (LOW)
  if (((b >> 6) | 0xFE) == 0xFE) {
    digitalWrite(PIN_G, LOW);
  } else {
    digitalWrite(PIN_G, HIGH);
  }
}
void setup() {
  pinMode(PIN_DOT, OUTPUT);
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_C, OUTPUT);
  pinMode(PIN_D, OUTPUT);
  pinMode(PIN_E, OUTPUT);
  pinMode(PIN_F, OUTPUT);
  pinMode(PIN_G, OUTPUT);

  // Cấu hình led ra từng số
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
}

void loop() {
  
  for (int number = 100; number >=0; number--) {
    for (int j = 0; j < 25; j++) {
      digitalWrite(PIN_DOT, HIGH); // Đặt LED DOT ở trạng thái tắt
      digitalWrite(LED_1, HIGH); // Bật hiển thị led 1
      LED_NumWrite(led7HEX[number / 1000]);
      delay(1);
      digitalWrite(LED_1, LOW); // Tắt hiển thị led 1
      /////////////////////////////////////
      digitalWrite(LED_2, HIGH);
      LED_NumWrite(led7HEX[(number/100)%10]);
      delay(1);
      digitalWrite(LED_2, LOW);
      /////////////////////////////////////
      digitalWrite(LED_3, HIGH);
      LED_NumWrite(led7HEX[(number/10)%10]);
      digitalWrite(PIN_DOT, LOW); // bật LED DOT khi đến lượt bật của LED3
      delay(1);
      digitalWrite(LED_3, LOW);
      /////////////////////////////////////
      digitalWrite(LED_4, HIGH);
      LED_NumWrite(led7HEX[number%10]);
      digitalWrite(PIN_DOT, HIGH);
      delay(1);
      digitalWrite(LED_4, LOW);
      /////////////////////////////////////
    }
    // Như vậy sau 25 lần lặp * 4 led * 10ms delay, ta thu được 1s delay
  }
}
