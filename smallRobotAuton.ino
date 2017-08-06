#include "MeOrion.h"

#define leftReversed 0
#define rightReversed 0

MeDCMotor rightMotor(M1);
MeDCMotor leftMotor(M2);

MeUltrasonicSensor sonar(PORT_3);
MeLineFollower tracker(PORT_4);

float last = 0.0;

void drive(int leftSpeed, int rightSpeed) {
  leftSpeed = leftReversed ? -leftSpeed : leftSpeed;
  rightSpeed = rightReversed ? -rightSpeed : rightSpeed;
  
  leftSpeed = leftSpeed > 255 ? 255 : (leftSpeed < -255 ? -255 : leftSpeed);
  rightSpeed = rightSpeed > 255 ? 255 : (rightSpeed < -255 ? -255 : rightSpeed);
  
  leftMotor.run(leftSpeed);
  rightMotor.run(rightSpeed);
}

void trackLine() {
  switch(tracker.readSensors()) {
    case S1_IN_S2_IN: drive(128,128); break;
    case S1_IN_S2_OUT: drive (-255,255); break;
    case S1_OUT_S2_IN: drive(255,-255); break;
    case S1_OUT_S2_OUT: drive(-128,-128); break;
  }
}

bool check() {
  float current = sonar.distanceCm();
  /*Serial.print(current);
  Serial.print(" \t");
  Serial.println(last);*/
  if(current < 3.0 && current != 0.0) {
    if(last < 3.0 && last != 0.0) {
      last = current;
      return false;
    } 
  }
  last = current;
  return true;
}

void setup() {
  Serial.begin(9600);
  while(check()) {
    trackLine();
    //drive(0.99 * 255, 255);
    delay(1);
  }
  drive(0,0);
}

void loop() {
  
}
