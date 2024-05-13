#include <EEPROM.h>

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
  getData();

}

void loop() {
  
}

void getData() {
  // put your main code here, to run repeatedly:
  Serial.println("DATA:");
  Serial.print("Leak Boolean: ");
  Serial.println(EEPROM.read(0));

  byte byte1 = EEPROM.read(1);
  byte byte2 = EEPROM.read(2);
  int temp = (byte1 << 8) | byte2;
  Serial.print("Temperature reading: ");
  Serial.println(temp);

  Serial.print("Voltage Readings:");
  for (int i = 0; i < 16; i+=2) {
    byte byte1 = EEPROM.read(3+i);
    byte byte2 = EEPROM.read(4+i);
    int voltage = (byte1 << 8) | byte2;
    Serial.print(" ");
    Serial.print(voltage);
  }
  Serial.println(" ");
  Serial.println(" ----------------------------------- ");
}
