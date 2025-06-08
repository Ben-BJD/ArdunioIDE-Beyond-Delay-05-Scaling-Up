#ifndef BuzzerMelody_h
#define BuzzerMelody_h

#include "Arduino.h"
#include <Timer.h>
#include <Pitches.h>

#define NOTE_LEN 25

class BuzzerMelody 
{
  public:
    BuzzerMelody();
    void onSetup();
    void onLoop();
  private:
    void playNote(int thisNote);
    uint8_t _buzzerPin = 7;
    uint8_t _currentNote = 0;
    int _melody[NOTE_LEN] = 
    {
        NOTE_E1, NOTE_E1, NOTE_E1,NOTE_C1,NOTE_E1,NOTE_G1,NOTE_FS1
        ,NOTE_C1,NOTE_FS1,NOTE_DS1,NOTE_A1,NOTE_AS1,NOTE_A1,NOTE_A1,NOTE_FS1,NOTE_E1,NOTE_G1,NOTE_GS1,NOTE_F1,NOTE_G1,NOTE_E1,NOTE_C1,NOTE_D1,NOTE_AS1
    };
    int _noteDurations[NOTE_LEN] = 
    {
        8,8,8,8,8,8,8,8
        ,8,8,8,8,8,8,8,8,8,4,8,8,4,8,8,8,8
    };
    Timer _timer = Timer(1000);
};

#endif

