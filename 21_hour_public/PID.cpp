#include "PID.h"


PID::PID(float Kp, float Ki, float Kd, float saturation) {
  //constructor-- will take in gains, and maybe like servo limits or can do a specific function
  this->Kp = Kp;//the this-> isnt vital but it makes it nice and clear we are modifying the class variable
  this->Kd = Kd;
  this->Ki = Ki;
  this->saturation = saturation;

}

void PID::setSetpoint(float setpoint) {
  //this function is kinda stupid
  this->setpoint = setpoint;
}

//if we wanted to improve this we could maybe use a template for return type and then the user could specify idk
float PID::update(float input) {
  current_time = micros();
  float del_t = (current_time - previous_time) / 1000000.0f;
  float error = setpoint - input;
  error_integral += error * del_t; // this is maybe bad??? idk
  //can add integral windup later maybe
  float del_error = (error - error_last) / del_t;
  out = Kp * error + Ki * error_integral + Kd * del_error;
  error_last = error;
  // kp*e + ki*e += e*dt + Kd * del_error
  previous_time = current_time;
  if (out > saturation) {
    out = saturation;
  } else if (out < -saturation) {
    out = -saturation;
  }
  return out;
}
