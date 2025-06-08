#include "Arduino.h"
#include "ServoControl.h"

ServoControl::ServoControl(){}

void ServoControl::moveServo(ServoStruct &servoStruct)
{
  if(servoStruct.servoForward)
  {
    servoStruct.pos += 1; // Increment position
    if(servoStruct.pos >= 180) 
    {
      servoStruct.servoForward = false; // Change direction
      servoStruct.pos = 180; // Ensure position does not exceed 180
    }
  } 
  else 
  {
    servoStruct.pos -= 1; // Decrement position
    if(servoStruct.pos <= 0) 
    {
      servoStruct.servoForward = true; // Change direction
      servoStruct.pos = 0; // Ensure position does not go below 0
    }
  }

  servoStruct.servo.write(servoStruct.pos); 
  servoStruct.servoTimer = Timer(servoStruct.servoDelay);
  servoStruct.servoTimer.start();
}

void ServoControl::onSetup() 
{
  for(int i = 0; i < SERVO_COUNT; i++) 
  {
    _servos[i].servo.attach(_servos[i].servoPin);
    _servos[i].servo.write(_servos[i].pos); // Initialize servo position
    moveServo(_servos[i]);
  }
}

void ServoControl::onLoop() 
{
  for(int i = 0; i < SERVO_COUNT; i++) 
  {
    if(_servos[i].servoTimer.update()) 
    {
      _servos[i].servoTimer.stop();
      moveServo(_servos[i]); // Move the servo
    }
  }
}



