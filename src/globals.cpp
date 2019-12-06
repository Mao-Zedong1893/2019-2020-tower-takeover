#include "main.h"
#include "globals.hpp"

// drive motors
pros::Motor leftFront(9,MOTOR_GEARSET_18,false,MOTOR_ENCODER_COUNTS);
pros::Motor leftBack(2,MOTOR_GEARSET_18,false,MOTOR_ENCODER_COUNTS);
pros::Motor rightFront(3,MOTOR_GEARSET_18,true,MOTOR_ENCODER_COUNTS);
pros::Motor rightBack(4,MOTOR_GEARSET_18,true,MOTOR_ENCODER_COUNTS);
// intake motors
pros::Motor leftIntake(7, MOTOR_GEARSET_18, true, MOTOR_ENCODER_COUNTS);
pros::Motor rightIntake(8, MOTOR_GEARSET_18, false, MOTOR_ENCODER_COUNTS);
// arm motor
//Motor arm(5, MOTOR_GEARSET_18, false, MOTOR_ENCODER_COUNTS);
// angleAdjuster motor
pros::Motor angleAdjuster(6, MOTOR_GEARSET_36, false, MOTOR_ENCODER_COUNTS);
//gyro
pros::ADIGyro gyro (1);

pros::Controller master(CONTROLLER_MASTER);
