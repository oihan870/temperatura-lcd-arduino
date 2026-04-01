#include <LiquidCrystal.h>
#include "DHT.h"

LiquidCrystal lcd(12, 11, 6, 5, 4, 3);

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  dht.begin();
  lcd.begin(16, 2);
  lcd.clear();
  Serial.begin(9600);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    lcd.setCursor(0, 0);
    lcd.print("Error DHT      ");
    lcd.setCursor(0, 1);
    lcd.print("               ");
    delay(2000);
    return;
  }

 lcd.setCursor(0, 0);
  lcd.print("H: ");
  lcd.print(h);
  lcd.print(" %     ");  // espacios para borrar restos

  lcd.setCursor(0, 1);
  lcd.print("T: ");
  lcd.print(t);
  lcd.print(" C     ");

  Serial.print(t);
  Serial.println(h);


  delay(2000);
}
