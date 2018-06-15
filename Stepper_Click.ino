/************************************************************************
*                                                                                                                                        
*    Test du module "Stepper Click"                                            
*                                                                    
*************************************************************************
* Description:  MIKROE-1528                                                
* Le moteur tourne dans un sens ou l'autre défini par l'état d'un bouton poussoir .
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO
*        3. Module "Stepper Click" inséré sur le support N°1 du shield
*        4. Moteur pas à pas 28BYJ-48
*        5. Bouton poussoir
*        
************************************************************************/

// Affectation des broches
#define MS1 14          
#define MS2 17
#define DIR 10
#define STEP 6
#define BP 5

boolean sens;

void setup()
{
pinMode(MS1, OUTPUT);                           // configuration des broches en sortie 
pinMode(MS2, OUTPUT);       
pinMode(DIR, OUTPUT);     
pinMode(STEP, OUTPUT);
pinMode(BP, INPUT_PULLUP);                      // configuration de la broche 5 en entrée avec résistance de tirage    
digitalWrite(MS1,LOW);                          // configuration du A3967 en mode pas entier
digitalWrite(MS2,LOW);
}

void loop()
{
sens=digitalRead(BP);                           // acquisition de l'état du bouton
digitalWrite(DIR,sens);                         // configuration du sens de rotation
delay(1);
digitalWrite(STEP, HIGH);                       // envoi d'un front descendant sur l'entrée STEP du A3967
delay(1);
digitalWrite(STEP, LOW);
delay(1);
}
