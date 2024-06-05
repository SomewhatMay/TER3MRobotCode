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

task main()
{
	initializeSystem();

	motor[armMotor] = armSpeed;
	wait1Msec(300);
	motor[armMotor]

	float delay = calculateTravelTime(200.0);
	startDrivetrain();
	wait1Msec(delay);
	stopDriveTrain();

	motor[clawMotor] = clawSpeed;
	wait1Msec(500);
	motor[clawMotor] = 0;

	delay = turn(180);
	wait1Msec(delay);
	stopDriveTrain();

	delay = calculateTravelTime(200.0);
	startDrivetrain();
	wait1Msec(delay);
	stopDriveTrain();

	delay = turn(-180);
	wait1Msec(delay);
	stopDriveTrain();

	delay = calculateTravelTime(10.0);
	startDrivetrain();
	wait1Msec(delay);
	stopDriveTrain();

	motor[clawMotor] = -clawSpeed;
	wait1Msec(500);
	motor[clawMotor] = 0;

	setDriveTrainSpeed(-DRIVE_TRAIN_SPEED);
	startDrivetrain();
	wait1Msec(delay);
	stopDriveTrain();


	resetSystem();
}
