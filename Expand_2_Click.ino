/************************************************************************
*                                                                                                                                        
*    Test du module "Expand 2 Click"                                            
*                                                                    
*************************************************************************
* Description:  MIKROE-1838                                                
* Huit boutons poussoirs branchés sur le PORT B commandent respectivement 
* huit leds branchées sur le PORT A.
* Les anodes des led sont reliées au PORT A au travers d'une résistance 
* de protection et les cathodes à la masse.
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO
*        3. Module "Expand 2 Click" inséré sur le support N°1 du shield
*        
************************************************************************/
#include <Wire.h>                        // appel de la bibliothèque     
#define MCP23017_Adresse 0x20            // adresse I2C du MCP23017
#define IODIRA_Adresse 0x00              // adresse du registre IODIRA
#define IODIRB_Adresse 0x01              // adresse du registre IODIRB
#define GPIOA_Adresse 0x12               // adresse du registre GPIOA
#define GPIOB_Adresse 0x13               // adresse du registre GPIOB
#define GPPUB_Adresse 0x0D               // adresse du registre GPPUB
#define RST 17                           // affectation des broches         

byte entree;     
            
void setup()
{
pinMode(RST,OUTPUT);
digitalWrite(RST,HIGH);
Wire.begin();                             // initialisation de la liaison I2C
Wire.beginTransmission(MCP23017_Adresse); // communication avec le MCP23017
Wire.write(IODIRA_Adresse);               // écriture dans le registre IODIRA
Wire.write(0x00);                         // configuration du PORT A en sortie
Wire.write(IODIRB_Adresse);               // écriture dans le registre IODIRB
Wire.write(0xFF);                         // configuration du PORT B en entrée
Wire.write(GPPUB_Adresse);                // écriture dans le registre GPPUB
Wire.write(0xFF);                         // configuration des résistances de tirage
Wire.endTransmission();
}

void loop()
{
// Lecture des boutons poussoirs
Wire.beginTransmission(MCP23017_Adresse); // communication avec le MCP23017  
Wire.write(GPIOB_Adresse);                // écriture dans le registre GPIOB
Wire.endTransmission();
Wire.requestFrom(MCP23017_Adresse, 1);    // demande d'envoi d'un octet
entree=Wire.read();                       // mémorisation dans la variable entree
// Allumage des led
Wire.beginTransmission(MCP23017_Adresse); // communication avec le MCP23017 
Wire.write(GPIOA_Adresse);                // écriture dans le registre GPIOA
Wire.write(entree);                       
Wire.endTransmission();
delay(100); 
}

