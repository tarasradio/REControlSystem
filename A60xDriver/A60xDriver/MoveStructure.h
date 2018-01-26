#pragma once
class MoveStructure
{
public:
	MoveStructure();
	~MoveStructure();

	int getMotor();
	int getAngle();

private:
	int motor;
	int angle;


};

