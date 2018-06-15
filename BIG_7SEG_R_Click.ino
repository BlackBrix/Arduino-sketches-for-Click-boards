/************************************************************************
*                                                                                                                                        
*    Test du module "BIG 7-SEG R Click"                                            
*                                                                    
*************************************************************************
* Description:  MIKROE-2269                                                
* Un comptage 0 à 9 est affiché sur l'afficheur.
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO
*        3. Module "BIG 7-SEG R Click" inséré sur le support N°1 du shield
*        
************************************************************************/

// Affectation des broches
#define DSI 11     // broche DS du 74HC595
#define CLK 13     // broche SHCP du 74HC595
#define LATCH 10   // broche STCP du 74HC595
#define MR 17      // broche MR du 74HC595
#define PWM 6      // broche de variation de luminosité de l'afficheur

byte chiffre[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7C,0x07,0x7F,0x67};  

void setup()
{
pinMode(DSI, OUTPUT);
pinMode(CLK, OUTPUT);
pinMode(LATCH, OUTPUT);
pinMode(MR, OUTPUT);
pinMode(PWM, OUTPUT);
digitalWrite(PWM,HIGH);                                 // validation de l'afficheur
}

void loop()
{
 
 digitalWrite(MR,LOW);                                  // remise à zero des sorties du 74HC595
 delayMicroseconds(5);
 digitalWrite(MR,HIGH);
 for(int i=0;i<10;i++)
    {
    digitalWrite(LATCH, LOW);                           // blocage du registre de sortie du 74HC595
    shiftOut(DSI, CLK, MSBFIRST, chiffre[i]);           // envoi des 8 bits  sur le 74HC595 
    digitalWrite(LATCH, HIGH);                          // déblocage du registre de sortie du 74HC595 
    delay(1000);
    } 
}
