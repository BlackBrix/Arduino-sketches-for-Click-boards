/************************************************************************
*                                                                                                                                        
*    Test du module "7x10 R Click"                                            
*                                                                    
*************************************************************************
* Description :  MIKROE-1993                                                
* Les nombres de 00 à 99 défilent toutes les 300 ms sur les deux matrices à led du module.
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO
*        3. Module "7x10 R Click" inséré sur le support N°1 du shield
*        
************************************************************************/

// Affectation des broches
#define SDI 11
#define SCK 13
#define LATCH 10
#define R_CLK 14                              
#define R_RST 6 

int nombre=0;
int unite=0;
int dizaine=0;
unsigned long temps;

byte chiffre[10][7]={
{0x0E, 0x11, 0x19, 0x15, 0x13, 0x11, 0x0E},  //0
{0x0E, 0x04, 0x04, 0x04, 0x04, 0x0C, 0x04},  //1
{0x1F, 0x08, 0x04, 0x02, 0x01, 0x11, 0x0E},  //2
{0x0E, 0x11, 0x01, 0x02, 0x04, 0x02, 0x1F},  //3
{0x02, 0x02, 0x1F, 0x12, 0x0A, 0x06, 0x02},  //4
{0x0E, 0x11, 0x01, 0x01, 0x1E, 0x10, 0x1F},  //5
{0x0E, 0x11, 0x11, 0x1E, 0x10, 0x08, 0x06},  //6
{0x08, 0x08, 0x08, 0x04, 0x02, 0x01, 0x1F},  //7
{0x0E, 0x11, 0x11, 0x0E, 0x11, 0x11, 0x0E},  //8
{0x0C, 0x02, 0x01, 0x0F, 0x11, 0x11, 0x0E},  //9
};




void setup() 
{
 // configuration des broches en sortie
 pinMode(SDI,OUTPUT);         
 pinMode(SCK, OUTPUT);
 pinMode(LATCH, OUTPUT);
 pinMode(R_CLK, OUTPUT);
 pinMode(R_RST, OUTPUT);
 digitalWrite(R_RST,HIGH);
 delayMicroseconds(5);
 digitalWrite(R_RST,LOW);
}

void loop() 
{ 
 // Calcul
 dizaine=nombre/10;
 if ((dizaine==10)&&(unite==9))
 {
  nombre=0;
  dizaine=0;
 }
 unite=nombre-10*dizaine;
 nombre=nombre+1;
 
 // Affichage sur les matrices
temps=millis();
do 
{
    for(int i=0;i<7;i++)
    {
    digitalWrite(LATCH, LOW);                              // blocage du registre de sortie des 74HC595
    shiftOut(SDI, SCK, MSBFIRST,chiffre[dizaine][i]);      // envoi des 8 bits de poids forts sur le premier 74HC595
    shiftOut(SDI, SCK, MSBFIRST,chiffre[unite][i]);        // envoi des 8 bits de poids forts sur le second 74HC595
    digitalWrite(LATCH, HIGH);                             // déblocage du registre de sortie des 74HC595
    delayMicroseconds(4700);                               // pause pour le multiplexage à affiner en fonction de l'éclairage
    digitalWrite(R_CLK,HIGH);                              // envoi d'une impulsion d'horloge sur le CD4017
    delayMicroseconds(5);
    digitalWrite(R_CLK,LOW);
   } 
    

 // Extinction de toutes les led
    digitalWrite(LATCH, LOW);                     
    shiftOut(SDI, SCK, MSBFIRST,0);            
    shiftOut(SDI, SCK, MSBFIRST,0);            
    digitalWrite(LATCH, HIGH);
    digitalWrite(R_RST,HIGH);
    delayMicroseconds(5);
    digitalWrite(R_RST,LOW);
}
 while(millis()-temps<300); 
}
