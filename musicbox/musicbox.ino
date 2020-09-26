#include "pitches.h"
#include "button.h"
#include "buzzer.h"

#define PIN_BUTTON_MEL_ONE 4
#define PIN_BUTTON_MEL_TWO 5
#define PIN_BUTTON_SPEED_UP 3
#define PIN_BUTTON_SPEED_DOWN 2
#define PIN_BUZZER 6

const int DELTA_SPEED = 15;
const int MIN_SPEED = 2000;

Button buttonMelodyOne(PIN_BUTTON_MEL_ONE);
Button buttonMelodyTwo(PIN_BUTTON_MEL_TWO);
Button buttonSpeedUp(PIN_BUTTON_SPEED_UP);
Button buttonSpeedDown(PIN_BUTTON_SPEED_DOWN);
Buzzer buzzer(PIN_BUZZER);

int notes[] = {NOTE_A4, NOTE_SILENCE, NOTE_G4, NOTE_SILENCE};
double durations[] = {8, 1, 4, 1};
int melodyLength = 4;

int currentSpeed = 100;

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

    if (buttonMelodyOne.wasPressed())
    {
        buzzer.setMelody(notes, durations, melodyLength);
        buzzer.turnSoundOn();
    }

    if (buttonMelodyTwo.wasPressed())
    {
        buzzer.setMelody(notes3, durations3, melodyLength3);
        buzzer.turnSoundOn();
    }

    if (buttonSpeedUp.wasPressed())
    {
        currentSpeed = max(currentSpeed - DELTA_SPEED, 1);
        buzzer.setNoteDuration(currentSpeed);
    }
}
