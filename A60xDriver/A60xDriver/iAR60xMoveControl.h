#pragma once
#include "Elements/MoveStructure.h"

class iAR60xMoveControl
{
public:
	iAR60xMoveControl();
	virtual ~iAR60xMoveControl();

	virtual void setAngles(MoveStructure angles[]) = 0;
	virtual void setAngle(MoveStructure angle) = 0;
};

