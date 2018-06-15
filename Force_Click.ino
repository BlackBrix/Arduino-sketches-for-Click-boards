/************************************************************************
*                                                                                                                                        
*    Test du module "Force Click"                                            
*                                                                    
*************************************************************************
* Description:  MIKROE-2065                                               
* La valeur de la force (entre 0 et 1024) est affichée sur le moniteur série.
* 
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO
*        3. Module "Force Click" inséré sur le support N°1 du shield
*        
************************************************************************/

// Affectation des broches
#define AN A0                           // broche de sortie du module
int valeur;

void setup()
{
Serial.begin(9600);                    // initialisation de la liaison série 
}

void loop()
{
valeur=analogRead(AN);                 // conversion AN
Serial.print("Valeur=");
Serial.println(valeur);
delay(500);
}

