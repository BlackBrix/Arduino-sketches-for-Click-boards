/************************************************************************
*                                                                                                                                        
*    Test du module "7seg Click"                                            
*                                                                    
*************************************************************************
* Description:  MIKROE-1201                                                
* Les nombres 00 à 99 sont affichés sur les deux afficheurs du module.
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO
*        3. Module "7seg Click" inséré sur le support N°1 du shield
*        
************************************************************************/

// Affectation des broches
#define DSI 11     // broche DS du premier 74HC595
#define CLK 13     // broche SHCP des 74HC595
#define LATCH 10   // broche STCP des 74HC595
#define MR 17      // broche MR des 74HC595
#define PWM 6      // broche de variation de luminosité des afficheurs

byte chiffre[10]={0x7E,0x0A,0xB6,0x9E,0xCA,0xDC,0xF8,0x0E,0xFE,0xCE};  

void setup()
{
pinMode(DSI, OUTPUT);
pinMode(CLK, OUTPUT);
pinMode(LATCH, OUTPUT);
pinMode(MR, OUTPUT);
pinMode(PWM, OUTPUT);
digitalWrite(PWM,HIGH);                                  // validation des afficheurs
}

void loop()
{
 digitalWrite(MR,LOW);                                    // remise à zero des sorties des 74HC595
 delayMicroseconds(5);
 digitalWrite(MR,HIGH);
    for (int i = 0; i < 10; i++)                          // boucle de comptage des dizaines
    { 
       for (int j = 0; j < 10; j++)                       // boucle de comptage des unités
      {
      digitalWrite(LATCH, LOW);                           // blocage du registre de sortie des 74HC595
      shiftOut(DSI, CLK, MSBFIRST, chiffre[j]);           // envoi des 8 bits  sur le second 74HC595 (unité)
      shiftOut(DSI, CLK, MSBFIRST, chiffre[i]);           // envoi des 8 bits  sur le premier 74HC595 (dizaine)
      digitalWrite(LATCH, HIGH);                          // déblocage du registre de sortie des 74HC595 
      delay(1000);
      }  
    }    
}
