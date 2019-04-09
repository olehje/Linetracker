#include <UCMotor.h>
UC_DCMotor leftMotor1(3, MOTOR34_64KHZ);
UC_DCMotor rightMotor1(4, MOTOR34_64KHZ);
UC_DCMotor leftMotor2(1, MOTOR34_64KHZ);
UC_DCMotor rightMotor2(2, MOTOR34_64KHZ); 

#define leftSensor    A0
#define middleSensor  A1
#define rightSensor   13

#include <Ultrasonic.h>
Ultrasonic ultrasonic(A2, A3);

int counter = 0;
String background = "black";

void setup() {
  Serial.begin(9600);
}

void loop() {
  int left = digitalRead(leftSensor); //svart = 0, hvit = 1
  int middle = digitalRead(middleSensor);
  int right = digitalRead(rightSensor);
 
 int  dist = ultrasonic.distanceRead();


  if (dist<30){
    brake();
  }
  
 else if(background == "black"){
  if ((left == 0) && (middle == 1) && (right == 1)) {
    turn_right();
    counter = 0;
  }
  if ((left == 0) && (middle == 0) && (right == 1)) {
    turn_right();
    counter = 0;
  }
  if ((left == 1) && (middle == 1) && (right == 0)) {
    turn_left();
    counter = 0;
  }
  if ((left == 1) && (middle == 0) && (right == 0)) {
    turn_left();
    counter = 0;
  }
  if ((left == 0) && (middle == 1) && (right == 0)) {
    forward();
    counter = 0;
  }
  
  if ((left == 0) && (middle == 0) && (right == 0)) {
    counter += 1;

    if(counter>3){
        back();
    }
  }    
}

 else if(background == "white"){
    if ((left == 1) && (middle == 0) && (right == 0)) {
      turn_right();
    }
    if ((left == 1) && (middle == 1) && (right == 0)) {
      turn_right();
    }
    if ((left == 0) && (middle == 0) && (right == 1)) {
      turn_left();
    }
    if ((left == 0) && (middle == 1) && (right == 1)) {
      turn_left();
    }
    if ((left == 1) && (middle == 0) && (right == 1)) {
      forward();
    }
    if ((left == 1) && (middle == 1) && (right == 1)) {
      back();
    }    
  }
 /*  
  Serial.print("left = "); Serial.println(left);
  Serial.print("middle = "); Serial.println(middle);
  Serial.print("right = "); Serial.println(right);
  Serial.println("");
*/
 delay(20);
}

void forward(){
  //Forward
  leftMotor1.run(0x01); rightMotor1.run(0x01);
  leftMotor2.run(0x01); rightMotor2.run(0x01);
  leftMotor1.setSpeed(150); rightMotor1.setSpeed(150);
  leftMotor2.setSpeed(150); rightMotor2.setSpeed(150);  
}
  
void turn_left(){
  //left
  leftMotor1.run(0x01); rightMotor1.run(0x01);
  leftMotor2.run(0x01); rightMotor2.run(0x01);
  leftMotor1.setSpeed(0); rightMotor1.setSpeed(150);
  leftMotor2.setSpeed(0); rightMotor2.setSpeed(150);  
}
  
void turn_right(){
  //right
  leftMotor1.run(0x01); rightMotor1.run(0x01);
  leftMotor2.run(0x01); rightMotor2.run(0x01);
  leftMotor1.setSpeed(150); rightMotor1.setSpeed(0);
  leftMotor2.setSpeed(150); rightMotor2.setSpeed(0); 
}  
  
void back(){
  //back
  leftMotor1.run(0x02); rightMotor1.run(0x02);
  leftMotor2.run(0x02); rightMotor2.run(0x02);
  leftMotor1.setSpeed(150); rightMotor1.setSpeed(150);
  leftMotor2.setSpeed(150); rightMotor2.setSpeed(150);      
}

void brake(){
  //stop
  leftMotor1.run(0x01); rightMotor1.run(0x01);
  leftMotor2.run(0x01); rightMotor2.run(0x01);
  leftMotor1.setSpeed(0); rightMotor1.setSpeed(0);
  leftMotor2.setSpeed(0); rightMotor2.setSpeed(0);   
}
