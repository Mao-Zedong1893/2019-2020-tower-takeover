#include "main.h"
#include "globals.hpp"
#include "tray.h"

void tilter(int power){
    angleAdjuster.move(power);
}

void setAngler(){
  int anglePower = 50 * (master.get_digital(pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_L1) - master.get_digital(pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_L2));
  tilter(anglePower);
  if (angleAdjuster.get_position() >= 3917){
    angleAdjuster.move_velocity(0);
  }
}
