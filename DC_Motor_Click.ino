/************************************************************************
*                                                                                                                                        
*    Test du module "DC Motor Click"                                            
*                                                                    
*************************************************************************
* Description:  MIKROE-1526                                                
* La commande du moteur est réalisée à l'aide du moniteur série.
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO
*        3. Module "DC Motor Click" inséré sur le support N°1 du shield
*                
************************************************************************/

// Affectation des broches
#define nSLEEP 14      
#define SELECT1 17     
#define SELECT2 10     
#define PWM 6          
#define nFAULT 2       
 
char sens=0;
char recu[3];
boolean dir;
int vitesse=0;
int vitesse_moteur;

void setup()
{
Serial.begin(9600);                                              // initialisation du moniteur série
pinMode(nSLEEP,OUTPUT);                                          // configuration des broches
pinMode(SELECT1,OUTPUT); 
pinMode(SELECT2,OUTPUT);
pinMode(PWM,OUTPUT);
pinMode(nFAULT,INPUT);
digitalWrite(SELECT1,LOW);                                      
digitalWrite(nSLEEP,HIGH);                                       // validation du DRV8833RTY  
// attachInterrupt(0, defaut, FALLING);                             // autorisation des interruptions sur la broche N°2
}


void loop()
{
Serial.println("Rentrer le sens (A: avance ou R:recule) puis Envoyer");
while (Serial.available()==0);                                   // attente du paramètre sens
sens=Serial.read();                                              // réception du paramètre sens
Serial.println("Rentrer la vitesse (000..100) puis Envoyer");
while (Serial.available()==0);                                   // attente du paramètre vitesse
for (int i=0;i<3;i++)                                            // réception du paramètre vitesse
{
recu[i]=Serial.read();
delay(10);
}
vitesse=(recu[0]-48)*100+(recu[1]-48)*10+recu[2]-48;             // reconstitution de la variable vitesse
vitesse_moteur=map(vitesse,0,100,0,255);                         // changement d'échelle pour la variable vitesse du moteur (0 à 255)
Serial.print("Le moteur tourne dans le sens ");
if (sens==65)                                                    // code ASCII de A
{
dir=LOW;
Serial.print("horaire");
}
if (sens==82)                                                    // code ASCII de R
{
dir=HIGH;
Serial.print("anti-horaire");
}
Serial.print(" avec une vitesse de ");
Serial.print(vitesse);
Serial.println(" %");
Serial.println(" ");
digitalWrite(SELECT2,dir);                                       // commande du moteur
analogWrite(PWM,vitesse_moteur);
delay(100);
}

void defaut()
{
digitalWrite(nSLEEP,LOW);                                       // blocage du DRV8833RTY  
}


