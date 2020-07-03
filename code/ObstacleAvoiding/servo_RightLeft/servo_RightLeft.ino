#include <Servo.h>
Servo servo;

void setup() {
  servo.attach(10);
}
void loop() {
  
  servo.write(50);    delay(1000);//look right
  servo.write(115);   delay(1000);//back
  
  servo.write(170);  delay(1000);//look left
  servo.write(115);   delay(5000);//back
}
