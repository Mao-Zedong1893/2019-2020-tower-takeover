#ifndef AUTO_HPP
#define AUTO_HPP
#include "main.h"
#include "globals.hpp"

// move strait
void moveStaight(float objective);
// rotate clockwise
void rotateCW(float objAngle);
// rotate counterclockwise
void rotateCCW(float objAngle);


/*
leftBack.set_brake_mode(MOTOR_BRAKE_HOLD);
rightBack.set_brake_mode(MOTOR_BRAKE_HOLD);
leftFront.set_brake_mode(MOTOR_BRAKE_HOLD);
rightFront.set_brake_mode(MOTOR_BRAKE_HOLD);
*/

// auton drive functions
// motor ticks to inches

/*
// move strait
void moveStaight(float objective) {
  float tickDistance = (objective/12.6)*900;
  while (rightFront.get_position () >= objective) {
    pros::delay(10);
    leftBack.move_velocity(objective);
    leftFront.move_velocity(objective);
    rightBack.move_velocity(objective);
    rightFront.move_velocity(objective);
  }
}

// rotate clockwise
void rotateCW(double objAngle) {
  gyro.reset();
// move motors to turn
  while (gyro.get_value() < objAngle) {
    pros::delay(10);
    rightBack.move_velocity(-64);
    rightFront.move_velocity(-64);
    leftBack.move_velocity(64);
    leftFront.move_velocity(64);
  }
}
// rotate counterclockwise
void rotateCCW(double objAngle) {
  gyro.reset();
// move motors to turn
  while (gyro.get_value() > objAngle) {
    pros::delay(10);
    rightBack.move_velocity(64);
    rightFront.move_velocity(64);
    leftBack.move_velocity(-64);
    leftFront.move_velocity(-64);
  }
}
*/
#endif
