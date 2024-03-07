#include <EEPROM.h>

int current = 12; //current address to read

void setup() {
  // put your setup code here, to run once:

  /*TESTING
  EEPROM.write(current-12, false);
  EEPROM.write(current, true);
  EEPROM.write(current+1, false);
  int temp = 35;
  EEPROM.write(current+2, temp >> 8);
  EEPROM.write(current+3, temp & 0xFF);
  EEPROM.write(current+4, 120);
  EEPROM.write(current+5, 121);
  EEPROM.write(current+6, 122);
  EEPROM.write(current+7, 123);
  EEPROM.write(current+8, 124);
  EEPROM.write(current+9, 125);
  EEPROM.write(current+10, 126);
  EEPROM.write(current+11, 127);
  TESTING END*/
  
  Serial.begin(9600);
  Serial.println("Finding last record...");

  bool currFound = false;
  int i = 0;
  while (i < EEPROM.length()) {
    bool validbit;
    EEPROM.get(i, validbit);
    if (validbit) {
      currFound = true;
      current = i;
      Serial.print("Last record found at ");
      Serial.println(current);
      delay(50);
      break;
    }
    i += 12;
  }

  if (!currFound) {
    Serial.println("Last record not found!");
  }

  else {
  getData();
  //current =- 12;
  //getData();
  }

}

void loop() {
  
}

void getData() {
  // put your main code here, to run repeatedly:
  Serial.print("DATA AT POSITION ");
  Serial.println(current);
  bool leak;
  Serial.print("Leak Boolean: ");
  Serial.println(leak);

  byte byte1 = EEPROM.read(current+2);
  byte byte2 = EEPROM.read(current+3);
  int temp = (byte1 << 8) | byte2;
  Serial.print("Temperature reading: ");
  Serial.println(temp);

  Serial.print("Voltage Readings:");
  for (int i = 0; i < 8; i++) {
    Serial.print(" ");
    Serial.print(EEPROM.read(current+4+i));
  }
  Serial.println(" ");
  Serial.println(" ----------------------------------- ");
}
