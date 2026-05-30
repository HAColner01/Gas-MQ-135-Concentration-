#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

int sensorpin = A0;
int ledpin = 4;
int relay = 5;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup(){
  pinMode(ledpin, OUTPUT);
  pinMode(sensorpin, INPUT);
  pinMode(relay, OUTPUT);
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("System Loading....");
  delay(30000); // 30 sec startup
  lcd.clear();
}

void loop() {
  int sensorValue = analogRead(sensorpin);
  float perc = (sensorValue / 1023.0) * 100.0;

  if(perc > 65){
    digitalWrite(ledpin, HIGH);
    digitalWrite(relay, HIGH);
  } else {
    digitalWrite(ledpin, LOW);
    digitalWrite(relay, LOW);
  }

  // Display gas level
  lcd.setCursor(0,0);
  lcd.print("Gas is:        "); // clear old chars
  lcd.setCursor(0,1);
  lcd.print(perc,1);
  lcd.print("%");

  delay(1000); // update every 1 second
}