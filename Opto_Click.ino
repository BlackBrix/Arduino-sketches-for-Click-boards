/************************************************************************
*                                                                                                                                        
*    Test du module "Opto Click"                                            
*                                                                    
*************************************************************************
* Description :  MIKROE-1196                                                
* L'état des sorties du module est affiché dans le moniteur série.
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO
*        3. Module "Opto Click" inséré sur le support N°1 du shield
*        
************************************************************************/

// Affectation des broches
#define IN1 2
#define IN2 10
#define IN3 17
#define IN4 14

void setup()
{
pinMode(IN1,INPUT);                             // configuration des broches en entrée            
pinMode(IN2,INPUT);
pinMode(IN3,INPUT); 
pinMode(IN4,INPUT);
Serial.begin(9600);                             // initialisation du moniteur série
}

void loop()
{
if (digitalRead(IN1)==HIGH)                    // si IN1 est inactif
  {
  Serial.println("Entree 1 inactive");
  }
else
  {
  Serial.println("Entree 1 active");
  }
if (digitalRead(IN2)==HIGH)                    // si IN2 est inactif
  {
  Serial.println("Entree 2 inactive");
  }
else
  {
  Serial.println("Entree 2 active");
  }
if (digitalRead(IN3)==HIGH)                    // si IN3 est inactif
  {
  Serial.println("Entree 3 inactive");
  }
else
  {
  Serial.println("Entree 3 active");
  }
if (digitalRead(IN4)==HIGH)                    // si IN4 est inactif
  {
  Serial.println("Entree 4 inactive");
  }
else
  {
  Serial.println("Entree 4 active");
  }
delay(1000);                                 // pause d'une seconde
}

