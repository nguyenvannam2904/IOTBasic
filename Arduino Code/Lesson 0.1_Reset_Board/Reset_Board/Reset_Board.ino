#include <avr/wdt.h>

void setup() {
}

void loop() {
  wdt_enable(WDTO_60MS);
  while (1) {}

}
