/************************************************************************
*                                                                                                                                        
*    Test du module "AlphaNum R Click"                                            
*                                                                    
*************************************************************************
* Description:  MIKROE-1864                                                
* Deux caractères à choisir dans une table sont affichés sur les 
* deux afficheurs du module.
*  
* Matériel
*        1. Arduino Uno                                       
*        2. Shield "Click" pour arduino UNO
*        3. Module "AlphaNum R Click" inséré sur le support N°1 du shield
*        
************************************************************************/

// Affectation des broches
#define DIN 11    
#define CLK 13     
#define LE1 10  
#define LE2 17   
#define NUM_SEL1 2     
#define NUM_SEL2 6

const unsigned Table[51]={

 // Caractères
 //-------------------------------------------------
 // Hex        Symbole           Binaire
 //-------------------------------------------------
    0x0300,    // '-'            0b0000001100000000
    0x4000,    // '.'            0b0100000000000000
    0x2176,    // '/'            0b0000100010000000
    0x003F,    // '0'            0b0000000000111111
    0x0006,    // '1'            0b0000000000000110
    0x031B,    // '2'            0b0000001100011011
    0x030F,    // '3'            0b0000001100001111
    0x0000,    // '4'            0b0000000001000000
    0x032D,    // '5'            0b0000001100101101
    0x033D,    // '6'            0b0000001100111101
    0x0007,    // '7'            0b0000000000000111
    0x033F,    // '8'            0b0000001100111111
    0x032F,    // '9'            0b0000001100101111
    0x1040,    // ':'            0b0001000001000000
    0x0840,    // ';'            0b0000100001000000
    0x0480,    // '<'            0b0000010010000000
    0x0776,    // '='            0b0000001100001000
    0x2800,    // '>'            0b0010100000000000
    0x1223,    // '?'            0b0001001000100011
    0x027B,    // '@'            0b0000001001111011
    0x0337,    // 'A'            0b0000001100110111
    0x124F,    // 'B'            0b0001001001001111
    0x0039,    // 'C'            0b0000001100111001
    0x104F,    // 'D'            0b0001000001001111
    0x0339,    // 'E'            0b0000001100111001
    0x0331,    // 'F'            0b0000001100110001
    0x023D,    // 'G'            0b0000001000111101
    0x0336,    // 'H'            0b0000001100110110
    0x1040,    // 'I'            0b0001000001000000
    0x001E,    // 'J'            0b0000000000011110
    0x05B0,    // 'K'            0b0000010110110000
    0x0038,    // 'L'            0b0000000000111000
    0x20B6,    // 'M'            0b0010000010110110
    0x2436,    // 'N'            0b0010010000110110
    0x003F,    // 'O'            0b0000000000111111
    0x0333,    // 'P'            0b0000001100110011
    0x443F,    // 'Q'            0b0100010000111111
    0x0733,    // 'R'            0b0000011100110011
    0x032D,    // 'S'            0b0000001100101101
    0x1063,    // 'T'            0b0001000001100011
    0x003E,    // 'U'            0b0000000000111110
    0x08B0,    // 'V'            0b0000100010110000
    0x0C36,    // 'W'            0b0000110000110110
    0x2C80,    // 'X'            0b0010110010000000
    0x3080,    // 'Y'            0b0011000010000000
    0x0889,    // 'Z'            0b0000100010001001
    0x0039,    // '['            0b0000000000111001
    0x0880,    // '/'            0b0000100010000000
    0x000F,    // ']'            0b0000000000001111
    0x0081,    // '^'            0b0000000010000001
    0x0008,    // '_'            0b0000000000001000
};


void setup()
{
pinMode(DIN, OUTPUT);
pinMode(CLK, OUTPUT);
pinMode(LE1, OUTPUT);
pinMode(LE2, OUTPUT);
pinMode(NUM_SEL1, OUTPUT);
pinMode(NUM_SEL2, OUTPUT);
}

void loop()
{
  Ecriture_Segment(Conversion_caractere('F'), Conversion_caractere('P'));
}

void Ecriture_Segment(int caractere1, int caractere2)
{
      int MSB1;
      int LSB1;
      int MSB2;
      int LSB2;
// Les caractères sont codées sur 2 octets. La fonction ShiftOut ne peut envoyer qu'un octet.
// Il faut donc scinder les caractères en deux octets.
      MSB1=caractere1&0xFF00;
      for (int i=0; i < 8; i++)
      {
      MSB1=MSB1>>1;
      }
      LSB1=caractere1&0x00FF;
      MSB2=caractere2&0xFF00;
      for (int i=0; i < 8; i++)
      {
      MSB2=MSB2>>1;
      }
      LSB2=caractere2&0x00FF;
      digitalWrite(NUM_SEL1,HIGH);            // blocage des sorties des deux registres TLC5926
      digitalWrite(NUM_SEL2,HIGH);
      digitalWrite(LE1, HIGH);                // blocage des verrous des deux registres TLC5926              
      digitalWrite(LE2, HIGH); 
      shiftOut(DIN, CLK, MSBFIRST, MSB1);     // envoi du premier caractère sur le premier TLC5926    
      shiftOut(DIN, CLK, MSBFIRST, LSB1);           
      digitalWrite(LE1, LOW);                 // déblocage du verrou du premier registre            
      digitalWrite(NUM_SEL1,LOW);             // sélection du premier afficheur
      delayMicroseconds(10000);               // pause pour le multiplexage
      digitalWrite(NUM_SEL1,HIGH);            
      shiftOut(DIN, CLK, MSBFIRST, MSB2);     // envoi du second caractère sur le second TLC5926      
      shiftOut(DIN, CLK, MSBFIRST, LSB2); 
      digitalWrite(LE2, LOW);                 // déblocage du verrou du second registre 
      digitalWrite(NUM_SEL2,LOW);             // sélection du second afficheur
      delayMicroseconds(10000);               // pause pour le multiplexage
      digitalWrite(NUM_SEL2,HIGH);     
}

unsigned Conversion_caractere(char caractere)
{
  if ((caractere >= '-') && (caractere <= '_'))
    return Table[caractere-'-'];
  else
    return 0;
}

