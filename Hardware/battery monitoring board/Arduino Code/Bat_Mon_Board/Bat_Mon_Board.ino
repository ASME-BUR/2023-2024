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

int leakCount = 0;
int tempCount = 0;
int shutoffTemp = 0;
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
  //INVALIDATE LAST EEPROM SLOT
  if (current >= 12) {
    EEPROM.write(current-12, false);
  }
  
  EEPROM.write(current, true);

  //LEAK SENSOR
  if (digitalRead(leakPin)) {
    leakCount++;
    EEPROM.write(current+1, true);
  }
  else {
    EEPROM.write(current+1, false);
  }
  
  //TEMP SENSOR
  int temp = readTemp();
  EEPROM.write(current+2, temp >> 8);
  EEPROM.write(current+3, temp & 0xFF);

  /*
  //BATTERY MONITORING
  byte batvals[8];
  batvals[0] = analogRead(bat1_cel1);
  batvals[1] = analogRead(bat1_cel2);
  batvals[2] = analogRead(bat1_cel3);
  batvals[3] = analogRead(bat1_cel4);
  batvals[4] = analogRead(bat2_cel1);
  batvals[5] = analogRead(bat2_cel2);
  batvals[6] = analogRead(bat2_cel3);
  batvals[7] = analogRead(bat2_cel4);
  
  for (int i = 0; i < 8; i++) {
    EEPROM.write(current+4+i, batvals[i]);
    if (batvals[i] < minVoltages[i]) {
      batCount[i]++;
    }
  }
  */

  //CHECK COUNTERS
  checkTurnoff();

  //INCREMENT EEPROM
  if (current + 12 > EEPROM.length()) {
    current = 0;
  }
  else {
    current += 12;
  }
  delay(1000);
}

int readTemp() {
  Serial.print("Internal Temp = ");
  Serial.println(thermocouple.readInternal());

  double c = thermocouple.readCelsius();
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
      shutoffTemp = c;
    }
    return int(c);
  }
}
void turnoff() {
  digitalWrite(outputPin, LOW);
}

void checkTurnoff() {
  if(tempCount >= 3) {
    Serial.println("Too Hot! c = ");
    Serial.print(shutoffTemp);
    turnoff();
  }
  if(leakCount >= 3) {
    Serial.println("LEAK!");
    turnoff();
  }
  for (int i = 0; i < 8; i++) {
    if(batCount[i] >= 3) {
    Serial.println("A cell does not have sufficient voltage!");
    turnoff();
    }
  } 
}
