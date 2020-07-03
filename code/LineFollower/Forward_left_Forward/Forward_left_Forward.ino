#include <AFMotor.h>
AF_DCMotor motorR(1);
AF_DCMotor motorL(2);

void setup() {
  motorR.setSpeed(200);motorL.setSpeed(200);
  motorR.run(RELEASE);motorL.run(RELEASE);
}

void loop() {
 motorR.run(FORWARD);motorL.run(FORWARD); delay(1000);
 
 motorR.run(RELEASE);motorL.run(FORWARD); delay(400);
 
 motorR.run(FORWARD);motorL.run(FORWARD);  delay(1000);    
}
