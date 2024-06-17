#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define trigger 11
#define echo 12
#define beep 3
#define beep_start 100
#define min_distance 5
#define c 0.034

LiquidCrystal_I2C lcd(0x27, 16, 2);

long tempo;
float space;

void setup() {
  Wire.begin();
  Wire.begin(0x20);
  Wire.write(255);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(beep, OUTPUT);
  lcd.init();
  lcd.clear();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigger, LOW);
  delayMicroseconds(5);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  tempo = pulseIn(echo, HIGH) / 2;
  space = tempo * c;

  Serial.println("Distancia = " + String(space, 1) + " cm");

  lcd.setCursor(0, 0);
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

  Wire.beginTransmission(0x20);
  if (space < 30) {
    Wire.write(255);
  } else if (space < 40) {
    Wire.write(127);
  } else if (space < 50) {
    Wire.write(63);
  } else if (space < 60) {
    Wire.write(31);
  } else if (space < 70) {
    Wire.write(15);
  } else if (space < 80) {
    Wire.write(7);
  } else if (space < 90) {
    Wire.write(3);
  } else if (space < 100) {
    Wire.write(1);
  } else {
    Wire.write(0);
  }
  Wire.endTransmission();

  delay(50);
}