#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain  Brain;
//The motor constructor takes motors as (port, ratio, reversed), so for example
//motor LeftFront = motor(PORT1, ratio6_1, false);

//Add your devices below, and don't forget to do the same in robot-config.h:
motor LeftFront = motor(PORT9, ratio6_1, true);
motor LeftRear1 = motor(PORT6, ratio6_1, false);
motor LeftRear2 = motor(PORT7, ratio6_1, true);
motor RightFront = motor(PORT3, ratio6_1, false);
motor RightRear1 = motor(PORT11, ratio6_1, true);
motor RightRear2 = motor(PORT18, ratio6_1, false);
motor IntakeS1R = motor(PORT15, ratio18_1, true);
motor IntakeS1L = motor (PORT19, ratio18_1, true);
motor IntakeS2 = motor(PORT5, ratio6_1, true);

motor_group IntakeS1 = (IntakeS1L, IntakeS1R);

motor_group Intake = (IntakeS1L, IntakeS1R, IntakeS2);

motor LB = motor(PORT19, ratio6_1, false);
controller Controller1 = controller();
digital_out mgClamp = digital_out(Brain.ThreeWirePort.B);
digital_out doinker = digital_out(Brain.ThreeWirePort.A);

void vexcodeInit( void ) {
  // nothing to initialize
}