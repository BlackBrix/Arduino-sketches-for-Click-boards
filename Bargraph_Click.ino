/************************************************************************
*                                                                                                                                        
*    Test du module "Bargraph Click"                                            
*                                                                    
*************************************************************************
* Description:  MIKROE-1423                                                
* Un comptage binaire sur 10 bit est affiché sur les led du bargraph.
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO
*        3. Module "Bargraph Click" inséré sur le support N°1 du shield
*        
************************************************************************/

// Affectation des broches
#define SDIN 11    // broche DS des 74HC595
#define SCLK 13    // broche SHCP des 74HC595
#define LATCH 10   // broche STCP des 74HC595
#define DISPLAY 6  // broche de validation du bargraph

int MSB;
int LSB;

void setup()
{
pinMode(SDIN, OUTPUT);
pinMode(SCLK, OUTPUT);
pinMode(LATCH, OUTPUT);
pinMode(DISPLAY, OUTPUT);
digitalWrite(DISPLAY,HIGH);                  // validation du bargraph
}

void loop()
{
  for (int i = 0; i < 1024; i++)             // boucle de comptage
    {  
     LSB=i&0x00FF;                           // récupération des 8 bit de poids faibles de la variable i
     MSB=i&0xFF00;                           // récupération des 8 bit de poids forts de la variable i
     MSB=MSB>>8;                             // décalage des 8 bits de poids forts pour les mettre au format octet
     digitalWrite(LATCH, LOW);               // blocage du registre de sortie des 74HC595
     shiftOut(SDIN, SCLK, MSBFIRST, MSB);    // envoi des 8 bits de poids forts sur le second 74HC595
     shiftOut(SDIN, SCLK, MSBFIRST, LSB);    // envoi des 8 bits de poids faibles sur le premier 74HC595
     digitalWrite(LATCH, HIGH);              // déblocage du registre de sortie des 74HC595
     i=i+1;                                  // incrémentation de la variable de comptage
     delay(200);                             // pause 
    }
}
