#include <Adafruit_CircuitPlayground.h>
#include <Wire.h>
#include <SPI.h>
const uint8_t spREADY[] PROGMEM = {0x6A,0xB4,0xD9,0x25,0x4A, 0xE5, 0xDB,0xD9, 0x8D, 0xB1, 0xB2, 0x45, 0x9A, 0xF6, 0xD8, 0x9F, 0xAE, 0x26, 0xD7, 0x30, 0xED, 0x72, 0xDA, 0x9E, 0xCD, 0x9C, 0x6D, 0xC9, 0x6D, 0x76, 0xED, 0xFA, 0xE1, 0x93, 0x8D, 0xAD, 0x51, 0x1F,0xC7, 0xD8, 0x13, 0x8B, 0x5A, 0x3F, 0x99, 0x4B, 0x39, 0x7A, 0x13, 0xE2, 0xE8, 0x3B, 0xF5, 0xCA, 0x77, 0x7E, 0xC2, 0xDB, 0x2B, 0x8A, 0xC7, 0xD6, 0xFA, 0x7F,};
const uint8_t spSTART[] PROGMEM = { 0x02, 0xF8, 0x49, 0xCC, 0x00, 0xBF, 0x87, 0x3B, 0xE0, 0xB7, 0x60, 0x03, 0xFC, 0x9A, 0xAA, 0x80, 0x3F, 0x92, 0x11, 0x30, 0x29, 0x9A, 0x02, 0x86, 0x34, 0x5F, 0x65, 0x13, 0x69, 0xE2, 0xDA, 0x65, 0x35, 0x59, 0x8F, 0x49, 0x59, 0x97, 0xD5, 0x65, 0x7D, 0x29, 0xA5, 0xDE, 0x56, 0x97, 0xF5, 0x85, 0x8E, 0xE4, 0x5D, 0x6D, 0x0E, 0x23, 0x39, 0xDC, 0x79, 0xD4, 0xA5, 0x35, 0x75, 0x72, 0xEF, 0x51, 0x95, 0xE9, 0x38, 0xE6, 0xB9, 0x4B, 0x5D, 0x1A, 0x26, 0x6B, 0x3B, 0x46, 0xE0, 0x14, 0xA5, 0x2A, 0x54, 0x03, 0x40, 0x01, 0x43, 0xBA, 0x31, 0x60, 0x73, 0x35, 0x04, 0x4E, 0x51, 0xAA, 0x42, 0x35, 0xFE, 0x1F };

int LEDM[10][4] = {  //LED MAP FOR LEVELS
  { 0, 255, 0, 255 },
  { 1, 0, 0, 0 },
  { 2, 0, 0, 0 },
  { 3, 0, 0, 0 },
  { 4, 0, 0, 0 },
  { 5, 0, 0, 0 },
  { 6, 0, 0, 0 },
  { 7, 0, 0, 0 },
  { 8, 0, 0, 0 },
  { 9, 255, 0, 255 }
};
int LEDM1[10][4] = {
  { 0, 255, 0, 255 },
  { 1, 0, 30, 0 },
  { 2, 0, 30, 0 },
  { 3, 0, 30, 0 },
  { 4, 0, 30, 0 },
  { 5, 0, 30, 0 },
  { 6, 0, 30, 0 },
  { 7, 0, 30, 0 },
  { 8, 0, 30, 0 },
  { 9, 255, 0, 255 }
};
int LEDM2[10][4] = {
  { 0, 255, 0, 255 },
  { 1, 30, 0, 0 },
  { 2, 30, 0, 0 },
  { 3, 30, 0, 0 },
  { 4, 30, 0, 0 },
  { 5, 30, 0, 0 },
  { 6, 30, 0, 0 },
  { 7, 30, 0, 0 },
  { 8, 30, 0, 0 },
  { 9, 255, 0, 255 }
};
int LEDM3[10][4] = {
  { 0, 255, 0, 255 },
  { 1, 20, 20, 0 },
  { 2, 20, 20, 0 },
  { 3, 20, 20, 0 },
  { 4, 20, 20, 0 },
  { 5, 20, 20, 0 },
  { 6, 20, 20, 0 },
  { 7, 20, 20, 0 },
  { 8, 20, 20, 0 },
  { 9, 255, 0, 255 }
};
int LEDM4[10][4] = {
  { 0, 255, 0, 255 },
  { 1, 0, 0, 50 },
  { 2, 0, 0, 50 },
  { 3, 0, 0, 50 },
  { 4, 0, 0, 50 },
  { 5, 0, 0, 50 },
  { 6, 0, 0, 50 },
  { 7, 0, 0, 50 },
  { 8, 0, 0, 50 },
  { 9, 255, 0, 255 }
};
int LEDM5[10][4] = {
  { 0, 200, 0, 0 },
  { 1, 200, 0, 0 },
  { 2, 200, 0, 0 },
  { 3, 200, 0, 0 },
  { 4, 200, 0, 0 },
  { 5, 255, 255, 255 },
  { 6, 255, 255, 255 },
  { 7, 255, 255, 255 },
  { 8, 255, 255, 255 },
  { 9, 255, 255, 255 }
};
int LEDM6[10][4] = {
  { 0, 200, 0, 0 },
  { 1, 200, 0, 0 },
  { 2, 200, 0, 0 },
  { 3, 200, 0, 0 },
  { 4, 200, 0, 0 },
  { 5, 200, 0, 0 },
  { 6, 200, 0, 0 },
  { 7, 200, 0, 0 },
  { 8, 200, 0, 0 },
  { 9, 200, 0, 0 }
};
int LEDM7[10][4] = {
  { 0, 100, 0, 0 },
  { 1, 0, 100, 0 },
  { 2, 0, 0, 100 },
  { 3, 200, 0, 0 },
  { 4, 200, 100, 0 },
  { 5, 200, 100, 0 },
  { 6, 200, 0, 0 },
  { 7, 0, 0, 100 },
  { 8, 0, 100, 0 },
  { 9, 100, 0, 0 }
};
volatile int EXP = 0;       //Record EXP for LEVEL UPS
volatile int LVL = 1;       //RECORDS LEVEL OF PLAYER
volatile int PlayerAT = 1;  //USED TO DETERMINE PLAYER ATTACK
volatile int PlayerHP = 5;  //USED TO DETERMINE PLAYER HP
volatile int LEVEL = 1;     // USED TO KNOW WHAT LEVEL PLAYER IS ON
int MonsterAT = 1;          // All MonsterHP and AT varries depending after level but the set standard is here
int MonsterHP = 3;
int MonsterAT1 = 1;
int MonsterHP1 = 3;
int MonsterAT2 = 1;
int MonsterHP2 = 1;
int MonsterAT3 = 1;
int MonsterHP3 = 1;
int ACOIN;  //ALL Coins are Used for Monster Movement
int BCOIN;
int CCOIN;
int DCOIN;
int j = 0;     //Final Boss ROUND Counter
int MAP = 11;  // MAP Standard VALUE used for choosing LEVEL
const byte interruptPin1 = 4;
const byte interruptPin2 = 5;
const byte interruptPin3 = 7;
volatile bool B1Flag = false;
volatile bool B2Flag = false;
volatile bool BF1Flag = false;
volatile bool BF2Flag = false;
volatile bool SFlag = false;
volatile bool B3Flag = false;
volatile bool TFlag = false;
volatile bool PlayerSword = false;
int MOVE = 7;
int GOLD = 1;
int Sword = 1;
float midi[127];
int A_four = 440;
int YES1[4] = { 60, 64, 67, 71 };
int YES2[4] = { 72, 76, 79, 83 };
int YES3[4] = { 79, 76, 72, 71 };
int YES4[3] = { 67, 64, 60 };
void setup() {
  CircuitPlayground.begin();
  randomSeed(analogRead(0));
  Serial.begin(9600);
  MAP = 1;
  attachInterrupt(digitalPinToInterrupt(interruptPin2), Button1, FALLING);
  attachInterrupt(digitalPinToInterrupt(interruptPin1), Button2, FALLING);
  attachInterrupt(digitalPinToInterrupt(interruptPin3), Switch, CHANGE);

  CircuitPlayground.speaker.say(spREADY);
  delay(500);
  CircuitPlayground.speaker.say(spSTART);
  generateMIDI();
  int ACOIN = 5;  //PLacement on LED MAp but is also changed in Case statements
  int BCOIN = 6;
  int CCOIN = 6;
}

void loop() {
  int MON = random(1, 100);  //MONS are for Monster RNG for hitting and missing PLayer
  int MON1 = random(1, 100);
  int MON2 = random(1, 100);
  int rant = random(50, 90);   // rant's are for random notes
  int rat = random(100, 500);  // rat's are for random times for the notes
  int rant1 = random(50, 90);
  int rat1 = random(100, 500);
  int rant2 = random(50, 90);
  int rat2 = random(100, 500);


  if (MonsterHP < 6) {  //All the code involving the COINS and MOnsterHP is for Monster movement, 3 Basic monsters and 1 Boss monster
    if (MON > 50) {
      if (ACOIN > 9) {
        ACOIN == 8;
      } else {
        ACOIN++;
      }
      delay(200);
    } else if (MON <= 50) {
      if (ACOIN <= 1) {
        ACOIN == 2;
      } else {
        ACOIN--;
      }
      delay(200);
    }
  } else if (MonsterHP >= 6) {
    ACOIN = 0;
  }
  if (MonsterHP1 < 6) {
    if (MON1 > 50) {
      if (BCOIN > 9) {
        BCOIN == 8;
      } else {
        BCOIN++;
      }
      delay(200);
    } else if (MON1 <= 50) {
      if (BCOIN <= 1) {
        BCOIN == 2;
      } else {
        BCOIN--;
      }
      delay(200);
    }
  } else if (MonsterHP1 >= 6) {
    BCOIN = 0;
  }
  if (MonsterHP2 < 6) {
    if (MON2 > 50) {
      if (CCOIN > 9) {
        CCOIN == 8;
      } else {
        CCOIN++;
      }
      delay(200);
    } else if (MON2 <= 50) {
      if (CCOIN <= 1) {
        CCOIN == 2;
      } else {
        CCOIN--;
      }
      delay(200);
    }
  } else if (MonsterHP2 >= 6) {
    CCOIN = 0;
  }
  if (MonsterHP3 < 6) {
    if (MON2 > 60) {
      if (DCOIN > 9) {
        DCOIN == 8;
      } else {
        DCOIN++;
      }
      delay(200);
    } else if (MON2 <= 60) {
      if (DCOIN <= 1) {
        DCOIN == 2;
      } else {
        DCOIN--;
      }
      delay(400);
    }
  } else if (MonsterHP3 >= 6) {
    DCOIN = 0;
  }
  if (MAP <= 5) {  //USED for player movement on LED MAP
                   //if(!SFlag){ //TOOL USED FOR Developer movement
    B1Flag = false;
    B2Flag = false;
    if (BF1Flag) {
      if (MOVE >= 8) {
        MOVE = 8;
      } else {
        MOVE++;
      }
      BF1Flag = false;
    }
    if (BF2Flag) {
      if (MOVE <= 1) {
        MOVE = 1;
      } else {
        MOVE--;
      }

      BF2Flag = false;
    }
    // }else if(SFlag){  //DEVOLPERTOOLS For level movement
    //   BF1Flag = false;
    //   BF2Flag = false;
    //   if(B1Flag){
    //     delay(100);
    //     if(MAP>=5){
    //       MAP=5;
    //     }else{
    //       MAP++;
    //     }
    //     B1Flag = false;
    //   }
    //   if(B2Flag){
    //     delay(100);
    //     if(MAP<=1){
    //       MAP=1;
    //     }else{
    //       MAP--;
    //     }
    //     B2Flag = false;
    //   }
    // }
  }
  switch (MAP) {
    case 1:
      for (int i = 0; i < sizeof(LEDM) / sizeof(LEDM[0]); i++) {
        CircuitPlayground.setPixelColor(LEDM[i][0], LEDM[i][1], LEDM[i][2], LEDM[i][3]);  //LOADS LED MAP FOR LEVEL 1
      }
      CircuitPlayground.setPixelColor(MOVE, 255, 255, 255);  // LOADS PLAYER LED
      if (MonsterHP < 6) {
        CircuitPlayground.setPixelColor(ACOIN, 200, 0, 0);  //LOADS MONSTER LED
      }
      if (TFlag) {
        CircuitPlayground.setPixelColor(GOLD, 100, 100, 0);  //WILL LOAD AFTER 1 MONSTERS DEFEAT
      }
      if (GOLD == MOVE) {  // LOADS PLACEMENT OF MONSTERS AND GOLD AND REGENS 1 OF THE PLAYER'S HP SETS MONSTER HP and RECORDS LEVEL then moves to next level
        for (int i = 0; i < sizeof(YES4) / sizeof(int); i++) {
          CircuitPlayground.playTone(midi[YES1[i]], 70);
          CircuitPlayground.playTone(midi[YES2[i]], 70);
        }
        TFlag = false;
        PlayerHP++;
        MonsterHP1 = 3;
        GOLD = 8;
        BCOIN = 8;
        MAP = 2;
        LEVEL++;
      }
      if (MOVE == ACOIN) {  // DOES MONSTER BATTLE IF CONDITION IS MET
        CircuitPlayground.playTone(100, 300);


        MAP = 6;
      }

      break;
    case 2:
      for (int i = 0; i < sizeof(LEDM1) / sizeof(LEDM1[0]); i++) {
        CircuitPlayground.setPixelColor(LEDM1[i][0], LEDM1[i][1], LEDM1[i][2], LEDM1[i][3]);
      }
      CircuitPlayground.setPixelColor(MOVE, 255, 255, 255);
      if (MonsterHP1 < 6) {
        CircuitPlayground.setPixelColor(BCOIN, 200, 0, 100);
      }
      if (TFlag) {
        CircuitPlayground.setPixelColor(GOLD, 100, 100, 0);
      }
      if (MOVE == BCOIN) {
        CircuitPlayground.playTone(100, 300);
        MAP = 7;
      }
      if (GOLD == MOVE) {
        for (int i = 0; i < sizeof(YES4) / sizeof(int); i++) {
          CircuitPlayground.playTone(midi[YES1[i]], 70);
          CircuitPlayground.playTone(midi[YES2[i]], 70);
        }
        TFlag = false;
        PlayerHP++;
        MonsterHP = 1;
        MonsterHP1 = 2;
        GOLD = 1;
        ACOIN = 1;
        BCOIN = 4;
        MAP = 3;
        LEVEL++;
      }

      break;
    case 3:
      for (int i = 0; i < sizeof(LEDM2) / sizeof(LEDM2[0]); i++) {
        CircuitPlayground.setPixelColor(LEDM2[i][0], LEDM2[i][1], LEDM2[i][2], LEDM2[i][3]);
      }
      CircuitPlayground.setPixelColor(MOVE, 255, 255, 255);
      if (MonsterHP < 6) {
        CircuitPlayground.setPixelColor(ACOIN, 200, 0, 0);
      }
      if (MonsterHP1 < 6) {
        CircuitPlayground.setPixelColor(BCOIN, 200, 0, 100);
      }
      if (TFlag) {
        CircuitPlayground.setPixelColor(GOLD, 100, 100, 0);
      }
      if (MOVE == ACOIN) {
        CircuitPlayground.playTone(100, 300);
        MAP = 6;
      }
      if (MOVE == BCOIN) {
        CircuitPlayground.playTone(100, 300);
        MAP = 7;
      }
      if (GOLD == MOVE) {
        for (int i = 0; i < sizeof(YES4) / sizeof(int); i++) {
          CircuitPlayground.playTone(midi[YES1[i]], 70);
          CircuitPlayground.playTone(midi[YES2[i]], 70);
        }
        TFlag = false;
        PlayerHP++;
        MonsterHP = 1;
        MonsterHP1 = 2;
        MonsterHP2 = 2;
        GOLD = 8;
        ACOIN = 8;
        BCOIN = 7;
        CCOIN = 6;
        MAP = 4;
        LEVEL++;
      }
      break;
    case 4:
      for (int i = 0; i < sizeof(LEDM2) / sizeof(LEDM2[0]); i++) {
        CircuitPlayground.setPixelColor(LEDM2[i][0], LEDM2[i][1], LEDM2[i][2], LEDM2[i][3]);
      }
      CircuitPlayground.setPixelColor(MOVE, 255, 255, 255);
      if (MonsterHP < 6) {
        CircuitPlayground.setPixelColor(ACOIN, 200, 0, 0);
      }
      if (MonsterHP1 < 6) {
        CircuitPlayground.setPixelColor(BCOIN, 200, 0, 100);
      }
      if (MonsterHP2 < 6) {
        CircuitPlayground.setPixelColor(CCOIN, 100, 0, 200);
      }
      if (TFlag) {
        CircuitPlayground.setPixelColor(GOLD, 100, 100, 0);
      }
      if (MOVE == ACOIN) {
        CircuitPlayground.playTone(100, 300);
        MAP = 6;
      }
      if (MOVE == BCOIN) {
        CircuitPlayground.playTone(100, 300);
        MAP = 7;
      }
      if (MOVE == CCOIN) {
        CircuitPlayground.playTone(100, 300);
        MAP = 8;
      }
      if (GOLD == MOVE) {
        for (int i = 0; i < sizeof(YES4) / sizeof(int); i++) {
          CircuitPlayground.playTone(midi[YES1[i]], 70);
          CircuitPlayground.playTone(midi[YES2[i]], 70);
        }
        TFlag = false;
        PlayerHP++;
        MonsterHP3 = -13;
        DCOIN = 1;
        MAP = 5;
        LEVEL++;
      }
      break;
    case 5:
      for (int i = 0; i < sizeof(LEDM4) / sizeof(LEDM4[0]); i++) {
        CircuitPlayground.setPixelColor(LEDM4[i][0], LEDM4[i][1], LEDM4[i][2], LEDM4[i][3]);
      }
      CircuitPlayground.setPixelColor(MOVE, 255, 255, 255);
      CircuitPlayground.setPixelColor(Sword, 200, 200, 100);  //USED to help defeat boss by adding extra Attack to PLayer Attack power
      if (MonsterHP3 < 6) {
        CircuitPlayground.setPixelColor(DCOIN, 200, 0, 100);
      }
      if (MOVE == DCOIN) {
        CircuitPlayground.playTone(100, 300);
        MAP = 9;
      }
      if (Sword == MOVE) {
        for (int i = 0; i < sizeof(YES4) / sizeof(int); i++) {  // Equips sword
          CircuitPlayground.playTone(midi[YES1[i]], 70);
          CircuitPlayground.playTone(midi[YES2[i]], 70);
        }
        PlayerSword = true;
        Sword = -1;
      }
      break;
    case 6:
      if (MON > 75) {  // MONSter has a 25% chace to deal 1 damage to player
        PlayerHP--;
        Serial.println("HIT");
        CircuitPlayground.playTone(1000, 50);
      } else if (MON <= 75) {
        Serial.println("MISS");
        CircuitPlayground.playTone(100, 50);
      }
      if (B3Flag) {  // When the player attacks deals damage to monster and if level exp high enough you can deal more damage
        delay(50);
        CircuitPlayground.playTone(700, 50);

        MonsterHP++;
        if (PlayerAT == 2) {
          MonsterHP++;
        }
        if (PlayerAT == 3) {
          MonsterHP++;
          MonsterHP++;
        }

        if (MonsterHP >= 6) {  // When monster is defeated regen 1 HP for player add 1 exp if exp high enough lvl up
          CircuitPlayground.clearPixels();
          EXP++;
          PlayerHP++;
          if (EXP == 3) {
            LVL++;
            Serial.print("LVL:");
            Serial.println(LVL);
            PlayerAT = 2;
            PlayerHP = 5;
            delay(50);
            for (int i = 0; i < sizeof(YES4) / sizeof(int); i++) {
              CircuitPlayground.playTone(midi[YES1[i]], 100);
              CircuitPlayground.playTone(midi[YES2[i]], 100);
            }
          }
          if (EXP == 6) {
            LVL++;
            Serial.print("LVL:");
            Serial.println(LVL);
            PlayerAT = 3;
            PlayerHP = 7;
            delay(50);
            for (int i = 0; i < sizeof(YES4) / sizeof(int); i++) {
              CircuitPlayground.playTone(midi[YES1[i]], 100);
              CircuitPlayground.playTone(midi[YES2[i]], 100);
            }
          }

          MAP = LEVEL;  //goes back to previous level
          TFlag = true;
        }
        B3Flag = false;
      }
      if (PlayerHP == 0) {  // Goes to game over screen if PLayer HP is 0
        CircuitPlayground.clearPixels();
        CircuitPlayground.playTone(50, 2000);
        MAP = 11;
      }
      for (int i = 0; i < sizeof(LEDM5) / sizeof(LEDM5[0]); i++) {
        CircuitPlayground.setPixelColor(LEDM5[i][0], LEDM5[i][1], LEDM5[i][2], LEDM5[i][3]);  //LED BACK LIGHT
      }
      for (int i = MonsterHP - 1; i < 5; i++) {
        CircuitPlayground.setPixelColor(i, 200, 0, 100);  //MONSTER HP LEDS
      }
      for (int i = PlayerHP + 4; i > 4; i--) {
        CircuitPlayground.setPixelColor(i, 255, 100, 0);  //PLAYER HP LEDS
      }

      delay(500);

      break;
    case 7:
      if (MON1 > 65) {  //35% to deal damage and heal 1 HP
        PlayerHP--;
        MonsterHP1--;


        Serial.println("HIT");
        CircuitPlayground.playTone(1000, 50);
      } else if (MON1 <= 65) {
        Serial.println("MISS");

        CircuitPlayground.playTone(100, 50);
      }
      if (B3Flag) {
        delay(50);
        CircuitPlayground.playTone(700, 50);

        MonsterHP1++;
        if (PlayerAT == 2) {
          MonsterHP++;
        }
        if (PlayerAT == 3) {
          MonsterHP++;
          MonsterHP++;
        }


        if (MonsterHP1 >= 6) {
          EXP++;
          PlayerHP++;
          if (EXP == 3) {
            LVL++;
            Serial.print("LVL:");
            Serial.println(LVL);
            PlayerAT = 2;
            PlayerHP = 5;
            delay(50);
            for (int i = 0; i < sizeof(YES4) / sizeof(int); i++) {
              CircuitPlayground.playTone(midi[YES1[i]], 100);
              CircuitPlayground.playTone(midi[YES2[i]], 100);
            }
          }
          if (EXP == 6) {
            LVL++;
            Serial.print("LVL:");
            Serial.println(LVL);
            PlayerAT = 3;
            PlayerHP = 7;
            delay(50);
            for (int i = 0; i < sizeof(YES4) / sizeof(int); i++) {
              CircuitPlayground.playTone(midi[YES1[i]], 100);
              CircuitPlayground.playTone(midi[YES2[i]], 100);
            }
          }
          MAP = LEVEL;
          TFlag = true;
        }
        B3Flag = false;
      }
      if (PlayerHP == 0) {
        CircuitPlayground.clearPixels();
        CircuitPlayground.playTone(50, 2000);
        MAP = 11;
      }
      for (int i = 0; i < sizeof(LEDM5) / sizeof(LEDM5[0]); i++) {
        CircuitPlayground.setPixelColor(LEDM5[i][0], LEDM5[i][1], LEDM5[i][2], LEDM5[i][3]);
      }
      for (int i = MonsterHP1 - 1; i < 5; i++) {
        CircuitPlayground.setPixelColor(i, 200, 0, 200);
      }
      for (int i = PlayerHP + 4; i > 4; i--) {
        CircuitPlayground.setPixelColor(i, 255, 200, 0);
      }

      delay(700);
      break;
    case 8:
      if (MON2 > 50) {  //50% to deal damage and heal 1 HP or Heal 1HP
        PlayerHP--;
        MonsterHP2--;



        Serial.println("HIT");
        CircuitPlayground.playTone(1000, 50);
      } else if (MON2 <= 50) {
        Serial.println("MISS");
        MonsterHP2--;
        CircuitPlayground.playTone(100, 50);
      }
      if (B3Flag) {
        delay(50);
        CircuitPlayground.playTone(700, 50);

        MonsterHP2++;
        if (PlayerAT == 2) {
          MonsterHP2++;
        }
        if (PlayerAT == 3) {
          MonsterHP++;
          MonsterHP++;
        }


        if (MonsterHP2 >= 6) {
          EXP++;
          PlayerHP++;
          if (EXP == 3) {
            LVL++;
            Serial.print("LVL:");
            Serial.println(LVL);
            PlayerAT = 2;
            PlayerHP = 5;
            delay(50);
            for (int i = 0; i < sizeof(YES4) / sizeof(int); i++) {
              CircuitPlayground.playTone(midi[YES1[i]], 100);
              CircuitPlayground.playTone(midi[YES2[i]], 100);
            }
          }
          if (EXP == 6) {
            LVL++;
            Serial.print("LVL:");
            Serial.println(LVL);
            PlayerAT = 3;
            PlayerHP = 7;
            delay(50);
            for (int i = 0; i < sizeof(YES4) / sizeof(int); i++) {
              CircuitPlayground.playTone(midi[YES1[i]], 100);
              CircuitPlayground.playTone(midi[YES2[i]], 100);
            }
          }
          MAP = LEVEL;
          TFlag = true;
        }
        B3Flag = false;
      }
      if (PlayerHP == 0) {
        CircuitPlayground.clearPixels();
        CircuitPlayground.playTone(50, 2000);
        MAP = 11;
      }
      for (int i = 0; i < sizeof(LEDM5) / sizeof(LEDM5[0]); i++) {
        CircuitPlayground.setPixelColor(LEDM5[i][0], LEDM5[i][1], LEDM5[i][2], LEDM5[i][3]);
      }
      for (int i = MonsterHP2 - 1; i < 5; i++) {
        CircuitPlayground.setPixelColor(i, 200, 0, 200);
      }
      for (int i = PlayerHP + 4; i > 4; i--) {
        CircuitPlayground.setPixelColor(i, 255, 200, 0);
      }

      delay(700);
      break;
    case 9:
      if (j = 4) {        // 4 turns to deal damage
        if (MON2 > 70) {  //30% chance to deal 2 damage or heals 1HP
          PlayerHP--;
          PlayerHP--;



          Serial.println("HIT");
          CircuitPlayground.playTone(1000, 50);
        } else if (MON2 <= 70) {
          Serial.println("MISS");
          MonsterHP3--;
          CircuitPlayground.playTone(100, 50);
        }
        if (B3Flag) {
          delay(50);
          CircuitPlayground.playTone(700, 50);

          MonsterHP3++;
          if (PlayerAT == 2) {
            MonsterHP3++;
          }
          if (PlayerSword) {
            MonsterHP3++;
            MonsterHP3++;
            MonsterHP3++;
          }

          if (MonsterHP3 >= 6) {  // On Boss death goes to MAP 10 the Celebration stage

            MAP = 10;
          }
          B3Flag = false;
        }
        if (PlayerHP <= 0) {
          CircuitPlayground.clearPixels();
          CircuitPlayground.playTone(50, 2000);
          MAP = 11;
        }
        for (int i = 0; i < sizeof(LEDM5) / sizeof(LEDM5[0]); i++) {
          CircuitPlayground.setPixelColor(LEDM5[i][0], LEDM5[i][1], LEDM5[i][2], LEDM5[i][3]);
        }
        for (int i = MonsterHP3 - 1; i < 5; i++) {
          CircuitPlayground.setPixelColor(i, 200, 0, 200);
        }
        for (int i = PlayerHP + 4; i > 4; i--) {
          CircuitPlayground.setPixelColor(i, 255, 200, 0);
        }

        delay(700);
        j++;
      } else {
        j = 0;
        MAP = LEVEL;
        DCOIN--;  // moves away from player when returning back to level
        DCOIN--;
      }

      break;
    case 10:

      for (int i = 0; i < sizeof(LEDM7) / sizeof(LEDM7[0]); i++) {
        CircuitPlayground.setPixelColor(LEDM7[i][0], LEDM7[i][1], LEDM7[i][2], LEDM7[i][3]);
      }
      for (int i = 0; i < 2; i++) {  // PLays random music
        CircuitPlayground.playTone(midi[rant], rat);
        CircuitPlayground.playTone(midi[rant1], rat1);
        CircuitPlayground.playTone(midi[rant2], rat2);
      }




      break;
    case 11:
      for (int i = 0; i < sizeof(LEDM6) / sizeof(LEDM6[0]); i++) {
        CircuitPlayground.setPixelColor(LEDM6[i][0], LEDM6[i][1], LEDM6[i][2], LEDM6[i][3]);
      }
      for (int i = 0; i < sizeof(YES4) / sizeof(int); i++) {  //Game over music
        CircuitPlayground.playTone(midi[YES3[i]], 500);
        CircuitPlayground.playTone(midi[YES4[i]], 500);
      }
      break;
  }
}
void Button1() {
  //B1Flag = CircuitPlayground.leftButton();
  B1Flag = true;
  BF1Flag = true;
  B3Flag = true;
  //Serial.print("BFlag is: ");
  //Serial.println(MAP);
}
void Button2() {
  // B2Flag = CircuitPlayground.rightButton();
  B2Flag = true;
  BF2Flag = true;
  //Serial.print("BFlag is: ");
  //Serial.println(MAP);
}
void Switch() {  //used for DEV tools
  // SFlag = CircuitPlayground.slideSwitch();
  //Serial.print("SWT: ");
  //Serial.println(SFlag);
}
void generateMIDI() {
  for (int x = 0; x < 127; ++x) {
    midi[x] = (A_four / 32.0) * pow(2.0, ((x - 9.0) / 12.0));
    Serial.println(midi[x]);
  }
}
