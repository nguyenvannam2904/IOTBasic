#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);

void blink(String word, int x, int y) {
  lcd.setCursor(x, y);
  lcd.print(word);
  delay(500);
  for(int i=0; i<word.length(); i++){
      lcd.setCursor(x, y);
      lcd.print(" ");
      x++; 
  }  
  delay(500);
}

void Countdown() {
  for (int i = 0; i >= 0; i--) {
    lcd.setCursor(3, 1);
    lcd.print(i);
    lcd.setCursor(4, 1);
    lcd.print(":");
    for (int j = 5; j >= 0; j--) {
      lcd.setCursor(5, 1);
      lcd.print(j);
      for (int k = 9; k >= 0; k--) {
        lcd.setCursor(6, 1);
        lcd.print(k);
        lcd.setCursor(7, 1);
        lcd.print(":");
        for (int l = 9; l >= 0; l--) {
          lcd.setCursor(8, 1);
          lcd.print(l);
          delay(100);
        }
      }
    }
  }
}
void countNumber() {
  for (int i = 0; i < 10; i++) {
    lcd.setCursor(2, 0);
    lcd.print(i);
    for (int j = 0; j < 10; j++) {
      lcd.setCursor(3, 0);
      lcd.print(j);
      for (int k = 0; k < 10; k++) {
        lcd.setCursor(4, 0);
        lcd.print(k);
        delay(1000);
      }
    }
  }
}


void Timer() {
  for (int i = 0; i < 10; i++) {
    lcd.setCursor(2, 1);
    lcd.print(i);
    lcd.setCursor(3, 1);
    lcd.print(":");
    for (int j = 0; j < 6; j++) {
      lcd.setCursor(4, 1);
      lcd.print(j);
      for (int k = 0; k < 10; k++) {
        lcd.setCursor(5, 1);
        lcd.print(k);
        lcd.setCursor(6, 1);
        lcd.print(":");
        for (int l = 0; l < 10; l++) {
          lcd.setCursor(7, 1);
          lcd.print(l);
          delay(100);
        }
      }
    }
  }
}

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("COUNTDOWN");
  Countdown();
}

void loop() {
  lcd.setCursor(2,0);
  lcd.print("Time's up!");
  blink("0:00:0", 3, 1);
}