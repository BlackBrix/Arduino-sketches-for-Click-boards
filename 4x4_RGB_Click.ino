/************************************************************************
*                                                                                                                                        
*    Test du module "4X4 RGB Click"                                            
*                                                                    
*************************************************************************
* Description:  MIKROE-1881                                               
* Des effets lumineux sont générés sur les led du module.
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO
*        3. Module "4x4 RGB Click" inséré sur le support N°1 du shield
*        
* Bibliothèque
*        1. https://github.com/adafruit/Adafruit_NeoPixel
************************************************************************/

// Affectation des broches
#define sortie 17                                             // DIN du module
#define nb_led 16                                             // le module comporte 16 led

#include <Adafruit_NeoPixel.h>                                // appel de la bibliothèque
Adafruit_NeoPixel module = Adafruit_NeoPixel(nb_led, sortie, NEO_GRB + NEO_KHZ800);  // création de l'objet module

float j, f, k;

void setup() 
{
  module.begin();                                             // initialisation de module
}

void loop()
{
   for(int t = 0; t < 16; t++)                                // allumage successif des 16 led
  {
    int rouge = 64 * (1 + sin(t / 2.0 + j / 4.0) );           // variation de la couleur rouge  
    int vert = 64 * (1 + sin(t / 1.0 + f / 9.0 + 2.1) );      // variation de la couleur verte
    int bleu = 64 * (1 + sin(t / 3.0 + k / 14.0 + 4.2) );     // variation de la couleur bleu
    module.setPixelColor(t, rouge, vert, bleu);               // allumage de la led t avec les couleurs rouge, verte et bleu
  }
  module.show();                                              // rafraichissement des led
  j += random(1, 6) / 6.0;                                    // changement aléatoire des variables j, f et k
  f += random(1, 6) / 6.0;
  k += random(1, 6) / 6.0;
}
