#include <Wire.h>
#include "MeMegaPi.h"

#define leftReversed 1
#define rightReversed 0

#define LEFT -87.5
#define RIGHT (-LEFT)

#define OPEN 1
#define CLOSE 0

MeMegaPiDCMotor rightMotor(PORT1B);
MeMegaPiDCMotor leftMotor(PORT2B);
MeMegaPiDCMotor fourBarMotor(PORT3B);
MeMegaPiDCMotor clawMotor(PORT4B);

MeGyro gyro(PORT_6);
MeUltrasonicSensor sonar(PORT_7);

float last = 0.0;

void drive(int leftSpeed, int rightSpeed) {
  leftSpeed = leftReversed ? -leftSpeed : leftSpeed;
  rightSpeed = rightReversed ? -rightSpeed : rightSpeed;
  
  leftSpeed = leftSpeed > 255 ? 255 : (leftSpeed < -255 ? -255 : leftSpeed);
  rightSpeed = rightSpeed > 255 ? 255 : (rightSpeed < -255 ? -255 : rightSpeed);
  
  leftMotor.run(leftSpeed);
  rightMotor.run(rightSpeed);
}

void turn(float angle) {
  int leftSpeed = angle > 0 ? -160 : 160;
  int rightSpeed = -leftSpeed;
  gyro.begin();
  gyro.update();
  while( fabs(gyro.getAngleZ()) < fabs(angle) ) {
    //leftSpeed = angle > 0 ? -196 / (PI/4.0) * atan( 0.4 * fabs( fabs(gyro.getAngleZ()) - fabs(angle) ) ) : 196 / (PI/4.0) * atan( 0.4 * fabs( fabs(gyro.getAngleZ()) - fabs(angle) ) );
    rightSpeed = -leftSpeed;
    drive(leftSpeed, rightSpeed);
    gyro.update();
    delay(10);
  }
  drive(0,0);
}

void moveClaw(byte state) {
  if(state == OPEN) {
    clawMotor.run(-255);
    delay(1300);
    clawMotor.run(0);
  } else if(state == CLOSE) {
    clawMotor.run(255);
    delay(1300);
    clawMotor.run(0);
  }
}

void raiseFourBar(int duration) {
  fourBarMotor.run(255);
  delay(duration);
  fourBarMotor.run(0);
}

void lowerFourBar(int duration) {
  fourBarMotor.run(-255);
  delay(duration);
  fourBarMotor.run(0);
}

void targetDistance(float distance) {
  int targetSpeed = distance > 0 ? 255 : -255;
  if(distance > 0) {
    while(sonar.distanceCm() > abs(distance) || sonar.distanceCm() == 0.0) {
      drive(targetSpeed, targetSpeed);
      delay(10);
    }
  } else {
    while(sonar.distanceCm() < abs(distance) || sonar.distanceCm() == 0.0) {
      drive(targetSpeed, targetSpeed);
      delay(10);
    }
  }
  drive(0,0);
}

void decideTurn() {
  const float distance = 13; //11.43
  targetDistance(distance); //15
  while(true) {
    turn(RIGHT);
    if(sonar.distanceCm() < 40) {
      turn(LEFT); //Left
      turn(LEFT); //Left
      if(sonar.distanceCm() <40) {
        turn(RIGHT);
        return;
      } else {
        targetDistance(distance); //15
      }
    } else {
      targetDistance(distance); //15
    }
  }
}

bool check() {
  float current = sonar.distanceCm();
  /*Serial.print(current);
  Serial.print(" \t");
  Serial.println(last);*/
  if(current < 5.0 && current != 0.0) {
    if(last < 5.0 && last != 0.0) {
      last = current;
      return false;
    } 
  }
  last = current;
  return true;
}

void setup() {
  Serial.begin(9600);
  gyro.begin();

  /*drive(255,255);
  delay(1000);
  drive(0,0);
  delay(1000);
  turn(90); //right
  delay(1000);
  turn(-90); //left*/
  /*targetDistance(10);
  delay(2000);
  targetDistance(-10);*/
  /*while(check()) {
    delay(10);
  }
  Serial.println("Moving on...");
  delay(5000);*/

  //targetDistance(-15);
  delay(20 * 1000);
  
  moveClaw(CLOSE);
  raiseFourBar(2000);
  drive(-128,-128);
  delay(500);
  drive(0,0);
  turn(LEFT);
  turn(LEFT); //Face the wall course

  decideTurn();
  /*targetDistance(15);
  decideTurn();
  targetDistance(15);
  decideTurn();
  targetDistance(15);
  decideTurn();
  targetDistance(15);
  decideTurn();
  targetDistance(30);*/

  targetDistance(-25);
  lowerFourBar(2000);
  moveClaw(OPEN);
  //drive(255,255);
  //turn(90);
  //delay(2000);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

