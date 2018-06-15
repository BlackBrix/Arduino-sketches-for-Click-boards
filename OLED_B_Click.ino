/************************************************************************
*                                                                                                                                        
*    Test du module "OLED B Click"                                            
*                                                                    
*************************************************************************
* Description:  MIKROE-1650                                                
* Un nuage de points est affiché aléatoirement puis le message LEXTRONIC 
* apparaît et clignote 3 fois
* 
* Matériel
*        1. Arduino Uno                                       
*        2. Module "OLED B Click" 
*        3. Shifter Level TXB0108
*        
* Bibliothèques 
*        1. https://github.com/adafruit/Adafruit_SSD1306
*        2. https://github.com/adafruit/Adafruit-GFX-Library
*  
************************************************************************/

// Affectation des broches 
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13

// Appel des bibliothèques
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>

Adafruit_SSD1306 afficheur(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);    //création de l'objet

int x;
int y;

void setup(void) 
{
   afficheur.begin();                // initialisation de l'objet afficheur
   afficheur.display();              // rafraichissement de l'écran
   afficheur.clearDisplay();         // effacement de l'écran
   afficheur.display();              // rafraichissement de l'écran
}


void loop() 
{
   afficheur.clearDisplay();                          // effacement de l'écran
   afficheur.display();                               // rafraichissement de l'écran          
   for (int i=0; i <= 50; i++)                        // apparition du nuage de points
   {
      x=random(128);                                  // x prend une valeur aléatoire comprise entre 0 et 128
      y=random(32);                                   // y prend une valeur aléatoire comprise entre 0 et 32
      afficheur.drawPixel(x, y, WHITE);               // affichage d'un pixel en (x,y)
      afficheur.display();                            // rafraichissement de l'écran
      delay(50);                                      // pause de 50 ms
   }  
   afficheur.setTextSize(1);                          // configuration de la taille des caractères
   afficheur.setTextColor(WHITE);         
   afficheur.setCursor(40,20);                        // placement du curseur en x=40 et y=20
   afficheur.println("LEXTRONIC");                    // écriture de LEXTRONIC
   afficheur.display();                               // rafraichissement de l'écran  
   delay(1000);
   for (int i=0; i <= 3; i++)                         // clignotement du message
   {
     afficheur.setCursor(40,20); 
     afficheur.println("LEXTRONIC");
     afficheur.display();
     delay(1000);
     afficheur.clearDisplay();
     afficheur.display();
     delay(500);
   } 
}
