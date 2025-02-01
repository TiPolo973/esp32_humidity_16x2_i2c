// Learn about the ESP32 WiFi simulation in
// https://docs.wokwi.com/guides/esp32-wifi

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTTYPE DHT22
#define width 16
#define height 2
#define i2c_addr 0x27

const int dht_pin = 33;

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(i2c_addr, width, height);

DHT dht(dht_pin, DHTTYPE);



void setup() {
  Serial.begin(115200);
  dht.begin();
}


void loop() {
  float humiditer = dht.readHumidity();
  float temperature = dht.readTemperature();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,1);
  lcd.print("Hum.. : ");
  lcd.print(humiditer);
  lcd.setCursor(1,0);
  lcd.print("Tem.. : ");
  lcd.print(temperature);
  delay(1000);
}
