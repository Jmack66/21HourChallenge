#include "RocketDo.h"

#define Y_SERVO_PIN 9
#define Z_SERVO_PIN 10
#define CHUTE_PIN 11
#define CHUTE_CLOSE 0
#define CHUTE_OPEN 90
#define SERVO_RATIO 3.0f

Rocket::Rocket() {
  //can initialize states and gyros/accel
  y_axis.attach(Y_SERVO_PIN);
  z_axis.attach(Z_SERVO_PIN);
  chute.attach(CHUTE_PIN);
  y_pid.setSetpoint(0.0);
  z_pid.setSetpoint(0.0);
  y_axis.write(90);
  z_axis.write(90);

}

void Rocket::pad_idle() {
  //make buzzer beep and update sensors waiting for liftoff
  accels = sensors.getAccel();
}

void Rocket::ascent() {
  gyros = sensors.getGyros();
  flight_time = (millis() - flight_start) / 1000.0f;
  current_t = micros();
  if(previous_t == 0){
      previous_t = current_t;
    }
  del_t = (current_t - previous_t) / 1000000.0f;
  ypr += gyros * del_t;
  float y_out = y_pid.update(ypr.y);
  float z_out = z_pid.update(ypr.z);
  float servo_y = y_out * SERVO_RATIO;
  float servo_z = z_out * SERVO_RATIO;
  y_axis.write(servo_y + 90);
  z_axis.write(servo_z + 90);
 previous_t = current_t;
  
}

void Rocket::apogee() {
  
}
void Rocket::descent() {
  //open chute

}

void Rocket::landed() {



}

void Rocket::updateState(){
  gyros = sensors.getGyros();
  accels = sensors.getAccel();
  flight_time = millis() - flight_start;
}
