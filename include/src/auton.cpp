#include "main.h"
#include "globals.hpp"
#include "tray.h"
#include "auton.hpp"


void moveStaight(float objective) {
  int tickDistance = (objective/12.6)*900;
  while (rightFront.get_position () > objective) {
    pros::delay(10);
    leftBack.move_velocity(100);
    leftFront.move_velocity(100);
    rightBack.move_velocity(100);
    rightFront.move_velocity(100);
  }
}

void rotateCW(float objAngle) {
  gyro.reset();
// move motors to turn
  while (gyro.get_value() < objAngle) {
    pros::delay(10);
    rightBack.move_velocity(-100);
    rightFront.move_velocity(-100);
    leftBack.move_velocity(100);
    leftFront.move_velocity(100);
  }
}

void rotateCCW(float objAngle) {
  gyro.reset();
// move motors to turn
  while (gyro.get_value() > objAngle) {
    pros::delay(10);
    rightBack.move_velocity(100);
    rightFront.move_velocity(100);
    leftBack.move_velocity(-100);
    leftFront.move_velocity(-100);
  }
}

void tilterRaise() {
  int anglePower = 50;
  tilter(anglePower);
  if (angleAdjuster.get_position() >= 3917) {
    angleAdjuster.move_velocity(0);
  }
}

void tilterLower() {
  int anglePower = -50;
  tilter(anglePower);
  if (angleAdjuster.get_position() <= 0) {
    angleAdjuster.move_velocity(0);
}

/*
void routineBlue1() {

moveStaight(12);

rotateCCW(180);

rotateCW(180);

}
*/
