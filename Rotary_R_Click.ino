/************************************************************************
*                                                                                                                                        
*    Test du module "Rotary R Click"                                            
*                                                                    
*************************************************************************
* Description:  MIKROE-1823                                                
* L'évolution d'une variable entre 0 et 65535 est affichée dans le moniteur
* série et sur les led du module. Le bouton poussoir de l'encodeur permet de 
* faire une remise à zero.
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO
*        3. Module "Rotary R Click" inséré sur le support N°1 du shield
*        
*Attention : il faut insérer une résistance de 10K entre la broche 2 et 
*la masse.
*        
************************************************************************/

// Affectation des broches
#define SDI 11     // broche DS des 74HC595
#define SCK 13     // broche SHCP des 74HC595
#define LATCH 10   // broche STCP des 74HC595
#define SW 2       // bouton poussoir de l'encodeur
#define ENCA 6     // sortie A de l'encodeur
#define ENCB 14    // sortie B de l'encodeur

int position_encodeur=0;
boolean encodeur_A=LOW;
boolean etat_bouton=LOW;
boolean precedent_encodeur_A=LOW;
volatile unsigned int nombre=0;

void setup()
{
pinMode(SDI, OUTPUT);
pinMode(SCK, OUTPUT);
pinMode(LATCH, OUTPUT);
pinMode(SW, INPUT);
pinMode(ENCA, INPUT);
pinMode(ENCB, INPUT);
Serial.begin(9600);
attachInterrupt(0, raz, RISING);                                  // autorisation des interruptions sur la broche N°2
}

void loop()
{
Serial.println(nombre);                                           // affichage dans le moniteur série
allumage_led(nombre);                                             // appel de la fonction allumage_led
encodeur_A = digitalRead(ENCA);                                   // acquisition de l'état de la broche ENCA
  if ((precedent_encodeur_A == LOW) && (encodeur_A == HIGH))      // si l'état a changé par rapport à l'état précédent
  {
    if (digitalRead(ENCB) == HIGH)                                // si la broche ENCB est à l'état haut
    {
     nombre--;                                                    // la variable nombre diminue de 1
    } 
    else 
    {
     nombre++;                                                    // la variable nombre augmente de 1
    }  
  }
precedent_encodeur_A = encodeur_A;                                // mémorisation de l'état précédent
}

void allumage_led(unsigned int led)
{
  digitalWrite(LATCH, LOW);
  shiftOut(SDI, SCK, MSBFIRST, (led >> 8));
  shiftOut(SDI, SCK, MSBFIRST, (led & 0xFF));
  digitalWrite(LATCH, HIGH);
}

void raz()
{
nombre=0;                                                        // remise à 0 de la variable nombre
allumage_led(nombre);
}

