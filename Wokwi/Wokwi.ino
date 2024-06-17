#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define trigger 11
#define echo 12
#define beep 3
#define tempera 9
#define beep_start 100
#define min_distance 5
#define c 0.034

LiquidCrystal_I2C lcd(0x27, 16, 2);
OneWire oneWire(tempera);
DallasTemperature sensors(&oneWire);

long tempo;
float space;

void setup() {
  Wire.begin();
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(beep, OUTPUT);
  pinMode(tempera, INPUT);
  lcd.init();
  lcd.clear();
  lcd.backlight();
  Serial.begin(9600);
  sensors.begin();
}

void loop() {
  digitalWrite(trigger, LOW);
  delayMicroseconds(5);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  tempo = pulseIn(echo, HIGH) / 2;
  space = tempo * c;
  
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);

  Serial.println("Distancia = " + String(space, 1) + " cm");
  Serial.println("Temp = " + String(tempC, 1) + " C");

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tempC);
  lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("Dist: ");
  lcd.print(space);
  lcd.print(" cm");

  if (space < beep_start) {
    tone(beep, 1000);
    delay(40);
    if (space > min_distance) {
      noTone(beep);
      delay(space * 4);
    }
  } else {
    noTone(beep);
  }

  delay(50);
}