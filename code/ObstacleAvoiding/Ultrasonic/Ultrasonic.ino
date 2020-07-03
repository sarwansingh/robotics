#define TRIG_PIN A2 
#define ECHO_PIN A3 

long duration;
int distance_cm,distance_inch;

void setup(){
    Serial.begin(9600);
    pinMode(TRIG_PIN,OUTPUT);
    pinMode(ECHO_PIN,INPUT);
}
void loop(){
     //clear trigPin
   digitalWrite(TRIG_PIN,LOW);
   delayMicroseconds(2);
   //trigPin HIGH for 10 u sec
   digitalWrite(TRIG_PIN,HIGH);
   delayMicroseconds(10);
   digitalWrite(TRIG_PIN,LOW);
   
   duration=pulseIn(ECHO_PIN,HIGH);//reads echoPin
   distance_cm=duration * 0.034/2; //calculate distance
   distance_inch=duration*0.0133/2;
  
   Serial.print("Distance: ");
   Serial.print(distance_cm);
   Serial.println(" cm");
   delay(20);
   Serial.print("Distance: ");
   Serial.print(distance_inch);
   Serial.println(" inch");
   delay(2000);
}
