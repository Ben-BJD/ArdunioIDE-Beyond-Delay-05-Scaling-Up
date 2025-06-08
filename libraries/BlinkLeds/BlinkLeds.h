#ifndef BlinkLeds_h
#define BlinkLeds_h

#include "Arduino.h"
#include <Timer.h>

#define LED_COUNT 3

struct BlinkLedStruct 
{
  uint8_t pin;
  int highLow;
  long blinkLimit;
  long blinkCount;
  Timer timer;
};

class BlinkLeds 
{
  public:
    BlinkLeds();
    void onSetup();
    void onLoop();
  private:
    void blinkLedCallback(BlinkLedStruct &led);
    void startLedsBlinking();
    Timer _restartTimer = Timer(200);
    BlinkLedStruct _leds[LED_COUNT]{
      {13, LOW, 2,0,Timer(1000)},
      {12, LOW, 10,0,Timer(200)},
      {10, LOW, 20,0,Timer(100)}
    };
};

#endif

