#include "main.h"
#include "globals.hpp"

int quadratic(int move){
  int(move > 0)
    return (move**2/127);
  else if (move < 0)
    return -(move**2/127)
  return 0;
}

int threshold(int value){
  if(abs(value) < 10)
    return 0;
}

int move(){
  int vexRTCh1, vexRTCh2, vexRTCh4, rightFrontMove, rightBackMove, lefftFrontMove, leftBackMove;

  vexRTCh1 = master.get_analog(pros::controller_analog_e_t:E_CONTROLLER_ANALOG_RIGHT_Y);
  vexRTCh2 = master.get_analog(pros::controller_analog_e_t:E_CONTRLLER_ANALOG_RIGHT_X);
  vexRTCh4 = master.get_analog(pros::controller_analog_e_t:E_CONTROLLER_ANALOG_LEFT_X);

  vexRTCh1 = threshold(vexRTCh1);
  vexRTCh2 = threshold(vexRTCh2);
  vexRTCh4 = threshold(vexRTCh4);

  //mecanum wheel arcade drive Code
  rightFrontMove = vexRTCh2 - vexRTCh1 - vexRTCh4;
  rightBackMove
}
