#include "auton.hpp"
#include "tray.h"
#include "globals.hpp"
#include "intake.h"

void pathOne() {
  moveStaight(12);
  moveStaight(-24);
  tilterRaise();
  tilterLower();
   
}
