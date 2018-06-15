/************************************************************************
*                                                                                                                                        
*    Test du module "Current Click"                                            
*                                                                    
*************************************************************************
* Description:  MIKROE-1396                                               
* La valeur du courant (entre 20 et 100 mA) circulant à travers la résistance shunt du module 
* est affichée sur le moniteur série.
* Le cavalier J2 est en position AN et la résistance shunt est égale à 1Ω.
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO
*        3. Module "Current Click" inséré sur le support N°1 du shield
*        
* Câblage
* Le courant arrive sur la broche VIN+ du bornier IN et ressort par la 
* broche VIN- du bornier IN sur laquelle est également branchée une 
* résistance de 50Ω reliée à la masse.
* La résistance shunt est reliée aux deux broches du bornier R SHUNT.
************************************************************************/

// Affectation des broches
#define AN A0                           // broche de sortie du module
int valeur;
float courant;
void setup()
{
Serial.begin(9600);                    // initialisation de la liaison série 
}

void loop()
{
valeur=analogRead(AN);                 // conversion AN
Serial.print("Valeur=");
Serial.println(valeur);
courant=0.176*valeur;                  // calcul du courant 
Serial.print("Courant=");
Serial.print(courant);
Serial.println(" mA");
delay(1000);
}

