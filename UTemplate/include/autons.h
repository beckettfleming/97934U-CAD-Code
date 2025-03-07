#pragma once
#include "JAR-Template/drive.h"

class Drive;

extern Drive chassis;

void default_constants();

void drive_test();
void turn_test();
void swing_test();
void full_test();
void odom_test();
void tank_odom_test();
void DriveChassis();

void red_non_rush();
void red_rush();
void blue_non_rush();
void blue_rush();