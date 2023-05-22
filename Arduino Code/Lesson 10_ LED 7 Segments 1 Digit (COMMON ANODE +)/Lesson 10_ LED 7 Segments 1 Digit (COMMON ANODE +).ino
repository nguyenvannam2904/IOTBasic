const int PIN_DOT = 2;
const int PIN_A = 3;
const int PIN_B = 4;
const int PIN_C = 5;
const int PIN_D = 6;
const int PIN_E = 7;
const int PIN_F = 8;
const int PIN_G = 9;
unsigned char led7HEX[] = { 0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xD8, 0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E };

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
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_C, OUTPUT);
  pinMode(PIN_D, OUTPUT);
  pinMode(PIN_E, OUTPUT);
  pinMode(PIN_F, OUTPUT);
  pinMode(PIN_G, OUTPUT);
}

void loop() {
  for (int i = 0; i < 16; i++) {
    LED_NumWrite(led7HEX[i]);
    delay(200);
  }
}
