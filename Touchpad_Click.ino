/************************************************************************
*                                                                                                                                        
*    Test du module "Touchpad Click"                                            
*                                                                    
*************************************************************************
* Description :  MIKROE-1995                                                
* Les valeurs des registres donnant la position sont affichés dans le
* moniteur série.
* 
* Exemple inspiré de 
* https://github.com/theapi/touch_timer/tree/master/arduino/mtch6102_proof_of_concept
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Module "Touchpad Click" 
*        3. Shifter Level TXB0108
*     
* Attention, ce module est alimenté en 3,3V. Il faut donc utiliser un module 
* shifter level I2C.
************************************************************************/

#include <Wire.h>
#define ADDR 0x25

// read register
unsigned char readRegister(unsigned char addr_reg) {
    byte error;
    Wire.beginTransmission(ADDR);
    Wire.write(addr_reg); // register to read
    error = Wire.endTransmission();
    Wire.requestFrom(ADDR, 1); // read a byte

    while (Wire.available()) {
        return Wire.read();
    }
}

// write data to register 
unsigned char writeRegister(unsigned char addr_reg, unsigned char dta) {
    Wire.beginTransmission(ADDR);
    Wire.write(addr_reg); // register to read
    Wire.write(dta);
    Wire.endTransmission();
}

void setup() 
{
 byte data;
  Wire.begin();
  Serial.begin(115200);

  delay(500);

  // the operating mode (MODE)
  data = readRegister(0x05);
  Serial.print("MODE: ");
  Serial.println(data,BIN);

  // Set mode to Touch only
  writeRegister(0x05, 0x02);


  data = readRegister(0x05);
  Serial.print("MODE: ");
  Serial.println(data,BIN);

  data = readRegister(0x20);
  Serial.print("NUMBEROFXCHANNELS: ");
  Serial.println(data);

  data = readRegister(0x21);
  Serial.print("NUMBEROFYCHANNELS: ");
  Serial.println(data);

  writeRegister(0x20, 0x07);
  writeRegister(0x21, 0x06);

  data = readRegister(0x20);
  Serial.print("NUMBEROFXCHANNELS: ");
  Serial.println(data);

  data = readRegister(0x21);
  Serial.print("NUMBEROFYCHANNELS: ");
  Serial.println(data);
}

void loop() 
{
byte data;
Serial.print("SENSORVALUE_RX <i>: ");
  for (byte i = 0x80; i < 0x8E; i++) 
  {
    data = readRegister(i);
    Serial.print(data);
    Serial.print(", ");
  }
Serial.println();
delay(500);
}

