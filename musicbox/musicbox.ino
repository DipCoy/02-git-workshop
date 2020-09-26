#include "pitches.h"
#include "button.h"
#include "buzzer.h"

#define PIN_BUTTON_MEL_ONE 4
#define PIN_BUTTON_OFF 5
#define PIN_BUTTON_SPEED_UP 3
#define PIN_BUTTON_SPEED_DOWN 2
#define PIN_BUZZER 6

Button buttonMelodyOne(PIN_BUTTON_MEL_ONE);
Button buttonOff(PIN_BUTTON_OFF);
Button buttonSpeedUp(PIN_BUTTON_SPEED_UP);
Button buttonSpeedDown(PIN_BUTTON_SPEED_DOWN);
Buzzer buzzer(PIN_BUZZER);

int notes[] = {NOTE_A4, NOTE_SILENCE, NOTE_G4, NOTE_SILENCE};
double durations[] = {8, 1, 4, 1};
int melodyLength = 4;

unsigned long speeds[] = {25, 50, 100, 200, 400, 800};
int currentSpeed = 2;
int speedsLength = 6;

// maybe somewhere in the future we will have one more button...
#define PIN_BUTTON_MEL_TWO 4
Button buttonMelodyTwo(PIN_BUTTON_MEL_TWO);
//and the second melody
int notes2[] = {NOTE_C4, NOTE_SILENCE, NOTE_G4, NOTE_SILENCE};
double durations2[] = {4, 1, 4, 1};
int melodyLength2 = 4;

int notes3[] = {NOTE_D4, NOTE_A4, NOTE_FS5, NOTE_E5, NOTE_FS5, NOTE_A4, NOTE_FS5, NOTE_A4, 
NOTE_D4, NOTE_A4, NOTE_FS5, NOTE_E5, NOTE_FS5, NOTE_A4, NOTE_FS5, NOTE_A4,
NOTE_D4, NOTE_B4, NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_B4, NOTE_G5, NOTE_B4, 
NOTE_D4, NOTE_B4, NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_B4, NOTE_G5, NOTE_B4};

const double d = 2.5;
double durations3[] = {d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,
d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d
};
int melodyLength3 = 32;

void setup()
{
    buzzer.setMelody(notes, durations, melodyLength);
}

void loop()
{
    buzzer.playSound();

    if (buttonOff.wasPressed())
    {
        buzzer.turnSoundOff();
    }

    if (buttonMelodyOne.wasPressed())
    {
        buzzer.setMelody(notes, durations, melodyLength);
        buzzer.turnSoundOn();
    }

    if (buttonSpeedDown.wasPressed())
    {
        currentSpeed = (currentSpeed + 1)%speedsLength;
        buzzer.setNoteDuration(speeds[currentSpeed]);
    }
}
