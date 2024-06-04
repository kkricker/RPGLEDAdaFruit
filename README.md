# RPGLEDAdaFruit
ENGR 103 Final Project Game
##A bit about myself...
I like RPG's and I like pizza
My game’s intended purpose is to fight enemies to progress to the next stage eventually getting to a boss fight.
Present Rules:
  My game’s intended purpose is to fight enemies to progress to the next stage eventually getting to a boss fight. You can decide to level up or try to sneak past the monster to eventually get to a boss.
  
User Inputs/Outputs:
INPUTS:
This game has 4 inputs 3 being the ISR’s and one being sensor queued.
2 of the ISR’s are the Left and Right buttons D4 and D5, these buttons control the LED players movement, Right going left and Left going Right (I will tweak to fix controls).
ISR RAW:
Switch: Slide switch equals the volatile bool “SFlag”.
Button1:Turns the Following volatile bool true “B1Flag” and “BF1Flag”.
Button2:Turns the Following volatile bool true “B2Flag” and “BF2Flag”.

OUTPUTS:
The Outputs of the code are The LEDs/Color of LEDs, Speaker for TTS, and Sounds from the tone maker.
LEDS:
The LEDs have Multiple 2D arrays that are for functions that control the level. Each Level is in a Case 1-5 in those Case functions there is a Function for the Player LED to Move and the moving monster to defeat aswell as a goal that lights up when a monster is defeated but you can go to the goal with out defeating the mosnter.
To make the LED Player Move I have the volatile int “MOVE” in the function to set the LED on and to move you press the Left or Right buttons to increment between 1 and 8 in and that value incrementing or decrementing is the MOVE value in the function to set the LED on.
If the MOVE Value is Equal to the COIN Value in the Case then it goes to the next Case.
The COIN Values A-B.  A RandomSeed is applied for variation in movement for going forward and backwards.


TTS AND PLAYTONE:
The TTS is a Speaker function that speaks the following Word that I stored in memory:READY, START, THE, MOVING, AND, USE, LEFT, RIGHT, FOR, TARGET, ZONE, GREAT, LIGHTS, LEVEL, FINAL, ABORT.
Not all words are used but in future use they will.
The playtone function uses the midi to make notes from there and uses a beep for Monster contact, fighting,and leveling up.
