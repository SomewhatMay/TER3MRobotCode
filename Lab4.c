#pragma config(Sensor, in1,    leftLineFollower, sensorLineFollower)
#pragma config(Sensor, in2,    centerLineFollower, sensorLineFollower)
#pragma config(Sensor, in3,    rightLineFollower, sensorLineFollower)
#pragma config(Sensor, in6,    gyro,           sensorGyro)
#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl6,  touchSensor,    sensorTouch)
#pragma config(Sensor, dgtl8,  sonarSensor,    sensorSONAR_cm)
#pragma config(Sensor, dgtl11, armEncoder,     sensorQuadEncoder)
#pragma config(Motor,  port1,           leftMotor,     tmotorVex393, openLoop)
#pragma config(Motor,  port6,           clawMotor,     tmotorVex393, openLoop)
#pragma config(Motor,  port7,           armMotor,      tmotorVex393, openLoop)
#pragma config(Motor,  port10,          rightMotor,    tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "commands.c"

task main() {
	initializeSystem();

	// Origin is top left.
	// Points are represented as (y, x)

	// Robot starting at (2, 1)

	int target[4][3] = {
		{1, 0, 270},
		{1, 2, 90},
		{0, 2, 0},
		{2, 2, 180}
	};

	// int target[2][3] = {
	// 	{0, 0, 90},
	// 	{0, 2, 0}
	// };


	for (int i = 0; i < 2; i++) {
		// Pick up the object
		openClaw();
		moveToPosition(target[i][0], target[i][1]);
		wait1Msec(350);
		turnToPosition(target[i][2]);

		wait1Msec(350);
		interact(1);

		// Go to drop-off location
		moveToPosition(target[i + 1][0], target[i + 	1][1]);
		wait1Msec(350);
		turnToPosition(target[i + 1][2]);

		// moveForward(10);
		wait1Msec(350);
		interact(0);

		// moveForward(-10);

		// Go to origin
		moveToPosition(ROBOT_POSITION_R, ROBOT_POSITION_C);
		turnToPosition(0);
		closeClaw();
		wait1Msec(350);
	}

	resetSystem();
}
