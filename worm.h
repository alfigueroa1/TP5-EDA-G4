#pragma once
#include "types.h"

//typedef uint wormState;

enum wormState { IDLE, JUMPING, TURNRIGHT, TURNLEFT, MOVERIGHT, MOVELEFT };



class Worm {
public:
	Worm(double pos_x, double pos_y);
	void jump();
	void walkRight();
	void walkLeft();
	void stopWalking();
	void update();
	void print();

private:
	wormState state;
	uint frameCount;
	double x;
	double y;
	bool lookingRight;
};