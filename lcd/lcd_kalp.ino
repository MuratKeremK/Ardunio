#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
byte kalp [8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};
void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, kalp);
  lcd.setCursor(0,0);
  lcd.write(byte(0));
}

void loop() {
  

}
