/************************************************************************
*                                                                                                                                        
*    Test du module "2x2 Key Click"                                            
*                                                                    
*************************************************************************
* Description :  MIKROE-2152                                                
* L'état des boutons est affiché dans le moniteur série.
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO
*        3. Module "2x2 Key Click" inséré sur le support N°1 du shield
*        
************************************************************************/

// Affectation des broches
#define BP1 14
#define BP2 17
#define BP3 10
#define BP4 6

void setup()
{
pinMode(BP1,INPUT);                             // configuration des broches en entrée            
pinMode(BP2,INPUT);
pinMode(BP3,INPUT); 
pinMode(BP4,INPUT);
Serial.begin(9600);                             // initialisation du moniteur série
}

void loop()
{
if (digitalRead(BP1)==HIGH)                    // si BP1 est actif
  {
  Serial.println("Le bouton poussoir N°1 est actif");
  }
else
  {
  Serial.println("Le bouton poussoir N°1 est inactif");
  }
if (digitalRead(BP2)==HIGH)                    // si BP2 est actif
  {
  Serial.println("Le bouton poussoir N°2 est actif");
  }
else
  {
  Serial.println("Le bouton poussoir N°2 est inactif");
  }
if (digitalRead(BP3)==HIGH)                    // si BP3 est actif
  {
  Serial.println("Le bouton poussoir N°3 est actif");
  }
else
  {
  Serial.println("Le bouton poussoir N°3 est inactif");
  }
if (digitalRead(BP4)==HIGH)                    // si BP4 est actif
  {
  Serial.println("Le bouton poussoir N°4 est actif");
  }
else
  {
  Serial.println("Le bouton poussoir N°4 est inactif");
  }
delay(1000);                                 // pause d'une seconde
}

