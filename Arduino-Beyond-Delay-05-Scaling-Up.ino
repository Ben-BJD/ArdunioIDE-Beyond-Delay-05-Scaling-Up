#include <Arduino.h>
#include <Timer.h>
#include <BlinkLeds.h>
#include <Pitches.h>
#include <BuzzerMelody.h>
#include <Servo.h>
#include <ServoControl.h>

BlinkLeds blinkLeds = BlinkLeds();
BuzzerMelody buzzerMelody = BuzzerMelody();
ServoControl servoControl = ServoControl();

void setup()
{
  blinkLeds.onSetup();
  buzzerMelody.onSetup();
  servoControl.onSetup();
}

void loop() 
{
  blinkLeds.onLoop();
  buzzerMelody.onLoop();
  servoControl.onLoop();
}