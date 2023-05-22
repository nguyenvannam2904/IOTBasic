#include <Key.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4;
const byte COLS = 4;


char hexaKeys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
String input;
String baseFrom;
String baseTo;

bool isBaseContainAlpha(String test) {
  for (int p = 0; p < test.length(); p++) {
    if (isAlpha(test[p]) == true) return true;
  }
  return false;
}

bool is01orNull(String test) {
  if (isBaseContainAlpha(test)) return false;
  else return (test.toInt() == 1 || test.toInt() == 0 || test == "");
}

bool isOnlyFrom0to9(String test) {
  for (int p = 0; p < test.length(); p++) {
    if (isDigit(test[p]) == false) return false;
  }
  return true;
}

bool isOnly0or1(String test) {
  for (int p = 0; p < test.length(); p++) {
    if (test[p] > '1' || test[p] < '0') return false;
  }
  return true;
}


void inputBaseFrom() {
  while (true) {
    baseFrom = "";
    char d = ' ';
    int i = 2;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter base from: ");
    while (d != '#') {
      lcd.setCursor(i, 1);
      d = customKeypad.waitForKey();
      if (d == '*' && i > 2) {
        baseFrom.remove(baseFrom.length() - 1);
        i--;
        lcd.setCursor(2, 1);
        lcd.print("                ");
        lcd.setCursor(2, 1);
        lcd.print(baseFrom);
      } else if (d == '*' && i == 2) {
      } else {
        baseFrom += d;
        lcd.print(d);
        i++;
      }
    }
    baseFrom.remove(baseFrom.length() - 1);

    if (isBaseContainAlpha(baseFrom)) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ERR: Letter");
      lcd.setCursor(0, 1);
      lcd.print("Please reinput");
      delay(2000);
    } else if (is01orNull(baseFrom)) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ERR: 0/1/NULL");
      lcd.setCursor(0, 1);
      lcd.print("Please reinput");
      delay(2000);
    } else if (is01orNull(baseFrom) == false && isBaseContainAlpha(baseFrom) == false) break;
  }
}

void inputNumber() {
  while (true) {
    char c = ' ';
    lcd.clear();
    input = "";
    lcd.setCursor(0, 0);
    lcd.print("Enter input: ");
    int i = 2;
    while (c != '#') {
      lcd.setCursor(i, 1);
      c = customKeypad.waitForKey();
      if (c == '*' && i > 2) {
        input.remove(input.length() - 1);
        i--;
        lcd.setCursor(2, 1);
        lcd.print("                ");
        lcd.setCursor(2, 1);
        lcd.print(input);
      } else if (c == '*' && i == 2) {
      } else {
        input += c;
        lcd.print(c);
        i++;
      }
    }
    input.remove(input.length() - 1);

    if (baseFrom.toInt() == 2 && isOnly0or1(input) == false) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("0 or 1 (base 2)");
      lcd.setCursor(0, 1);
      lcd.print("Please reinput");
      delay(2000);
    }

    if (baseFrom.toInt() > 2 && baseFrom.toInt() < 11 && isOnlyFrom0to9(input) == false) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Only from 0->9");
      lcd.setCursor(0, 1);
      lcd.print("Please reinput");
      delay(2000);
    }

    if (is01orNull(input)) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ERR: 0/1/NULL");
      lcd.setCursor(0, 1);
      lcd.print("Please reinput");
      delay(2000);
    }

    if (
      (baseFrom.toInt() == 2 && isOnly0or1(input) == true && is01orNull(input) == false) || (baseFrom.toInt() > 2 && baseFrom.toInt() < 11 && isOnlyFrom0to9(input) == true && is01orNull(input) == false)
      || (baseFrom.toInt() > 10)) break;
  }
}



void inputBaseTo() {
  while (true) {
    baseTo = "";
    char e = ' ';
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter base to: ");
    int i = 2;
    while (e != '#') {
      lcd.setCursor(i, 1);
      e = customKeypad.waitForKey();
      if (e == '*' && i > 2) {
        baseTo.remove(baseTo.length() - 1);
        i--;
        lcd.setCursor(2, 1);
        lcd.print("                ");
        lcd.setCursor(2, 1);
        lcd.print(baseTo);
      } else if (e == '*' && i == 2) {
      } else {
        baseTo += e;
        lcd.print(e);
        i++;
      }
    }
    baseTo.remove(baseTo.length() - 1);
    if (isBaseContainAlpha(baseTo)) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ERR: Letter");
      lcd.setCursor(0, 1);
      lcd.print("Please reinput");
      delay(2000);
    } else if (is01orNull(baseTo)) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ERR: 0/1/NULL");
      lcd.setCursor(0, 1);
      lcd.print("Please reinput");
      delay(2000);
    } else if (is01orNull(baseTo) == false && isBaseContainAlpha(baseTo) == false) break;
  }
}
int chartoInt(char into) {
  if (into >= '0' && into <= '9') {
    return (int)into - '0';
  } else {
    return (int)(toupper(into)) - 'A' + 10;
  }
}
char inttoChar(int num) {
  if (num >= 0 && num <= 9)
    return (char)(num + '0');
  else
    return (char)(num - 10 + 'A');
}
String reverseStr(String str) {
  char rev[str.length()];
  String temp = "";
  for (int index = 0, len = str.length(); (index < len); index++) {
    rev[index] = str[len - 1 - index];
    temp += rev[index];
  }
  return temp;
}

String baseConverter(String input, int baseFrom, int baseTo) {
  long decimal = 0;
  long power = 1;
  for (int i = input.length() - 1; i >= 0; i--) {
    decimal += chartoInt(input.charAt(i)) * power;
    power = power * baseFrom;
  }
  String s = "";
  while (decimal > 0) {
    s += inttoChar(decimal % baseTo);
    decimal /= baseTo;
  }
  String temp = reverseStr(s);
  return temp;
}

void baseConverterCalc() {
  inputBaseFrom();
  inputNumber();
  inputBaseTo();

  int bFrom = (baseFrom.toInt());
  int bTo = (baseTo.toInt());
  String output = baseConverter(input, bFrom, bTo);
  input = input + "(" + baseFrom.toInt() + ")";
  output = output + "(" + baseTo.toInt() + ")";
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("IN: ");
  lcd.setCursor(4, 0);
  lcd.print(input);
  lcd.setCursor(0, 1);
  lcd.print("OUT: ");
  lcd.setCursor(5, 1);
  lcd.print(output);

  delay(10000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WANNA CONTINUE?");
  lcd.setCursor(0, 1);
  lcd.print("PRESS # TO STOP");
}

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(" WELCOME TO NEW");
  lcd.setCursor(0, 1);
  lcd.print(" BASE CONVERTER");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("* to BACKSPACE");
  lcd.setCursor(0, 1);
  lcd.print("# to ENTER");
  delay(5000);
  lcd.clear();
  baseConverterCalc();

  char isNext;
  isNext = customKeypad.waitForKey();
  while (isNext != '#') {
    baseConverterCalc();
    isNext = customKeypad.waitForKey();
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("    GOODBYE!");
  lcd.setCursor(1, 1);
  lcd.print("SEE YOU AGAIN!");
  delay(5000);
  lcd.clear();
  lcd.noBacklight();
}

void loop() {
}
