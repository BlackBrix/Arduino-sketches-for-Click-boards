/************************************************************************
*                                                                                                                                        
*    Test du module "Thumbwheel Click"                                            
*                                                                    
*************************************************************************
* Description:  MIKROE-2366                                                
* La position du commutateur est affiché dans le moniteur série.
* 
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO 
*        3. Module "Thumbwheel Click" inséré sur le support N°1 du shield
*        
* Bibliothèque
*        1. https://github.com/PaulStoffregen/OneWire
*        
* Remarque : Le code obtenu pour les positions est le suivant 
* Position 1  -> Code 0x0A
* Position 2  -> Code 0x08
* Position 3  -> Code 0x0A
* Position 4  -> Code 0x04
* Position 5  -> Code 0x06
* Position 6  -> Code 0x00
* Position 7  -> Code 0x02
* Position 8  -> Code 0x00
* Position 9  -> Code 0x02
* Position 10 -> Code 0x08
* 
************************************************************************/

#include <OneWire.h>                         // appel de la bibliothèque

// Affectation des broches
#define OW1 6
#define RST 17

byte addresse[8];
byte code;

OneWire ds(OW1);                            // création de l'objet ds


void setup(void) 
{
Serial.begin(9600);                         // initialisation de la liaison série
pinMode(RST,OUTPUT);                        // configuration de la broche RST en sortie
digitalWrite(RST,HIGH);
Serial.println("Recherche composant");

// Recherche un module 1-Wire sur le bus 
  if (!ds.search(addresse)) 
  {
    Serial.println("Fin de recherche");
    ds.reset_search();
  }
  
// Module 1-Wire trouvé 
  Serial.print("Composant trouvé :");
  for(byte i = 0; i < 8; ++i) 
  {
    if (addresse[i] < 0x10) 
      {
        Serial.write('0');
      }
    Serial.print(addresse[i], HEX);
    Serial.write(' ');
  }
  Serial.println();
  if (addresse[0] == 0x29) 
      {
        Serial.println("Le composant est un DS2408");
      }

// Vérification de l'adresse 
  if (OneWire::crc8(addresse, 7) != addresse[7]) 
  {
      Serial.print("CRC invalide");
  }
  
  Serial.println();
  delay(1000);
}


void loop(void) 
{
// Acquisition du code
ds.reset();
ds.select(addresse);
ds.write(0xF0);
ds.write(0x88);
ds.write(0x00);
code = ds.read();
Serial.print("Code:");
Serial.println(code,HEX);
switch (code) 
{
  case 0x0A:
     Serial.println("La position est 1 ou 3");
  break;
  case 0x08:
     Serial.println("La position est 2 ou 10");
  break;
  case 0x04:
     Serial.println("La position est 4");
  break;
  case 0x06:
     Serial.println("La position est 5");
  break;
  case 0x00:
     Serial.println("La position est 6 ou 8");
  break;
  case 0x02:
     Serial.println("La position est 7 ou 9");
  break;
  default:
  break;
}
delay(1000);
}
