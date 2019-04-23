#include <Servo.h> //servo library

Servo servo1; //create servo object
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

void setup() 
{ 
  Serial.begin(9600);
  servo1.attach(5); //enable control of servo, PWM digital 5 pin for servo
  servo2.attach(6);
  servo3.attach(9);
  servo4.attach(10);
  servo5.attach(11);
  
} 

void loop() 
{ 
  int flexposition1; //MIDDLE  (initiate input value FROM the flex senseo) 
  int flexposition2; //THUMB
  int flexposition3; //RING
  int flexposition4; //INDEX
  int flexposition5; //PINKY
  
  int servoposition1; //initiate output value TO the servoh
  int servoposition2;
  int servoposition3;
  int servoposition4;
  int servoposition5;

  flexposition1 = analogRead(0); //0 to 1023, Analogue 0 pin for flex sensor
  flexposition2 = analogRead(1);
  flexposition3 = analogRead(2);
  flexposition4 = analogRead(3);
  flexposition5 = analogRead(4);
  
  servoposition1 = map(flexposition1, 830, 900, 0, 180); //map flex value onto servo angle
  servoposition1 = constrain(servoposition1, 0, 180); //make sure it doesn't overshoot 
  servoposition2 = map(flexposition2, 850, 910, 0, 180); 
  servoposition2 = constrain(servoposition2, 0, 180);
  servoposition3 = map(flexposition3, 800, 880, 0, 180); //Tweal these manually to match each sensor value using Serial.print
  servoposition3 = constrain(servoposition3, 0, 180);
  servoposition4 = map(flexposition4, 960, 970, 0, 180); 
  servoposition4 = constrain(servoposition4, 0, 180);
  servoposition5 = map(flexposition5, 920, 970, 0, 180); 
  servoposition5 = constrain(servoposition5, 0, 180);
  
  servo1.write(servoposition1); //move servo this angle
  servo2.write(servoposition2);
  servo3.write(servoposition3);
  servo4.write(servoposition4);
  servo5.write(servoposition5);

  Serial.print("sensor: "); //use this to tweak the values 
  Serial.print(flexposition4);
  Serial.print("  servo: ");
  Serial.println(servoposition4); //println ensures it is all on the same line
  
  delay(20); //wait 20ms between servo updates
} 
