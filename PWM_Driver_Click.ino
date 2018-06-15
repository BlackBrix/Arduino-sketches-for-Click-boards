/************************************************************************
*                                                                                                                                        
*    Test du module "PWM Driver Click"                                            
*                                                                    
*************************************************************************
* Description:  MIKROE-2272                                                
* Le signal PWM généré par l'Arduino est transmis à la charge via le module.
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO
*        3. Module "PWM Driver Click" inséré sur le support N°1 du shield
*        
************************************************************************/

// Affectation des broches
#define PWM 6           
int i;

void setup()
{
pinMode(PWM, OUTPUT);
}

void loop()
{
for(i = 0;i<=255;i++)                                 // variation du rapport cyclique toutes les 100 ms
  { 
    analogWrite(PWM, i);
    delay(100);
  }
delay(2000);                                         // pause de 2 secondes lorsque le rapport cyclique est à 100 %
analogWrite(PWM,0);                                  // rapport cyclique à 0%
delay(2000);                                         // pause de 2 secondes
}

