/************************************************************************
*                                                                                                                                        
*    Test du module "4X4 Key Click"                                            
*                                                                    
*************************************************************************
* Description:  MIKROE-1889                                               
* L'état des boutons poussoirs est affiché dans le moniteur série.
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO
*        3. Module "4x4 Key Click" inséré sur le support N°1 du shield
*        
************************************************************************/

// Affectation des broches
#define LD 10                                           
#define CLK 13                                         
#define DATA 12

int bouton[16];

void setup() 
{
  Serial.begin(9600);                       // initialisation du moniteur série
  pinMode(LD, OUTPUT);                      // configuration des broches
  pinMode(CLK, OUTPUT);
  pinMode(DATA, INPUT);
  digitalWrite(LD, HIGH);
  digitalWrite(CLK, LOW);
}

void loop()
{
 // Chargement des entrées dans le registre 74HC165
 digitalWrite(LD, LOW);                    
 delayMicroseconds(5);
 digitalWrite(LD, HIGH);
 // Lecture de la donnée série sur la broche DATA et rangement dans le tableau bouton
 for (int i=0; i <= 15; i++)
   {
    bouton[15-i] = digitalRead(DATA);
    digitalWrite(CLK, LOW);
    delayMicroseconds(5);
    digitalWrite(CLK, HIGH);   
   } 
 // Affichage des valeurs du tableau dans le moniteur série
  for (int i=0; i <= 15; i++)
   {
    Serial.print("B");
    Serial.print(i);
    Serial.print(":");
    Serial.print(bouton[i]);
    Serial.print(", ");   
   } 
 delay(1000);
 Serial.println();
}
