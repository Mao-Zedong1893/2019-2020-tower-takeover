// Code for a tray bot

#include "main.h"
#include "globals.hpp"
#include "auton.hpp"
#include "tray.h"s

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(3, "I was pressed!");
	} else {
		pros::lcd::clear_line(3);
	}
}

void intakeMove(){
    if(master.get_digital(pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_R1)){
        leftIntake.move(127);
        rightIntake.move(-127);
    } else if (master.get_digital(pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_R2) == 1) {
        leftIntake.move(-127);
        rightIntake.move(127);
    }
    else{
        leftIntake.move(0);
        rightIntake.move(0);
    }
}

void tilter(){
    if(master.get_digital(pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_L1) == 1){
        angleAdjuster.move(-127);
    } else if (master.get_digital(pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_L2) == 1) {
        angleAdjuster.move(127);
    }
    else{
        angleAdjuster.move(0);
    }
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	// very important to use if u are not using
	// if delete this line, then have to use pro:: to avoid errors
	using namespace pros;
	lcd::initialize();
	lcd::set_text(1, "Hello PROS User!");
	// drive motors
	Motor leftFront(9,MOTOR_GEARSET_18,false,MOTOR_ENCODER_COUNTS);
	Motor leftBack(2,MOTOR_GEARSET_18,false,MOTOR_ENCODER_COUNTS);
	Motor rightFront(3,MOTOR_GEARSET_18,true,MOTOR_ENCODER_COUNTS);
	Motor rightBack(4,MOTOR_GEARSET_18,true,MOTOR_ENCODER_COUNTS);
	// intake motors
	Motor leftIntake(7, MOTOR_GEARSET_18, true, MOTOR_ENCODER_COUNTS);
	Motor rightIntake(8, MOTOR_GEARSET_18, false, MOTOR_ENCODER_COUNTS);
	// arm motor
	//Motor arm(5, MOTOR_GEARSET_18, false, MOTOR_ENCODER_COUNTS);
	// angleAdjuster motor
	Motor angleAdjuster(6, E_MOTOR_GEARSET_36, false, MOTOR_ENCODER_COUNTS);
	ADIGyro gyro(1);
	//lcd::register_btn1_cb(on_center_button);
	// controller init
	Controller master (E_CONTROLLER_MASTER);
}
/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {



}
/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {

moveStaight(10);


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
	*/

}


/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	using namespace pros;
	/*
	Controller master(E_CONTROLLER_MASTER);
	Motor left_mtr(1);
	Motor right_mtr(2);
	while (true) {
		lcd::print(0, "%d %d %d", (lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
		int left = master.get_analog(ANALOG_LEFT_Y);
		int right = master.get_analog(ANALOG_RIGHT_Y);
		left_mtr = left;
		right_mtr = right;
		delay(20);
		*/
		// motor inits
		//drive
		Motor leftFront(9);
		Motor leftBack(2);
		Motor rightFront(3);
		Motor rightBack(7);
		// intake
		Motor leftIntake(5);
		Motor rightIntake(8);
		//arm
		//Motor arm(5);
		// angle adjuster (tray tilter)
		Motor angleAdjuster(6);

		//variable inits
		int vexRTCh1, vexRTCh2, vexRTCh4;
		while(true){
			//tank drive code
			/*
			left_wheels.move(master.get_analog(ANALOG_LEFT_Y));
			right_wheels.move(master.gt_analog(ANALOG_RIGHT_Y));
			*/
			// variable definitions
			vexRTCh2 = master.get_analog(controller_analog_e_t::E_CONTROLLER_ANALOG_RIGHT_Y);
			vexRTCh1 = master.get_analog(controller_analog_e_t::E_CONTROLLER_ANALOG_RIGHT_X);
			vexRTCh4 = master.get_analog(controller_analog_e_t::E_CONTROLLER_ANALOG_LEFT_X);

			//intake = master.get_digital(controller_digital_e_t::E_CONTROLLER_DIGITAL_R1);
			//intakeMode = master.get_digital(controller_digital_e_t::E_CONTROLLER_DIGITAL_R2);

			//arcade drive code
			rightFront.move(vexRTCh2 - vexRTCh1 - vexRTCh4);
			rightBack.move(vexRTCh2 - vexRTCh1 + vexRTCh4);
			leftFront.move(vexRTCh2 + vexRTCh1 + vexRTCh4);
			leftBack.move(vexRTCh2 + vexRTCh1 - vexRTCh4);

			//intake Code
			intakeMove();

/*
			// intake toggle code
			if (intake == 1) intakeOn = !intakeOn;
			if (intakeMode == 1) intakeCCW = !intakeCCW;

			if (intakeOn) {
				if (intakeCCW) {
					intakeDir = 127;
				} else {
					intakeDir = -127;
				}
				leftIntake.move(intakeDir);
				rightIntake.move(intakeDir);
			}
			else {
				leftIntake.move(0);
				rightIntake.move(0);
			}
*/
			// important delay for multitasking of the brain and to avoid abnormailities.
			// std::cout << left_wheels.get_voltage()*0.010583 << std::endl;

			//angle adjuster
			tilter();
			delay(15);
		}

	}
