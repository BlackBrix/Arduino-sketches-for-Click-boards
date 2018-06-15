/************************************************************************
*                                                                                                                                        
*    Test du module "8x8 Click"                                            
*                                                                    
*************************************************************************
* Description :  MIKROE-1295                                                
* Le slogan I ♥ Arduino est affiché sur la matrice.
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO
*        3. Module "8x8 Click" inséré sur le support N°1 du shield
*        
* Bibliothèque 
*        1. https://github.com/wayoda/LedControl
*        
* Logiciel permettant de convertir un caractère en 8 octets
*        1. https://8x8ledmatrixgenerator.codeplex.com/releases/view/135669
************************************************************************/

// Affectation des broches
#define CS 10
#define CLK 13
#define DIN 11

#define NB_MATRICE 1


#include "LedControl.h"                                                                                       // appel de la librairie
LedControl matrice=LedControl(DIN,CLK,CS,NB_MATRICE);                        // création de l'objet matrice

// Définition des caractères à l'aide du logiciel 8x8 ledmatrixgenerator
unsigned char coeur[8]={0x00,0x66,0xFF,0xFF,0x7E,0x3C,0x18,0x00};
unsigned char A[8]={0x18,0x24,0x42,0x81,0xFF,0x81,0x81,0x81};
unsigned char R[8]={0xFC,0x82,0x81,0x82,0xFC,0x84,0x82,0x81};
unsigned char D[8]={0xFC,0x82,0x81,0x81,0x81,0x81,0x82,0xFC};
unsigned char U[8]={0x81,0x81,0x81,0x81,0x81,0x81,0x42,0x3C};
unsigned char N[8]={0x81,0xC1,0xA1,0x91,0x89,0x85,0x83,0x81};
unsigned char I[8]={0x1C,0x08,0x08,0x08,0x08,0x08,0x08,0x1C};
unsigned char O[8]={0x3C,0x42,0x81,0x81,0x81,0x81,0x42,0x3C};

void setup()
{
matrice.shutdown(0,false);                   // arrêt du mode économie du MAX7219
matrice.setIntensity(0,8);                      // configuration de l'intensité lumineuse des led (0 à 15)
matrice.clearDisplay(0);                         // extinction de toutes les led
}

void loop()
{
for(int i=0;i<8;i++)                                   // affichage de I
  {
    matrice.setRow(0,i,I[i]);
    delay(10);
  }
delay(1000);                                            // pause d'une seconde
for(int i=0;i<8;i++)
  {
    matrice.setRow(0,i,coeur[i]);           // affichage de ♥
    delay(10);
  }
delay(1000);                                            // pause d'une seconde
for(int i=0;i<8;i++)                                  // affichage de A
  {
    matrice.setRow(0,i,A[i]);
    delay(10);
  }
delay(1000);                                           // pause d'une seconde
for(int i=0;i<8;i++)                                 // affichage de R
  {
    matrice.setRow(0,i,R[i]);
    delay(10);
  }
delay(1000);                                            // pause d'une seconde
for(int i=0;i<8;i++)                                  // affichage de D
  {
    matrice.setRow(0,i,D[i]);
    delay(10);
  }
delay(1000);                                            // pause d'une seconde
for(int i=0;i<8;i++)                                  // affichage de U
  {
    matrice.setRow(0,i,U[i]);
    delay(10);
  }
delay(1000);                                            // pause d'une seconde
for(int i=0;i<8;i++)                                  // affichage de I
  {
    matrice.setRow(0,i,I[i]);
    delay(10);
  }
delay(1000);                                    // pause d'une seconde
for(int i=0;i<8;i++)                         // affichage de N
  {
    matrice.setRow(0,i,N[i]);
    delay(10);
  }
delay(1000);                                   // pause d'une seconde
for(int i=0;i<8;i++)                         // affichage de O
  {
    matrice.setRow(0,i,O[i]);
    delay(10);
  }
delay(1000);                                 // pause d'une seconde
}

