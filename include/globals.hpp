#ifndef GLOBALS_HPP
#define GLOBALS_HPP
#include "main.h"

extern pros::Controller master;

extern pros::Motor leftFront;
extern pros::Motor leftBack;
extern pros::Motor rightFront;
extern pros::Motor rightBack;
// intake motors
extern pros::Motor leftIntake;
extern pros::Motor rightIntake;
// arm motor
//Motor arm(5, MOTOR_GEARSET_18, false, MOTOR_ENCODER_COUNTS);
// angleAdjuster motor
extern pros::Motor angleAdjuster;

extern pros::ADIGyro gyro;



#endif
