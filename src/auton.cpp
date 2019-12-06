#include "main.h"
#include "globals.hpp"
#include "move.h"


// move strait
void moveStaight(float objective) {
  int tickDistance = (objective/12.6)*900;
  while (rightFront.get_position () > objective) {
    pros::delay(10);
    leftBack.move_velocity(127);
    leftFront.move_velocity(127);
    rightBack.move_velocity(127);
    rightFront.move_velocity(127);
  }
}

// rotate clockwise
void rotateCW(float objAngle) {
  gyro.reset();
// move motors to turn
  while (gyro.get_value() < objAngle) {
    pros::delay(10);
    rightBack.move_velocity(-127);
    rightFront.move_velocity(-127);
    leftBack.move_velocity(127);
    leftFront.move_velocity(127);
  }
}
// rotate counterclockwise
void rotateCCW(float objAngle) {
  gyro.reset();
// move motors to turn
  while (gyro.get_value() > objAngle) {
    pros::delay(10);
    rightBack.move_velocity(127);
    rightFront.move_velocity(127);
    leftBack.move_velocity(-127);
    leftFront.move_velocity(-127);
  }
}


/*
void Auton() {

  using namespace okapi;

  const int rightFront = 3;
  const int rightBack = 4;
  const int leftFront = 9;
  const int leftBack = 2;
  const auto WHEEL_DIAMETER = 4_in;
const auto CHASSIS_WIDTH = 11_in;

  auto chassis = ChassisControllerFactory::create(
    leftFront, leftBack,
    rightFront, rightBack,
    AbstractMotor::gearset::green,
    {WHEEL_DIAMETER, CHASSIS_WIDTH}
  );

  void autonomous () {
    chassis.moveDistance(1_m);
    chassis.turnAngle(90_deg);
  }
}


moveStaight(12);

rotateCCW(180);

rotateCW(180);

}
*/
