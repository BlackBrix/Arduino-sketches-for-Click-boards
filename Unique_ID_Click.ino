/************************************************************************
*                                                                                                                                        
*    Test du module "Unique ID Click"                                            
*                                                                    
*************************************************************************
* Description:  MIKROE-1819                                                
* Le numéro de série du module est affiché dans le moniteur série.
* 
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO 
*        3. Module "Unique ID Click" inséré sur le support N°1 du shield
*        
* Bibliothèques
*        1. https://github.com/PaulStoffregen/OneWire
*        
************************************************************************/

#include <OneWire.h>                        // appel de la bibliothèque                       

#define GPIO0 6                             // affectation des broches

// Variables de stockage des 8 octets du DS2401: 1 octet pour la famille, 6 octets pour le N° de série et 1 octet pour le CRC
byte data[8];
                               
OneWire DS2401(GPIO0);                      // création de l'objet DS2401


void setup() 
{
Serial.begin(9600);                        // initialisation de la liaison série
Serial.println("Test du module Unique ID Click"); 
Serial.println(" ");
if (DS2401.reset()) 
  {
  DS2401.write(0x33);                      // demande de lecture de la ROM
  data[0] = DS2401.read();                 // acquisition du N° de famille
  Serial.print("Code famille: 0x");
  Affichage_code(data[0]);                     
  Serial.print("Numero de serie: 0x");
  for (byte i = 1; i <= 6; i++)           // acquisition des 6 octets du N° de série
    {
      data[i] = DS2401.read(); 
      Affichage_code(data[i], (i < 6) ? '\0' : '\n');
    } 
  data[7] = DS2401.read();                // acquisition du CRC
  if (data[7] == OneWire::crc8(data, 7)) 
    {
      Serial.print("CRC du DS2401 correct = 0x");
      Affichage_code (data[7]);
    } 
  else 
    {
      Serial.println("Erreur de CRC");
    }
  }
}

void loop() 
{
}

void Affichage_code(byte donnee, const char separateur = '\n')  // fonction permettant d'afficher dans le moniteur série l'octet en hexadécimal
{
  if (donnee <= 0xF) 
  {
    Serial.print(0);
  }
  Serial.print(donnee, HEX);
  if (separateur) 
  {
  Serial.write(separateur);
  }
}
