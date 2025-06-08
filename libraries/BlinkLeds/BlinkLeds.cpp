#include "Arduino.h"
#include "BlinkLeds.h"

BlinkLeds::BlinkLeds(){}

void BlinkLeds::blinkLedCallback(BlinkLedStruct &led) 
{
  led.highLow = (led.highLow == HIGH) ? LOW : HIGH;
  digitalWrite(led.pin, led.highLow);
  if(led.highLow == LOW) 
  {
      led.blinkCount++;
      if(led.blinkCount >= led.blinkLimit) 
      {
          led.timer.stop();
      }
  }
}

void BlinkLeds::startLedsBlinking() 
{
  for(uint8_t i=0; i<LED_COUNT; i++) 
  {
      _leds[i].blinkCount = 0;
      _leds[i].highLow = LOW;
      blinkLedCallback(_leds[i]);
      _leds[i].timer.start();
  }
}

void BlinkLeds::onSetup() 
{
  for(uint8_t i=0; i<LED_COUNT; i++) 
  {
      pinMode(_leds[i].pin, OUTPUT);
      startLedsBlinking(); // Start blinking LEDs immediately
  }
}

void BlinkLeds::onLoop() 
{
  bool anyTimersRunning = false;

  for(uint8_t i=0; i<LED_COUNT; i++) 
  {
      if( _leds[i].timer.update() )
      {
          blinkLedCallback(_leds[i]);
      }

      if( _leds[i].timer.isRunning() ) 
      {
          anyTimersRunning = true;
      }
  }

  if(!anyTimersRunning && !_restartTimer.isRunning()) 
  {
    _restartTimer.start();
  }

  if( _restartTimer.update() )
  {
      _restartTimer.stop();
      startLedsBlinking(); // Restart blinking LEDs after the restart timer expires
  }
}

