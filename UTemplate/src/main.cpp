#include "vex.h"

using namespace vex;
competition Competition;
/*---------------------------------------------------------------------------*/
/*                             VEXcode Config                                */
/*                                                                           */
/*  Before you do anything else, start by configuring your motors and        */
/*  sensors. In VEXcode Pro V5, you can do this using the graphical          */
/*  configurer port icon at the top right. In the VSCode extension, you'll   */
/*  need to go to robot-config.cpp and robot-config.h and create the         */
/*  motors yourself by following the style shown. All motors must be         */
/*  properly reversed, meaning the drive should drive forward when all       */
/*  motors spin forward.                                                     */
/*---------------------------------------------------------------------------*/

int LBPositionState = 0;

/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your motors.                                     */
/*---------------------------------------------------------------------------*/

Drive chassis(

//Pick your drive setup from the list below:
//ZERO_TRACKER_NO_ODOM
//ZERO_TRACKER_ODOM
//TANK_ONE_FORWARD_ENCODER
//TANK_ONE_FORWARD_ROTATION
//TANK_ONE_SIDEWAYS_ENCODER
//TANK_ONE_SIDEWAYS_ROTATION
//TANK_TWO_ENCODER
//TANK_TWO_ROTATION
//MECANUM_IMU
//MECANUM_TWO_ROTATION
//Write it here:
MECANUM_IMU,

//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

//Left Front Motors:
motor_group(LeftFront),

//Left Rear Motors:
motor_group(LeftRear1, LeftRear2),

//Right Front Motors:
motor_group(RightFront),

//Right Rear Motors:
motor_group(RightRear1, RightRear2),

//Specify the PORT NUMBERS of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
PORT8,

//Input your wheel diameter. (4" omnis are actually closer to 4.125"):
2,

//External ratio, must be in decimal, in the format of input teeth/output teeth.
//If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
//If the motor drives the wheel directly, this value is 1:
1,

//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
//For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
360,

/*---------------------------------------------------------------------------*/
/*                                  PAUSE!                                   */
/*                                                                           */
/*  The rest of the drive constructor is for robots using POSITION TRACKING. */
/*  If you are not using position tracking, leave the rest of the values as  */
/*  they are.                                                                */
/*---------------------------------------------------------------------------*/

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
8,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
2.75,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
6.25,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
1,

//Sideways tracker diameter (reverse to make the direction switch):
-2.75,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
5.5

);

int current_auton_selection = 0;
bool auto_started = false;

/**
 * Function before autonomous. It prints the current auton number on the screen
 * and tapping the screen cycles the selected auton by 1. Add anything else you
 * may need, like resetting pneumatic components. You can rename these autons to
 * be more descriptive, if you like.
 */

void pre_auton() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  default_constants();
  LB.resetPosition();
  while(!auto_started){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5, 20, "JAR Template v1.2.0");
    Brain.Screen.printAt(5, 40, "Battery Percentage:");
    Brain.Screen.printAt(5, 60, "%d", Brain.Battery.capacity());
    Brain.Screen.printAt(5, 80, "Chassis Heading Reading:");
    Brain.Screen.printAt(5, 100, "%f", chassis.get_absolute_heading());
    Brain.Screen.printAt(5, 120, "Selected Auton:");
    switch(current_auton_selection){
      case 0:
        Brain.Screen.printAt(5, 140, "Auton 1");
        break;
      case 1:
        Brain.Screen.printAt(5, 140, "Auton 2");
        break;
      case 2:
        Brain.Screen.printAt(5, 140, "Auton 3");
        break;
      case 3:
        Brain.Screen.printAt(5, 140, "Auton 4");
        break;
      case 4:
        Brain.Screen.printAt(5, 140, "Auton 5");
        break;
      case 5:
        Brain.Screen.printAt(5, 140, "Auton 6");
        break;
      case 6:
        Brain.Screen.printAt(5, 140, "Auton 7");
        break;
      case 7:
        Brain.Screen.printAt(5, 140, "Auton 8");
        break;
    }
    if(Brain.Screen.pressing()){
      while(Brain.Screen.pressing()) {}
      current_auton_selection ++;
    } else if (current_auton_selection == 8){
      current_auton_selection = 0;
    }
    task::sleep(10);
  }
}

/**
 * Auton function, which runs the selected auton. Case 0 is the default,
 * and will run in the brain screen goes untouched during preauton. Replace
 * drive_test(), for example, with your own auton function you created in
 * autons.cpp and declared in autons.h.
 */

void autonomous(void) {
  auto_started = true;
  switch(current_auton_selection){ 
    case 0:
      red_non_rush();
      break;
    case 1:         
      red_rush();
      break;
    case 2:
      blue_non_rush();
      break;
    case 3:
      blue_rush();
      break;
    case 4:
      full_test();
      break;
    case 5:
      odom_test();
      break;
    case 6:
      tank_odom_test();
      break;
    case 7:
      
      break;
 }
}

void doinkerToggle() {
  doinker = !doinker;
}
void clampToggle() {
  mgClamp = !mgClamp;
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop

  //LB.setStopping(hold);
  doinker = false;
  mgClamp = false;
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    //Replace this line with chassis.control_tank()
    chassis.control_mecanum();

    if (Controller1.ButtonB.pressing()) {
            IntakeS2.spin(vex::directionType::fwd, 600, vex::velocityUnits::rpm);
            IntakeS1.spin(vex::directionType::fwd, 200, vex::velocityUnits::rpm);
    }
    else if (Controller1.ButtonDown.pressing()) {
            IntakeS2.spin(vex::directionType::rev, 600, vex::velocityUnits::rpm);
            IntakeS1.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);
    }
    else {
            IntakeS2.stop(vex::brakeType::hold);
            IntakeS1.stop(vex::brakeType::hold);
    }

    Controller1.ButtonR1.pressed(doinkerToggle);
    Controller1.ButtonR2.pressed(clampToggle);

 /*
    if (Controller1.ButtonL1.pressing()) {
            vex::task::sleep(200); // Debounce delay
            LBPositionState = (LBPositionState + 1) % 3; // Cycle through 0, 1, 2
            switch (LBPositionState) {
                case 0:
                    LB.spinToPosition(5, deg, 200, rpm);
                    break;
                case 1:
                    LB.spinToPosition(-64, deg, 200, rpm);
                    break;
                case 2:
                    IntakeS2.spinFor(-250, msec, 600, rpm);
                    LB.spinToPosition(-480, deg, 200, rpm);
                    LB.spinToPosition(5, deg, 200, rpm); 
                    break;
            }
        }

    if (Controller1.ButtonL2.pressing()) {
            LB.stop(vex::brakeType::hold);
            LB.spinToPosition(0, deg, 200, rpm);
            LBPositionState = 0; // Ensure state matches the reset position
            vex::task::sleep(200); // Debounce delay
        }
*/


    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
