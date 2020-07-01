#include <AFMotor.h>
AF_DCMotor motorR(1);
AF_DCMotor motorL(2);
void setup() {
  motorR.setSpeed(200);motorL.setSpeed(200); 
  motorR.run(RELEASE);motorL.run(RELEASE); //stop motors
}
void loop() {
 motorR.run(FORWARD);motorL.run(FORWARD);//clockwise
 delay(2000);
 motorR.run(RELEASE);motorL.run(RELEASE);//stop motors
 delay(500);
 motorR.run(BACKWARD);motorL.run(BACKWARD);//anticlockwise
 delay(2000); 
 motorR.run(RELEASE);motorL.run(RELEASE);//stop motors
 delay(500);
}
