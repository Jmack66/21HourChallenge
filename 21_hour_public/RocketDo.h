#include <Wire.h>
#include <Arduino.h>
#include "Sensor.h"
#include <Servo.h>
#include "PID.h"

class Rocket{
  public:
    Rocket();
    Vector3 ypr;
    Vector3 gyros;
    Vector3 accels; // x accel is vertical
    void updateState();
    void pad_idle();
    void ascent();
    void apogee();
    void descent();
    void landed();
    unsigned long flight_time = 0.0;
    unsigned long flight_start = 0.0;
  private:
    Sensors sensors;
    unsigned long current_t = 0.0;
    unsigned long previous_t = 0.0;
    float del_t = 0.0f;
    Servo y_axis;
    Servo z_axis;
    Servo chute;
    //kp, ki ,kd , saturation
    PID y_pid = PID(0.5f,0.3f,0.1f,10.0f);
    PID z_pid = PID(0.5f,0.3f,0.1f,10.0f);
  };
