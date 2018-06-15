/************************************************************************
*                                                                                                                                        
*    Test du module "DC Motor 5 Click"                                            
*                                                                    
*************************************************************************
* Description:  MIKROE-2699                                                
* La vitesse et le sens de rotation du moteur sont proportionnels 
* à la position de l'axe y du module Thumbstick Click
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO
*        3. Module "DC Motor 5 Click" inséré sur le support N°1 du shield
*        4. Module "Thumbstick Click" inséré sur le support N°2 du shield
*                
************************************************************************/
#include "MCP320X.h"                            // appel de la bibliothèque

// Affectation des broches du module DC Motor 5 Click
#define IN1 6      
#define IN2 2         
#define SLEEP 17              

// Affectation des broches du module Thumbstick Click
#define CS 9
#define SCK 13
#define SDI 11
#define SDO 12

#define MCP3204 4                               // référence du MPC320X

MCP320X joystick(MCP3204, SCK, SDI, SDO, CS);   // création de l'objet joystick

int y;
int vitesse;

void setup()
{
Serial.begin(9600);                             // initialisation de la liaison série
pinMode(IN1,OUTPUT);                            // configuration des broches
pinMode(IN2,OUTPUT); 
pinMode(SLEEP,OUTPUT);
pinMode(SNSO,INPUT);
digitalWrite(SLEEP,HIGH);                       // validation du DRV8701P
}

void loop()
{
y=joystick.readADC(0);                          // acquisition de la valeur y
Serial.print("Valeur y du joystick:");
Serial.println(y);
if (y>2050)
{
vitesse=map(y,2050,4092,0,255);
digitalWrite(IN2,LOW);                          // sens horaire
analogWrite(IN1, vitesse);
}
if (y<1950)
{
vitesse=map(y,1950,0,255,0);
digitalWrite(IN2,HIGH);                         // sens anti-horaire
analogWrite(IN1, vitesse);
}
if ((y<2050)&&(y>1950))
{
digitalWrite(IN1,HIGH);                         // arrêt du moteur
digitalWrite(IN2,HIGH);
}
}


