/************************************************************************
*                                                                                                                                        
*    Test du module "Counter Click"                                            
*                                                                    
*************************************************************************
* Description:  MIKROE-1917                                                
* L'évolution du nombre de tours de l'encodeur rotatif est affichée 
* sur le moniteur série.
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO
*        3. Module "Counter Click" inséré sur le support N°1 du shield
*        4. Encodeur rotatif KY-040
*        
************************************************************************/
#include <SPI.h>        // appel de la bibliothèque

// Affectation des broches
#define CS 10           // broches de la liaison SPI
#define MOSI 11
#define MISO 12       
#define SCK 13     
#define CNT_EN 17       // entrée de validation du LS7366

// Configuration des registres
#define CLR_MDR0 0x08
#define CLR_MDR1 0x10
#define CLR_CNTR 0x20
#define CLR_STR 0x30
#define READ_MDR0 0x48
#define READ_MDR1 0x50
#define READ_CNTR 0x60
#define READ_OTR 0x68
#define READ_STR 0x70
#define WRITE_MDR1 0x90
#define WRITE_MDR0 0x88
#define WRITE_DTR 0x98
#define LOAD_CNTR 0xE0
#define LOAD_OTR 0xE4

byte valeur=0;

void setup()
{
pinMode(CS, OUTPUT);
pinMode(MOSI, OUTPUT);
pinMode(SCK, OUTPUT);
pinMode(MISO, INPUT);
digitalWrite(CNT_EN,HIGH);                    // validation du comptage

// Initialisation et configuration de la liaison SPI
SPI.begin();                                
SPI.setDataMode(SPI_MODE0);
SPI.setBitOrder(MSBFIRST);
SPI.setClockDivider(SPI_CLOCK_DIV8);
Serial.begin(9600);                            // initialisation de la liaison série
Serial.println("Initialisation.....");
// Configuration du LS7366
digitalWrite(CS,LOW);                          // début de la communication SPI
SPI.transfer(WRITE_MDR0);                      // écriture dans le registre MDR0
SPI.transfer(0x01);                            // mode quadrature 
digitalWrite(CS,HIGH);                         // fin de la communication SPI
digitalWrite(CS,LOW);                          // début de la communication SPI
SPI.transfer(WRITE_MDR1);                      // écriture dans le registre MDR1
SPI.transfer(0x03);                            // mode comptage sur un octet 
digitalWrite(CS,HIGH);                         // fin de la communication SPI
digitalWrite(CS,LOW);                          // début de la communication SPI
SPI.transfer(CLR_CNTR);                        // RAZ du compteur
digitalWrite(CS,HIGH);                         // fin de la communication SPI 
digitalWrite(CS,LOW);                          // début de la communication SPI
SPI.transfer(CLR_STR);                         // RAZ du registre d'état STR
digitalWrite(CS,HIGH);                         // fin de la communication SPI
delay(1000); 
}

void loop()
{
digitalWrite(CS,LOW);                          // début de la communication SPI
SPI.transfer(READ_CNTR);                       // lecture du compteur
valeur=SPI.transfer(0x00);
digitalWrite(CS,HIGH);                         // fin de la communication SPI 
Serial.print("Valeur : ");                     // affichage dans le moniteur série
Serial.println(valeur);  
}

