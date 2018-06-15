/************************************************************************
*                                                                                                                                        
*    Test du module "Matrix G Click"                                            
*                                                                    
*************************************************************************
* Description:  MIKROE-2246                                                
* Les nombres de 00 à 99 sont affichés sur le module. 
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO
*        3. Module "Matrix G Click" inséré sur le support N°1 du shield
*        
* Bibliothèque 
*        1. https://github.com/wayoda/LedControl
*        
************************************************************************/

// Affectation des broches
#define CSL 10
#define CSR 14
#define CLK 13
#define DIN 11

#define NB_MATRICE 1

#include "LedControl.h"                                 // appel de la librairie
LedControl matriceL=LedControl(DIN,CLK,CSL,NB_MATRICE);   // création de l'objet matriceL
LedControl matriceR=LedControl(DIN,CLK,CSR,NB_MATRICE);   // création de l'objet matriceR

// Définition des chiffres

unsigned char chiffre [10] [7]={
{0x1C,0x22,0x22,0x22,0x22,0x22,0x1C},     // 0
{0x1C,0x08,0x08,0x08,0x08,0x18,0x08},     // 1
{0x3E,0x20,0x10,0x08,0x04,0x22,0x1C},     // 2
{0x1C,0x22,0x02,0x0C,0x02,0x22,0x1C},     // 3
{0x04,0x04,0x3E,0x24,0x14,0x0C,0x04},     // 4
{0x1C,0x22,0x02,0x02,0x3C,0x20,0x3E},     // 5
{0x1C,0x22,0x22,0x3C,0x20,0x22,0x1C},     // 6
{0x10,0x10,0x10,0x08,0x04,0x02,0x3E},     // 7
{0x1C,0x22,0x22,0x1C,0x22,0x22,0x1C},     // 8
{0x1C,0x22,0x02,0x1E,0x22,0x22,0x1C},     // 9
};

void setup()
{
matriceL.shutdown(0,false);                   // arrêt du mode économie du MAX7219
matriceL.setIntensity(0,10);                  // configuration de l'intensité lumineuse des led (0 à 15)
matriceL.clearDisplay(0);                     // extinction de toutes les led
matriceR.shutdown(0,false);                   // arrêt du mode économie du MAX7219
matriceR.setIntensity(0,10);                  // configuration de l'intensité lumineuse des led (0 à 15)
matriceR.clearDisplay(0);                     // extinction de toutes les led
}

void loop()
{
 for(int j=0;j<10;j++)                              // défilement des dizaines
    {
    for(int i=0;i<7;i++)                            // affichage des chiffres sur la matrice de droite
      {
       matriceL.setRow(0,i,chiffre[j][i]);
       delay(10);
      }
    for(int j=0;j<10;j++)                           // défilement des unités
      {
      for(int i=0;i<8;i++)                          // affichage des chiffres sur la matrice de gauche
       {
       matriceR.setRow(0,i,chiffre[j][i]);
       delay(10);
       }
     delay(1000);                                   // pause d'une seconde
     }
    }
}
