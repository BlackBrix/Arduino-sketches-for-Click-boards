/************************************************************************
*                                                                                                                                        
*    Test du module "Thumbstick Click"                                            
*                                                                    
*************************************************************************
* Description :  MIKROE-1627                                                
* La position du joystick et l'état du bouton sont affichés dans 
* le moniteur série.
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO
*        3. Module "Thumbstick Click" inséré sur le support N°1 du shield
*        
* Bibliothèque 
*        1. https://github.com/Rom3oDelta7/MCP320X
*        
************************************************************************/

// Affectation des broches
#define CS 10
#define SCK 13
#define SDI 11
#define SDO 12
#define SW 2

#define MCP3204 4   // référence du MPC320X

int x;
int y;
boolean bp;

#include "MCP320X.h"                            // appel de la librairie
MCP320X joystick(MCP3204, SCK, SDI, SDO, CS);   // création de l'objet joystick

void setup()
{
Serial.begin(9600);                             // initialisation de la liaison série
pinMode(SW,INPUT);                              // configuration de la broche SW en entrée
}

void loop()
{
bp=digitalRead(SW);                             // lecture de l'état du bouton
x=joystick.readADC(1);                          // acquisition de la valeur x
y=joystick.readADC(0);                          // acquisition de la valeur y
// Affichage dans le moniteur série
Serial.print("Valeur x du joystick:");
Serial.println(x);
Serial.print("Valeur y du joystick:");
Serial.println(y);
Serial.print("Etat du bouton:");
Serial.println(bp);
delay(500);
}

