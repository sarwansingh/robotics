#include <AFMotor.h>
#include <Servo.h>

#define TRIG_PIN A2
#define ECHO_PIN A3
#define MAX_SPEED 190 // sets speed of DC  motors

AF_DCMotor motorL(1, MOTOR12_1KHZ);
AF_DCMotor motorR(2, MOTOR12_1KHZ);
Servo myservo;

boolean goesForward = false;
int distance = 100,speedSet = 0;

int calDistance() {
    delay(10);
   //clear trigPin
   digitalWrite(TRIG_PIN,LOW); 
   delayMicroseconds(2);
   //trigPin HIGH for 10 u sec
   digitalWrite(TRIG_PIN,HIGH);
   delayMicroseconds(10);
   digitalWrite(TRIG_PIN,LOW);
   
   int duration=pulseIn(ECHO_PIN,HIGH);//reads echoPin
   int cm=duration * 0.034/2; //calculate distance
   Serial.println(cm);
   if(cm==0) cm=250;
  return cm;
}
void setup() {
  Serial.begin(9600);
  myservo.attach(10);
  myservo.write(115);
  delay(1000);
  distance = calDistance();    delay(100);
  distance = calDistance();    delay(100);
}
void loop() {
  int distanceR = 0, distanceL = 0;  delay(40);

  if (distance <= 15)
  { moveStop();     delay(100);
    moveBackward(); delay(300);
    moveStop();     delay(200);
    distanceR = lookRight();    delay(200);
    distanceL = lookLeft();     delay(200);

    if (distanceR >= distanceL)
    { turnRight();      moveStop();
    } else{
      turnLeft();      moveStop();
    }
  } else {
    moveForward();
  }
  Serial.print("Front ");
  distance = calDistance();
}
int lookRight(){ 
  Serial.print("right ");
  myservo.write(50);  delay(500);
  int distance = calDistance();
  delay(100);
  myservo.write(115);
  return distance;
}
int lookLeft(){ 
  Serial.print("left ");
  myservo.write(170);   delay(500);
  int distance = calDistance();
  delay(100);
  myservo.write(115);
  return distance;
}
void moveStop() {
  motorL.run(RELEASE);
  motorR.run(RELEASE);
}
void moveForward() {

  if (!goesForward)
  {
    goesForward = true;
    motorL.run(FORWARD);    motorR.run(FORWARD);
    // slowly bring the speed up to avoid loading down the batteries too quickly
    for (speedSet = 0; speedSet < MAX_SPEED; speedSet += 2) 
    {
      motorL.setSpeed(speedSet);
      motorR.setSpeed(speedSet);
      delay(5);
    }
  }
}
void moveBackward() {
  goesForward = false;
  motorL.run(BACKWARD);  motorR.run(BACKWARD);
  
  // slowly bring the speed up to avoid loading down the batteries too quickly
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet += 2) 
  {
    motorL.setSpeed(speedSet);
    motorR.setSpeed(speedSet);
    delay(5);
  }
}
void turnRight() {
  motorL.run(FORWARD);  motorR.run(BACKWARD);
  delay(500);
  motorL.run(FORWARD);  motorR.run(FORWARD);
}
void turnLeft() {
  motorL.run(BACKWARD);  motorR.run(FORWARD);
  delay(500);
  motorL.run(FORWARD);   motorR.run(FORWARD);
}
