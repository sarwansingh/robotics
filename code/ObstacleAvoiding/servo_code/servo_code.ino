#include <Servo.h>
Servo servo;

void setup() {
  servo.attach(10);
}
void loop() {
  servo.write(0);    delay(1000);
  servo.write(90);    delay(1000);
  servo.write(180);    delay(3000);
  
}
