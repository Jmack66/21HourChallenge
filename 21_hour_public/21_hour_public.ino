#include "StateMachine.h"
// THIS IS OUR SUPER SICK AND COOL CODE LETS GOOOOOOOOOOO "S" GANG RISE UP! 


StateMachine* sm;
void setup() {
  Serial.begin(9600);
  Serial.println("HI");
  sm = new StateMachine();
}

void loop() {
  sm->update();
}
