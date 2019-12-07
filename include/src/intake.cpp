#include "main.h"
#include "globals.hpp"
#include "intake.h"

void intakeMove(int power){
  leftIntake.move(-power);
  rightIntake.move(-power);
}

void setIntake(){
  int intakePower = 80 * (master.get_digital(pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_R1) - master.get_digital(pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_R2));
  intakeMove(intakePower);
}
