const int IRsensor = 2;
int inputVal = 0;
void setup()
{
  pinMode(13, OUTPUT);          // Pin 13 has an LED connected on most Arduino boards:
  pinMode(IRsensor, INPUT);   //Pin 2 is connected to the output of proximity sensor
  Serial.begin(9600);
}
void loop()
{
  if (digitalRead(IRsensor) == HIGH)   //Check the sensor output
  {   
    digitalWrite(13, HIGH);   // set the LED on
  }  else  {
    digitalWrite(13, LOW);    // set the LED off
  }
  inputVal = digitalRead(IRsensor);
  Serial.println(inputVal);
  delay(1000);              // wait for a second
}
