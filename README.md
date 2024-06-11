# RPGLEDAdaFruit
ENGR 103 Final Project Game
##A bit about myself...
I like RPG's and I like pizza
My game’s intended purpose is to fight enemies to progress to the next stage eventually getting to a boss fight.
Present Rules:
  My game’s intended purpose is to fight enemies to progress to the next stage eventually getting to a boss fight. You can decide to level up or try to sneak past the monster to eventually get to a boss.
  
User Inputs/Outputs:
INPUTS:
This game has 3 inputs.
2 of the ISR’s are the Left and Right buttons D4 and D5, these buttons control the LED players movement, Right going right Left going left, Button1 Controls the Attack of the Player as well.
ISR RAW:
Switch: Slide switch equals the volatile bool “SFlag”.
Button1:Turns the Following volatile bool true “B1Flag” and “BF1Flag” and "B3Flag".
Button2:Turns the Following volatile bool true “B2Flag” and “BF2Flag”.

OUTPUTS:
The Outputs of the code are The LEDs/Color of LEDs, Speaker for TTS, and Sounds from the tone maker.
Decreases Monster HP LEDs when Button 1 pressed.
LEDS:
The LEDs have Multiple 2D arrays that are for functions that control the level. Each Level is in a Case 1-5 in those Case functions there is a Function for the Player LED to Move and the moving monster to defeat aswell as a goal that lights up when a monster is defeated but you can go to the goal with out defeating the mosnter.
To make the LED Player Move I have the volatile int “MOVE” in the function to set the LED on and to move you press the Left or Right buttons to increment between 1 and 8 in and that value incrementing or decrementing is the MOVE value in the function to set the LED on.
If the MOVE Value is Equal to the COIN Value in the Case then it goes to the next Case.
The COIN Values A-B.  A RandomSeed is applied for variation in movement for going forward and backwards.


TTS AND PLAYTONE:
The TTS is a Speaker function that speaks the following Word that I stored in memory:READY,and  START.
The playtone function uses the midi to make notes from there and uses a beep for Monster contact, fighting,and leveling up.

MONSTER RNG AND MOVEMENT:
Monsters follow 2 RNG Random function from 1-100 to move forward or backwords within the LED bounds.
Monster: The first monster attacks and has a 75% chance of missing, the second monster heals every turn it attacks and misses 65% of the time, the third monster has a 50% chance of missing healing on misses and hits, The last boss monster has a 70% chance of missing healing on misses and does 2 damage to the player on hits instead of 1.

LEVEL UP:
When the player defeats a monster it gains +1 EXP and if the EXP ==3 then the player levels up, when leveled up AT=2 and HP is set back to 5, when EXP==6 AT=3 and HP=7, lvl is printed on Serial

GAME OVER:
If player HP reaches 0 in a monster fight and Monster's Hp is above 0 then the player dies and a Game over tone plays then the Screen goes red and plays a game over song.
