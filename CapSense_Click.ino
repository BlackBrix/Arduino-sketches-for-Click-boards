/************************************************************************
*                                                                                                                                        
*    Test du module "CapSense Click"                                            
*                                                                    
*************************************************************************
* Description:  MIKROE-1446                                                
* L'état des deux boutons et l'évolution du slider sont affichés 
* dans le moniteur série.
* 
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO 
*        3. Module "CapSense Click" inséré sur le support N°1 du shield
*        
************************************************************************/

#include <Wire.h>                                  // appel de la bibliothèque 
#define CY8C201A0_Adresse 0x00                     // adresse I2C du CY8C201A0

//Affectation des broches
#define XRES 17 

byte bouton;
byte slider1;
byte slider2;
byte slider;

void setup()
{
  pinMode(XRES,OUTPUT);
  digitalWrite(XRES,LOW);                         
  Serial.begin(9600);                              // initialisation de la liaison série 
  Wire.begin();                                    // initialisation de la liaison I2C
  Init_CY8C201A0();                                // initialisation du CY8C201A0
// Ecriture dans le registre OUTPUT_PORT0 pour éteindre les led
   Ecriture_Registre(0x04,0x03); 
   delay(500);
// Ecriture dans le registre OUTPUT_PORT0 pour allumer les led
   Ecriture_Registre(0x04,0x00); 
   delay(500);
}
 
void loop()
{
bouton=Lecture_Registre(0x88);
Serial.print("Bouton=");
Serial.println(bouton);

Wire.beginTransmission(CY8C201A0_Adresse);      // envoi de l'adresse du CY8C201A0
Wire.write(0x8A);                               // envoi de l'adresse du registre 
Wire.endTransmission();
Wire.beginTransmission(CY8C201A0_Adresse|0x1);  // envoi de l'adresse du CY8C201A0+R
Wire.requestFrom(CY8C201A0_Adresse, 2);
  delay(10);
  if (Wire.available()<=2)                      // récupération des deux octets
  {
    slider1 = Wire.read();
    slider2 = Wire.read();
  }
Wire.endTransmission();
Serial.print("Slider1=");
Serial.println(slider1);
Serial.print("Slider2=");
Serial.println(slider2);

delay(500);
}

void Init_CY8C201A0(void)   // Initialisation du CY8C201A0
{
// Ecriture dans le registre COMMAND_REG pour accéder au mode de configuration
   Ecriture_Registre(0xA0,0x08);
// Ecriture dans le registre CS_ENABL1 pour définir les broches du slider
   Ecriture_Registre(0x07,0x1F);
// Ecriture dans le registre CS_ENABL0 pour définir les broches des boutons
   Ecriture_Registre(0x06,0x18); 
// Ecriture dans le registre GPIO_ENABLE0 pour définir les broches des led
   Ecriture_Registre(0x08,0x03);
// Ecriture dans le registre DM_STRONG0 pour valider le mode "Strong Drive"
   Ecriture_Registre(0x11,0x03);
// Ecriture dans le registre CS_SLID_CONFIG pour configurer le slider
   Ecriture_Registre(0x75,0x01);
// Ecriture dans les registres CS_SLID_MULM et CS_SLID_MULL pour configurer la résolution du slider
   Ecriture_Registre(0x77,0x30);
   Ecriture_Registre(0x78,0x00);
// Ecriture dans le registre COMMAND_REG pour mémoriser cette configuration
   Ecriture_Registre(0xA0,0x01);
   delay(250);
   Ecriture_Registre(0xA0,0x06);
   delay(250);
}

void Ecriture_Registre(byte adresse,byte donnee)
{
  Wire.beginTransmission(CY8C201A0_Adresse);      // envoi de l'adresse du CY8C201A0
  Wire.write(adresse);                            // envoi de l'adresse du registre             
  Wire.write(donnee);                             // envoi de la donnée
  Wire.endTransmission();
}

byte Lecture_Registre(byte adresse)
{
byte donnee;
Wire.beginTransmission(CY8C201A0_Adresse);      // envoi de l'adresse du CY8C201A0
Wire.write(adresse);                            // envoi de l'adresse du registre 
Wire.endTransmission();
Wire.beginTransmission(CY8C201A0_Adresse|0x1);  // envoi de l'adresse du CY8C201A0+R
Wire.requestFrom(CY8C201A0_Adresse, 1);
delay(10);
  if (Wire.available()<=1)                      // récupération de la donnée
  {
    donnee = Wire.read();
  }
Wire.endTransmission();
return donnee;
}
