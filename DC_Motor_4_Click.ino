/************************************************************************
*                                                                                                                                        
*    Test du module "DC Motor 4 Click"                                            
*                                                                    
*************************************************************************
* Description:  MIKROE-2221                                                
* La vitesse du moteur augmente par pas successif toutes les 10 ms 
* jusqu'à la vitesse maximale puis le cycle recommence mais le moteur 
* tourne dans l'autre sens.
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO
*        3. Module "DC Motor 4 Click" inséré sur le support N°1 du shield
*                
************************************************************************/

// Affectation des broches
#define DIR 14      
#define EN 10         
#define PWM 6              

int i;

void setup()
{
pinMode(DIR,OUTPUT);                                           // configuration des broches
pinMode(PWM,OUTPUT); 
pinMode(EN,OUTPUT);
digitalWrite(EN,LOW);                                          // validation du max14870
}

void loop()
{
digitalWrite(DIR,HIGH);                                        // sens horaire
for(i = 0;i<256;i++)                                           // variation de la vitesse toutes les 10 ms
  { 
    analogWrite(PWM, i);
    delay(10);
  }
delay(1000);                                                   // pause d'une seconde à vitesse maximale
analogWrite(PWM, 0);                                           // arrêt du moteur
delay(1000);                                                   // pause d'une seconde entre les deux sens de rotation
digitalWrite(DIR,LOW);                                         // sens anti-horaire
for(i = 0;i<256;i++)                                           // variation de la vitesse toutes les 10 ms
  { 
    analogWrite(PWM, i);
    delay(10);
  }
delay(1000);                                                   // pause d'une seconde à vitesse maximale
analogWrite(PWM, 0);                                           // arrêt du moteur
delay(1000);                                                   // pause d'une seconde entre les deux sens de rotation  
}



