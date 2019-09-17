#pragma once
#include "types.h"
#include "wormFSM.h"
#include "front.h"

#define WSTATES 6
#define WEVENTS 6

//typedef uint wormState;

#define WX(x) (static_cast<void (wormFSM::* ) (void)>(&Worm:: x))

enum wormState : stateTypes { IDLE, JUMPING, LOOKRIGHT, LOOKLEFT, MOVERIGHT, MOVELEFT };

enum events { UP, RIGHT, LEFT, HOLDRIGHT, HOLDLEFT, RELEASE, STOP };

enum wormSprites { JUMP1, JUMP2, JUMP3, JUMP4, JUMP5, JUMP6, JUMP7, JUMP8, JUMP9, JUMP10,
	WALK1, WALK2, WALK3, WALK4, WALK5, WALK6, WALK7, WALK8, WALK9, WALK10, WALK11, WALK12, WALK13, WALK14, WALK15 };

class Worm : public wormFSM
{
public:
	//constructor
	Worm(double pos_x, double pos_y) : wormFSM(&wormTable[0][0], WSTATES, WEVENTS, IDLE) {}

	//acciones
	void jump();
	void toggleRight(void);
	void toggleLeft(void);
	void walkRight();
	void walkLeft();
	void stopWalking();
	void print();
	int getSprite();
	double getX();
	double getY();
	void evHand(TrueEvent ev);
	bool getLookingRight();

private:
	wormState state;
	uint frameCount;
	double x;
	double y;
	uint sprite;
	bool lookingRight;
	double speedX;
	double speedY;
	//										    UP						  RIGHT						    LEFT						HOLDRIGHT					  HOLDLEFT					  STOP
	cellType wormTable[WSTATES][WEVENTS] = { { {JUMPING, WX(jump)},		 {LOOKRIGHT, WX(toggleRight)}, {LOOKLEFT, WX(toggleLeft)}, {LOOKRIGHT, WX(toggleRight)}, {LOOKLEFT, WX(toggleLeft)}, {IDLE, WX(nothing)} },				//IDLE
											 { {JUMPING, WX(nothing)},	 {JUMPING, WX(nothing)},	   {JUMPING, WX(nothing)},	   {JUMPING, WX(nothing)},		 {JUMPING, WX(nothing)},	 {JUMPING, WX(nothing)} },			//JUMPING
											 { {JUMPING, WX(jump)},		 {LOOKRIGHT, WX(walkRight)},   {LOOKLEFT, WX(toggleLeft)}, {MOVERIGHT, WX(walkRight)},	 {LOOKLEFT, WX(toggleLeft)}, {LOOKRIGHT, WX(nothing)} },		//LOOKRIGHT
											 { {JUMPING, WX(jump)},		 {LOOKRIGHT, WX(toggleRight)}, {LOOKLEFT, WX(walkLeft)},   {LOOKRIGHT, WX(toggleRight)}, {MOVELEFT, WX(walkLeft)},	 {LOOKLEFT, WX(nothing)} },			//LOOKLEFT
											 { {MOVERIGHT, WX(nothing)}, {MOVERIGHT, WX(nothing)},	   {MOVERIGHT, WX(nothing)},   {MOVERIGHT, WX(nothing)},	 {MOVERIGHT, WX(nothing)},	 {LOOKRIGHT, WX(stopWalking)} },	//MOVERIGHT
											 { {MOVELEFT, WX(nothing)},	 {MOVELEFT, WX(nothing)},	   {MOVELEFT, WX(nothing)},	   {MOVELEFT, WX(nothing)},		 {MOVELEFT, WX(nothing)},	 {LOOKLEFT, WX(stopWalking)} } };	//MOVELEFT
};