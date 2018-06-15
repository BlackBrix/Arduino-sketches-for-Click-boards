/************************************************************************
*                                                                                                                                        
*    Test du module "Expand 4 Click"                                            
*                                                                    
*************************************************************************
* Description:  MIKROE-1910                                                
* Les huit sorties du module passent successivement à l'état haut.
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO
*        3. Module "Expand 4 Click" inséré sur le support N°1 du shield
*        
************************************************************************/

// Affectation des broches
#define MOSI 11               // broche SERIN du TPIC6A595
#define SCK 13                // broche SRCK du TPIC6A595
#define CS 10                 // broche RCK du TPIC6A595

byte sortie=0;
int i=0;

void setup()
{
// Configuration des broches  en sortie
pinMode(MOSI, OUTPUT);
pinMode(SCK, OUTPUT);
pinMode(CS, OUTPUT);
}

void loop()
{ 
if (i == 7)
    {
    i = 0;
    }
else
    {
     i++;
    }

bitSet(sortie, i);                     // mise à 1 du bit i de la variable sortie
digitalWrite(CS, LOW);              
shiftOut(MOSI, SCK, LSBFIRST, sortie); // envoi bit par bit de la variable sortie
digitalWrite(CS, HIGH);
delay(250);
}
