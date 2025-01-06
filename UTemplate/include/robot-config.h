using namespace vex;

extern brain Brain;

//To set up a motor called LeftFront here, you'd use
//extern motor LeftFront;

//Add your devices below, and don't forget to do the same in robot-config.cpp:
extern controller Controller1;
extern motor LeftFront;
extern motor LeftRear1;
extern motor LeftRear2;
extern motor RightFront;
extern motor RightRear1;
extern motor RightRear2;
extern motor IntakeS1;
extern motor IntakeS2;
extern motor LB;
extern digital_out mgClamp;
extern digital_out doinker;

void  vexcodeInit( void );