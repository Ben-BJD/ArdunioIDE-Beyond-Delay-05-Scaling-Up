#include "Arduino.h"
#include "BuzzerMelody.h"

BuzzerMelody::BuzzerMelody(){}

void BuzzerMelody::playNote(int thisNote) 
{
  // to calculate the note duration, take one second divided by the note type.

  //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

  int noteDuration = 1000 / _noteDurations[thisNote];

  tone(_buzzerPin, _melody[thisNote], noteDuration);

  // to distinguish the notes, set a minimum time between them.

  // the note's duration + 30% seems to work well:

  int pauseBetweenNotes = noteDuration * 1.30;

  _timer= Timer(pauseBetweenNotes);
  _timer.start();

  _currentNote++;
  if (_currentNote >= NOTE_LEN) 
  {
    _currentNote = 0; // Reset to the first note
  }
}

void BuzzerMelody::onSetup() 
{
  pinMode(_buzzerPin, OUTPUT);
  //tone(buzzerPin, 1000, 1000); // 1 kHz tone
  playNote(_currentNote);
}

void BuzzerMelody::onLoop() 
{
  if(_timer.update()) 
  {
    _timer.stop();
    noTone(_buzzerPin);
    // Play the next note
    playNote(_currentNote);
  }
}

