
// C++ code
//
#include <Servo.h>
Servo myServo;




//define variables and constants
int const potPin = A0; //analog pin A
int potVal;            //stores value of pot
int angle = 0;         //stores position of servo




int distanceThreshold = 20;




int cm = 0;




long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}




void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);




  distanceThreshold = 20;
 
  myServo.attach(8);
Serial.begin(9600);
}




int mappedpotval;
void loop()
{




  //loop function


  potVal =  analogRead(potPin);
  Serial.print("potval: ");
  Serial.println(potVal);


mappedpotval= map(potVal, 0, 1023, 0, 179);
   Serial.println(mappedpotval);


  //original range: 0 to 1023
  //maps to second range: 0 to 179
   
//  myServo.write(100);
  delay(15);
 


    cm = 0.01723 * readUltrasonicDistance(7, 6);


  Serial.print("ultra: ");
  Serial.println(cm);


  if (cm > distanceThreshold) {
  myServo.write(120);
  }
  else if ((cm < distanceThreshold)){
    // OPENS BOX
    myServo.write(800);
    delay(2000); // Wait for 500 millisecond(s)
  }
 
} //end of loop()


 




 





