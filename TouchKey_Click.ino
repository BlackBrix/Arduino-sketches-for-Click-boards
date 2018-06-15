/************************************************************************
*                                                                                                                                        
*    Test du module "TouchKey Click"                                            
*                                                                    
*************************************************************************
* Description :  MIKROE-1906                                                
* L'état des boutons est affiché dans le moniteur série.
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO
*        3. Module "TouchKey Click" inséré sur le support N°1 du shield
*        
*        
************************************************************************/

// Affectation des broches
#define OUTA 17
#define OUTB 14
#define OUTC 6
#define OUTD 2

byte broche[4]={OUTA,OUTB,OUTC,OUTD};
boolean etat[4];
void setup()
{
Serial.begin(9600);                             // initialisation de la liaison série
for (int i=0;i<4;i++)
  {
  pinMode(broche[i],INPUT);                     // configuration des broches en entrée
  }
}

void loop()
{
for (int i=0; i <4; i++)
   {
    etat[i] = digitalRead(broche[i]);          // acquisition de l'état des boutons   
    Serial.print("Bouton");                    // affichage dans le moniteur série
    Serial.print(i);
    Serial.print("=");
    Serial.println(etat[i]);    
   }
delay(300); 
}

