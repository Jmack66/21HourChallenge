#include <Wire.h>
#include <Arduino.h>
class PID{
  public:
  PID(float Kp, float Ki,float Kd, float saturation);
  void setSetpoint(float setpoint);
  float update(float input);

  
  private:
     float Kp = 0.0f;
     float Kd = 0.0f;
     float Ki = 0.0f;
     float saturation = 0.0f;
     float setpoint = 0.0f;
     float output = 0.0f;
     float error_integral = 0.0f;
     float error_last = 0.0f;
     unsigned long current_time = 0.0;
     unsigned long previous_time = 0.0;
 };
