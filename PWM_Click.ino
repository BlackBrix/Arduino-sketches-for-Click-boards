/************************************************************************
*                                                                                                                                        
*    Test du module "PWM Click"                                            
*                                                                    
*************************************************************************
* Description:  MIKROE-1898                                                
* La sortie CH0 du module délivre un signal carré ayant une fréquence de 50 Hz 
* et un rapport cyclique de 50%.
* 
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO 
*        3. Module "PWM Click" inséré sur le support N°1 du shield
*        
* Bibliothèques
*        1. https://github.com/adafruit/Adafruit-PWM-Servo-Driver-Library
*        
************************************************************************/

#include <Wire.h>                                               // appel des bibliothèques
#include <Adafruit_PWMServoDriver.h>

#define OE 17

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);        // création de l'objet pwm

#define frequence 50
#define numero_sortie 0

void setup()
{
  pwm.begin();
  pwm.setPWMFreq(frequence);                                    // configuration de la fréquence du signal PWM
  pinMode(OE,OUTPUT);                                           // configuration de la broche OE en sortie
  digitalWrite(OE,LOW);                                         // validation des sorties du PCA9685
}

void loop()
{
  pwm.setPWM(numero_sortie, 0, 2048);                           // génération du signal PWM
}
