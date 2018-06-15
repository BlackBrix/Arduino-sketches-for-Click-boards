/************************************************************************
*                                                                                                                                        
*    Test du module "Relay 2 Click"                                            
*                                                                    
*************************************************************************
* Description :  MIKROE-1899                                                
* Les relais sont activés un à un avec une pause d'une seconde entre chaque étape.
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Module "Relay 2 Click" 
*     
* Attention, ce module est alimenté en 3,3V. Il faut donc faire une adaptation 
* de tension entre les broches de sorties de l'Arduino et les broches d'entrées
* du module.
************************************************************************/

// Affectation des broches
#define REL1 6
#define REL2 14

void setup()
{
pinMode(REL1,OUTPUT);                             // configuration des broches en sortie            
pinMode(REL2,OUTPUT);
}

void loop()
{
digitalWrite(REL1,HIGH);                      // Relais 1 actif
digitalWrite(REL2,LOW);
delay(1000);                                 // pause d'une seconde
digitalWrite(REL1,LOW);                      // Relais 2 actif
digitalWrite(REL2,HIGH);
delay(1000);                                 // pause d'une seconde
}

