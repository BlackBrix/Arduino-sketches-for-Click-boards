/************************************************************************
*                                                                                                                                        
*    Test du module "16x9 G Click"                                            
*                                                                    
*************************************************************************
* Description:  MIKROE-2520                                                
* Un rectangle avec effet lumineux est affiché sur la matrice.
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO
*        3. Module "16X9 G Click" inséré sur le support N°1 du shield
*        
* Bibliothèques 
*        1. https://github.com/adafruit/Adafruit_IS31FL3731
*        2. https://github.com/adafruit/Adafruit-GFX-Library
************************************************************************/

// Affectation des broches
#define SDB 10   // broche Shutdown de l'IS31FL3731

// Appel des bibliothèques
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_IS31FL3731.h>

Adafruit_IS31FL3731 matrice = Adafruit_IS31FL3731();                 // création de l'objet matrice

void setup() 
{
pinMode(SDB, OUTPUT);
digitalWrite(SDB,HIGH);                                                                        // validation de l'affichage
matrice.begin();
}

void loop() 
{
matrice.clear();                                                                                    // extinction des led de la matrice
// Dessin des 4 rectangles
matrice.drawRect(0,0, matrice.width(), matrice.height(), 128);       
delay(100);
matrice.drawRect(1,1, matrice.width()-2, matrice.height()-2, 64);
delay(100);
matrice.drawRect(2,2, matrice.width()-4, matrice.height()-4,32);
delay(100);
matrice.drawRect(3,3, matrice.width()-6, matrice.height()-6,16);
delay(100);
matrice.drawLine(4,4,11,4,8);                                                         // dessin d'une ligne
delay(1000);
matrice.drawLine(4,4,11,4,128);       // dessin de la même ligne mais avec une intensité lumineuse différente
delay(100);
matrice.drawRect(3,3, matrice.width()-6, matrice.height()-6,64);
delay(100);
matrice.drawRect(2,2, matrice.width()-4, matrice.height()-4,32);
delay(100);
matrice.drawRect(1,1, matrice.width()-2, matrice.height()-2, 16);
delay(100);
matrice.drawRect(0,0, matrice.width(), matrice.height(), 8);
delay(1000);
}

