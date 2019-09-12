#pragma once
#include "types.h"
typedef uint wormState;

class Worm {
public:
	Worm();
	jump();
	walkRight();
	walkLeft();
	stopWalking();
	update();

private:
	wormState state;
	uint frameCount;
	double x;
	double y;
	bool lookingRight;
};