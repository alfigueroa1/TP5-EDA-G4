#pragma once
#include "types.h"

//typedef uint wormState;

enum wormState { IDLE, JUMPING, TURNRIGHT, TURNLEFT, MOVERIGHT, MOVELEFT };

enum wormSprites {JUMP1, JUMP2, JUMP3, JUMP4, JUMP5, JUMP6, JUMP7, JUMP8, JUMP9, JUMP10,
				WALK1, WALK2, WALK3, WALK4, WALK5, WALK6, WALK7, WALK8, WALK9, WALK10, WALK11, WALK12, WALK13, WALK14, WALK15,
};

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
	uint sprite;
	bool lookingRight;
};