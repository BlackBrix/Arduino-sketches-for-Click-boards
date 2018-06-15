/************************************************************************
*                                                                                                                                        
*    Test du module "Ammeter Click"                                            
*                                                                    
*************************************************************************
* Description:  MIKROE-2377                                               
* La valeur moyenne du courant est affichée sur le moniteur série.
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO
*        3. Module "Ammeter Click" inséré sur le support N°1 du shield
*        
***********************************************************************/

// Affectation des broches
#define AN A0                          // broche de sortie du module
int echantillon=100;
int valeur;
float courant=0.000;
unsigned long somme=0;
unsigned long moyenne;

void setup()
{
Serial.begin(9600);                    // initialisation de la liaison série 
}

void loop()
{
for (int i=0; i<echantillon; i++)
{
valeur=analogRead(AN);                 // conversion AN
Serial.print("Valeur=");
Serial.println(valeur);     
somme=somme+valeur;
moyenne=somme/echantillon;
/* Le module comporte un amplificateur différentiel ayant pour fonction de transfert Vs=Vref+10Ve
Ve=Rshunt*I avec Rshunt=0.1 donc Vs=1.024+I
Le courant d'entrée du module doit être compris entre 1 et 1000 mA, ce qui correspond à des tensions de sortie
de 1,025V soit une valeur du CAN à 207 et de 2,024V soit une valeur du CAN à 414*/
courant=map(moyenne,207,414,1,1000);
//courant=(valeur*0.00488)-1.024;
delay(10);
}
Serial.print("Courant moyen=");
Serial.print(courant);
Serial.println(" mA");
delay(500);
somme=0;
}


