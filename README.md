# ESP32 - Affichage Température et Humidité sur LCD I2C

## Description
Ce projet utilise un ESP32 pour mesurer la température et l'humidité à l'aide d'un capteur **DHT22** et affiche ces valeurs sur un écran **LCD I2C** (16x2). Les données sont rafraîchies toutes les secondes.

## Matériel requis
- ESP32
- Capteur **DHT22**
- Écran **LCD I2C 16x2** (adresse I2C : `0x27`)
- Câbles de connexion

## Schéma de connexion
| ESP32 | DHT22 | LCD I2C |
|-------|------|--------|
| 3.3V  | VCC  | VCC    |
| GND   | GND  | GND    |
| GPIO33 | DATA | -      |
| SDA (GPIO21) | - | SDA |
| SCL (GPIO22) | - | SCL |

## Installation des bibliothèques
Assurez-vous d'installer les bibliothèques suivantes dans l'IDE Arduino :

1. **DHT sensor library** (Adafruit)
2. **Adafruit Unified Sensor**
3. **LiquidCrystal I2C**

Pour installer ces bibliothèques, allez dans **Sketch** > **Inclure une bibliothèque** > **Gérer les bibliothèques...**, puis recherchez et installez chaque bibliothèque.

## Code source
```cpp
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
  lcd.init();
  lcd.backlight();
}

void loop() {
  float humiditer = dht.readHumidity();
  float temperature = dht.readTemperature();

  lcd.setCursor(0,1);
  lcd.print("Hum.. : ");
  lcd.print(humiditer);
  lcd.setCursor(1,0);
  lcd.print("Tem.. : ");
  lcd.print(temperature);
  delay(1000);
}
```

## Fonctionnement
1. L'ESP32 lit la température et l'humidité via le capteur **DHT22**.
2. Les valeurs sont envoyées à l'écran **LCD I2C** et affichées.
3. Les mesures sont rafraîchies toutes les **secondes**.

## Améliorations possibles
- Ajouter un affichage en **%RH** et en **°C / °F**.
- Intégrer une connexion WiFi pour envoyer les données à un serveur.
- Ajouter un **bouton poussoir** pour changer l'unité d'affichage.

## Auteur
Projet réalisé par **Paul Jacotin**.

