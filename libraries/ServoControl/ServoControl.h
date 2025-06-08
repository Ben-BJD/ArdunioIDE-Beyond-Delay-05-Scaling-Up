#ifndef ServoControl_h
#define ServoControl_h

#include "Arduino.h"
#include <Timer.h>
#include <Servo.h>

#define SERVO_COUNT 3

struct ServoStruct 
{
  Servo servo;
  int servoPin;
  int pos;
  bool servoForward;
  Timer servoTimer;
  long servoDelay;
};

class ServoControl 
{
  public:
    ServoControl();
    void onSetup();
    void onLoop();
  private:
    void moveServo(ServoStruct &servoStruct);
    ServoStruct _servos[SERVO_COUNT]
    {
    {Servo(), 9, 0,true,Timer(1000),7}
    ,{Servo(), 6, 0,true,Timer(1000),15}
    ,{Servo(), 3, 0,true,Timer(1000),30}
    };
    
};

#endif

