//Line Follower code v1
#include <AFMotor.h>
//defining pins and variables
#define lefts A5    // left IR sensor
#define rights A4   // right IR sensor
//defining motors
AF_DCMotor motorL(1, MOTOR12_8KHZ); 
AF_DCMotor motorR(2, MOTOR12_8KHZ);

void setup() {
  //setting the speed of motors
  motorL.setSpeed(200);
  motorR.setSpeed(200);
  //declaring pin types
  pinMode(lefts,INPUT);
  pinMode(rights,INPUT);
  //begin serial communication
  Serial.begin(9600);
}

void loop(){
  //printing values of the sensors to the serial monitor
  Serial.println(analogRead(lefts));
  Serial.println(analogRead(rights));
  //line detected by bo  th
  if(analogRead(lefts)<=400 && analogRead(rights)<=400){
    //stop
    motorL.run(RELEASE);
    motorR.run(RELEASE);
  }
  //line detected by left sensor
  else if(analogRead(lefts)<=400 && !analogRead(rights)<=400){
    //turn left
    motorL.run(BACKWARD);
    motorR.run(FORWARD);
  }
  //line detected by right sensor
  else if(!analogRead(lefts)<=400 && analogRead(rights)<=400){
    //turn right
    motorL.run(FORWARD);
    motorR.run(BACKWARD);
  }
  //line detected by none
  else if(!analogRead(lefts)<=400 && !analogRead(rights)<=400){
    //stop
    motorL.run(FORWARD);
    motorR.run(FORWARD);
  }
  
}
