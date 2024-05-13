#include <SPI.h>
#include "Adafruit_MAX31855.h"
#include <MCP3008.h>
#include <EEPROM.h>

//adc SPI pins
#define CS_PIN 9
#define CLOCK_PIN 13
#define MOSI_PIN 11
#define MISO_PIN 12

//temp sensor SPI pins
int MAXCS = 10;
int MAXDO = 12;
int MAXCLK = 13;

//other pins
int leakPin = 2;
int outputPin = 3;
int LEDPin = 4;

//PROGRAM VARIABLES (NOT FOR USER)
int leakCount = 0;
int tempCount = 0;
byte isLeak = 0;
double c = 255;
int batvals[8];
int batCount[8] = {0, 0, 0, 0, 0, 0, 0, 0};

Adafruit_MAX31855 thermocouple(MAXCLK, MAXCS, MAXDO);
MCP3008 adc(CLOCK_PIN, MOSI_PIN, MISO_PIN, CS_PIN);


//ADJUSTABLE VARIABLES
int maxTemp = 80;
int minVoltage = 660;

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
  for (int i=0; i<8; i++) {
   int val = adc.readADC(i);
   batvals[i] = val;
   Serial.print(val);
   Serial.print(" ");
   
   if (val < minVoltage)
      batCount[i]++;
   else
      batCount[i] = 0;
  }
  Serial.println("------------------------------");

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
  Serial.println("TURNING OFF");
  digitalWrite(outputPin, LOW);
  EEPROM.write(0, isLeak);

  int temp = int(c);
  EEPROM.write(1, temp >> 8);
  EEPROM.write(2, temp & 0xFF);

  for (int i = 0; i < 16; i+=2) {
    EEPROM.write(3+i, batvals[i] >> 8);
    EEPROM.write(4+i, batvals[i] & 0xFF);
  }
}
