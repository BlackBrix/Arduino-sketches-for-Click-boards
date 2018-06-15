/************************************************************************
*                                                                                                                                        
*    Test du module "DC Motor 3 Click"                                            
*                                                                    
*************************************************************************
* Description:  MIKROE-2047                                                
* La commande du moteur est réalisée à l'aide de 4 boutons poussoirs 
* du module 2x2 Key Click.
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO
*        3. Module "DC Motor 3 Click" inséré sur le support N°1 du shield
*        4. Module "2x2 Key Click" inséré sur le support N°2 du shield
*                
************************************************************************/

// Affectation des broches module DC Motor Click 3
#define IN1 14      
#define IN2 17     
#define SLP 10     
#define PWM 6 

// Affectation des broches module 2x2 Key Click
#define BP1 15
#define BP2 16
#define BP3 9
#define BP4 5     

int vitesse=0;
void setup()
{
Serial.begin(9600);                                             // initialisation du moniteur série
pinMode(IN1,OUTPUT);                                            // configuration des broches
pinMode(IN2,OUTPUT); 
pinMode(SLP,OUTPUT);
pinMode(PWM,OUTPUT);
pinMode(BP1,INPUT);                                      
pinMode(BP2,INPUT);
pinMode(BP3,INPUT); 
pinMode(BP4,INPUT);
digitalWrite(SLP,HIGH);                                         // validation du TB6549FG
}

void loop()
{
if (digitalRead(BP1)==HIGH)                    // si BP1 est actif le moteur tourne dans le sens horaire
  {
  Serial.println("Le moteur tourne dans le sens horaire");
  digitalWrite(IN1,LOW); 
  digitalWrite(IN2,HIGH); 
  } 
else                                           // sinon le moteur tourne dans le sens anti-horaire
  {
  Serial.println("Le moteur tourne dans le sens anti-horaire");
  digitalWrite(IN1,HIGH); 
  digitalWrite(IN2,LOW); 
  }
if (digitalRead(BP2)==HIGH)                    // si BP2 est actif on augmente la vitesse 
  {
  vitesse=vitesse+10;
  if (vitesse>255)
  {
  vitesse=250;
  }
  }
if (digitalRead(BP4)==HIGH)                    // si BP4 est actif on diminue la vitesse
  {
  vitesse=vitesse-10;
  if (vitesse<0)
  {
  vitesse=0;
  }
  }
if (digitalRead(BP3)==HIGH)                    // si BP3 est actif on arrête le moteur
  {
  digitalWrite(IN1,HIGH); 
  digitalWrite(IN2,HIGH);
  vitesse=0;
  }
analogWrite(PWM,vitesse);                      // génération du signal PWM
Serial.print("Vitesse : ");                    // affichage de la vitesse
Serial.println(vitesse);
delay(600);                                    // pause pour les rebonds
}



