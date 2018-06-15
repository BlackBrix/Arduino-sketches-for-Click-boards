/************************************************************************
*                                                                                                                                        
*    Test du module "Signal Relay Click"                                            
*                                                                    
*************************************************************************
* Description :  MIKROE-2154                                                
* Les relais sont activés un à un avec une pause d'une seconde entre chaque étape.
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO
*        3. Module "Signal Relay Click" inséré sur le support N°1 du shield
*        
************************************************************************/

// Affectation des broches
#define REL1 14
#define REL2 17
#define REL3 10
#define REL4 6

void setup()
{
pinMode(REL1,OUTPUT);                             // configuration des broches en sortie            
pinMode(REL2,OUTPUT);
pinMode(REL3,OUTPUT); 
pinMode(REL4,OUTPUT);
}

void loop()
{
digitalWrite(REL1,HIGH);                      // Relais 1 actif
digitalWrite(REL2,LOW);
digitalWrite(REL3,LOW);
digitalWrite(REL4,LOW);
delay(1000);                                 // pause d'une seconde
digitalWrite(REL1,LOW);                      // Relais 2 actif
digitalWrite(REL2,HIGH);
digitalWrite(REL3,LOW);
digitalWrite(REL4,LOW);
delay(1000);                                 // pause d'une seconde
digitalWrite(REL1,LOW);                      // Relais 3 actif
digitalWrite(REL2,LOW);
digitalWrite(REL3,HIGH);
digitalWrite(REL4,LOW);
delay(1000);                                 // pause d'une seconde
digitalWrite(REL1,LOW);                      // Relais 1 actif
digitalWrite(REL2,LOW);
digitalWrite(REL3,LOW);
digitalWrite(REL4,HIGH);
delay(1000);                                 // pause d'une seconde
}

