#pragma config(StandardModel, "RVW CLAWBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define DRIVE_TRAIN_SPEED 50
#define DRIVE_TRAIN_ANGLE 90
#define ARM_SPEED 20
#define CLAW_SPEED 40


static int driveTrainSpeed = 0;
static int driveTrainAngle = 0;
static int armSpeed = 0;
static int armPosition = 0;
static int clawSpeed = 0;
static int clawPosition = 0;


/* Robot Initializer */
void initializeSystem() {
	setDriveTrainSpeed(DRIVE_TRAIN_SPEED);
	setDriveTrainAngle(DRIVE_TRAIN_ANGLE); // robot points north
	stopDriveTrain();
	setArmSpeed(ARM_SPEED);
	setArmPosition(0);
	stopArm()
	setClawSpeed(CLAW_SPEED);
	setClawPosition(0);
	stopClaw();
}


/* DriveTrain Functions */
void setDriveTrainSpeed(int speed) {
	driveTrainSpeed = speed;
}

void setDriveTrainAngle(int angle) {
	driveTrainAngle = angle;
}

void stopDriveTrain() {
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
}


/* Arm Functions */
void setArmSpeed(int speed) {
	armSpeed = speed;
}

void setArmPosition(int degrees) {
		armPosition = degrees;
}

void stopArm() {
	motor[armMotor] = 0;
}


/* Claw Functions */
void setClawSpeed(int speed) {
	clawSpeed = 0;
}

void setClawPosition(int degrees) {
	clawPosition = degrees;
}

void stopClaw() {
	motor[claw] = 0;
}


/* Robot Reset */
void resetSystem() {
	stopDriveTrain();
	setDriveTrainAngle(0);
	setDriveTrainSpeed(0);

	stopArm();
	setArmSpeed(0);

	stopClaw();
	setClawSpeed(0);
}


/* Main Task Function */
task main()
{
	initializeSystem();

	motor[leftMotor] = driveTrainSpeed;
	motor[rightMotor] = -driveTrainSpeed;
	wait1Msec(300);

	resetSystem();
}
