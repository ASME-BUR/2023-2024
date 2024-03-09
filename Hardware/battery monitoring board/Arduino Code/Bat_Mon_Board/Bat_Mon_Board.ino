#include <SPI.h>
#include "Adafruit_MAX31855.h"
#include <EEPROM.h>

int leakPin = 2;
int outputPin = 3;
int LEDPin = 4;
int MAXCS = 10;
int MAXDO = 12;
int MAXCLK = 13;

int bat1_cel1 = A0;
int bat1_cel4 = A1;
int bat1_cel3 = A2;
int bat1_cel2 = A3;
int bat2_cel1 = A4;
int bat2_cel4 = A5;
int bat2_cel3 = A6;
int bat2_cel2 = A7;

//PROGRAM VARIABLES (NOT FOR USER)
int leakCount = 0;
int tempCount = 0;
byte isLeak = 0;
double c = 255;
int batCount[8] = {0, 0, 0, 0, 0, 0, 0, 0};

Adafruit_MAX31855 thermocouple(MAXCLK, MAXCS, MAXDO);
int current = 0; //current EEPROM address


//ADJUSTABLE VARIABLES
int maxTemp = 55;
int minVoltages[8] = {179, 155, 190, 217, 179, 155, 190, 217};

void setup() {
  pinMode(outputPin, OUTPUT);
  pinMode(LEDPin, OUTPUT);
  digitalWrite(outputPin, HIGH);

  Serial.begin(9600);

  while (!Serial) delay(1);

  Serial.println("MAX31855 test");
  // wait for MAX chip to stabilize
  delay(500);
  Serial.print("Initializing sensor...");
  if (!thermocouple.begin()) {
    Serial.println("ERROR.");
    while (1) delay(10);
  }
  Serial.println("DONE.");
}

void loop() { 

  //LEAK SENSOR
  if (digitalRead(leakPin)) {
    leakCount++;
  }
  else {
    leakCount = 0;
  }
  
  //TEMP SENSOR
  Serial.print("Internal Temp = ");
  Serial.println(thermocouple.readInternal());

  c = thermocouple.readCelsius();
  if (isnan(c)) {
    Serial.println("Thermocouple fault(s) detected!");
    uint8_t e = thermocouple.readError();
    if (e & MAX31855_FAULT_OPEN) Serial.println("FAULT: Thermocouple is open - no connections.");
    if (e & MAX31855_FAULT_SHORT_GND) Serial.println("FAULT: Thermocouple is short-circuited to GND.");
    if (e & MAX31855_FAULT_SHORT_VCC) Serial.println("FAULT: Thermocouple is short-circuited to VCC.");
    return 255;
  } else {
    Serial.print("C = ");
    Serial.println(c);
    if (c > maxTemp) {
      tempCount++;
    }
    else {
      tempCount = 0;
    }
  }

  //BATTERY MONITORING
  byte batvals[8];
/*
  batvals[0] = analogRead(bat1_cel1);
  batvals[1] = analogRead(bat1_cel2);
  batvals[2] = analogRead(bat1_cel3);
  batvals[3] = analogRead(bat1_cel4);
  batvals[4] = analogRead(bat2_cel1);
  batvals[5] = analogRead(bat2_cel2);
  batvals[6] = analogRead(bat2_cel3);
  batvals[7] = analogRead(bat2_cel4);
  
  for (int i = 0; i < 8; i++) {
    if (batvals[i] < minVoltages[i]) {
      batCount[i]++;
    }
    else {
      batCount[i] = 0;
    }
  }
*/

  //CHECK TURNOFF
  if(leakCount >= 3) {
    isLeak = 1;
    Serial.println("LEAK!");
    turnoff(batvals[8]);
  }
  if (tempCount >= 3) {
    Serial.println("Too Hot! c = ");
    Serial.print(c);
    turnoff(batvals[8]);
  }
  for (int i = 0; i < 8; i++) {
    if(batCount[i] >= 3) {
    Serial.println("A cell does not have sufficient voltage!");
    turnoff(batvals[8]);
    }
  } 

  //WAIT FOR NEXT SAMPLE
  delay(1000);
}

void turnoff(byte bat[8]) {
  digitalWrite(outputPin, LOW);
  EEPROM.write(0, isLeak);

  int temp = int(c);
  EEPROM.write(current+1, temp >> 8);
  EEPROM.write(current+2, temp & 0xFF);

  for (int i = 0; i < 8; i++) {
    EEPROM.write(current+3+i, bat[i]);
  }
}
