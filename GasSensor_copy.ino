#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int sensorpin = A0;
int ledpin = 4;
int relay = 5;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  pinMode(ledpin, OUTPUT);
  pinMode(relay, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("System Loading");
  delay(30000);

  lcd.clear();
}

void loop() {

  int sensorValue = analogRead(sensorpin);

  // Adjust these values after testing your MQ-135
  sensorValue = constrain(sensorValue, 250, 800);

  int perc = map(sensorValue, 250, 800, 0, 100);

  if (perc > 65) {
    digitalWrite(ledpin, HIGH);
    digitalWrite(relay, HIGH);
  }
  else {
    digitalWrite(ledpin, LOW);
    digitalWrite(relay, LOW);
  }

  lcd.setCursor(0,0);
  lcd.print("Gas Level:");

  lcd.setCursor(0,1);
  lcd.print("    ");      // Clear old value
  lcd.setCursor(0,1);
  lcd.print(perc);
  lcd.print("%");

  delay(1000);
}