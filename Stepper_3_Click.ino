/************************************************************************
*                                                                                                                                        
*    Test du module "Stepper 3 Click"                                            
*                                                                    
*************************************************************************
* Description : MIKROE-2035                                                
* Le moteur fait un tour dans un sens puis revient à sa position d'origine dans l'autre sens.
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO
*        3. Module "Stepper 3 Click" inséré sur le support N°1 du shield
*        4. Moteur pas à pas 28BYJ-48
*        
************************************************************************/
#include <Stepper.h>                              // appel de la bibliothèque

// Affectation des broches
#define INA 14          
#define INB 17
#define INC 10
#define IND 6

const int nombre_pas=2048;                       // nombre de pas du moteur
Stepper moteur(nombre_pas, INA, INC, INB, IND);  // création de l'objet moteur

void setup()
{
moteur.setSpeed(10);                            // initialisation la vitesse de rotation du moteur en tour par minute
pinMode(INA, OUTPUT);                           // configuration des broches en sortie 
pinMode(INB, OUTPUT);       
pinMode(INC, OUTPUT);     
pinMode(IND, OUTPUT);  
}

void loop()
{
for (int i=1; i<=nombre_pas; i++)              // boucle avance du moteur en fonction du nombre de pas
  { 
  moteur.step(1);                              // un pas en sens positif
  }
for (int i=1; i<=nombre_pas; i++)              // boucle retour du moteur en fonction du nombre de pas
  {   
  moteur.step(-1);                             // un pas en sens négatif
  }
}

