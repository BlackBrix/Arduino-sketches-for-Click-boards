/************************************************************************
*                                                                                                                                        
*    Test du module "Button R Click"                                            
*                                                                    
*************************************************************************
* Description :  MIKROE-1901                                                
* L'état du bouton est affiché dans le moniteur série et la led clignote
* pendant 1 s après chaque appui.
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO
*        3. Module "Button R Click" inséré sur le support N°1 du shield
*        
************************************************************************/

// Affectation des broches
#define LED 6
#define BP 2


void setup()
{
pinMode(BP,INPUT);                                 // configuration de la broche en entrée            
pinMode(LED,OUTPUT);                               // configuration de la broche en sortie
Serial.begin(9600);                                // initialisation du moniteur série
}

void loop()
{
if (digitalRead(BP)==HIGH)                         // si BP est actif
  {
  Serial.println("Le bouton poussoir est actif");
  for (int i=0;i<10;i++)
    {
    digitalWrite(LED,HIGH);                        // allumage de la led
    delay(50);
    digitalWrite(LED,LOW);                         // extinction de la led
    delay(50);
    }
  }
else
  {
  Serial.println("Le bouton poussoir est inactif");
  }
}


