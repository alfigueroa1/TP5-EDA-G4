#pragma once
#include "types.h"
//#include "wormFSM.h"
#include "trueEv.h"

#define WSTATES 6
#define WEVENTS 6

//typedef uint wormState;

//#define WX(x) (static_cast<void (wormFSM::* ) (void)>(&Worm:: x))

enum moveKeys {UP, LEFT, RIGHT};

enum wormState { IDLE, PREJUMP, JUMPING, POSTJUMP, LOOKRIGHT, LOOKLEFT, MOVERIGHT, MOVELEFT };

enum events { EUP, ERIGHT, ELEFT, EHOLDRIGHT, EHOLDLEFT, ERELEASE, ESTOP };

enum wormSprites { JUMP1, JUMP2, JUMP3, JUMP4, JUMP5, JUMP6, JUMP7, JUMP8, JUMP9, JUMP10,
	WALK1, WALK2, WALK3, WALK4, WALK5, WALK6, WALK7, WALK8, WALK9, WALK10, WALK11, WALK12, WALK13, WALK14, WALK15 };

class Worm
{
public:
	//constructor
	Worm(double pos_x, double pos_y); //: wormFSM(&wormTable[0][0], WSTATES, WEVENTS, IDLE) {}

	//acciones
	void nothing(void);
	void jump();
	void noJump();
	void toggleRight(void);
	void toggleLeft(void);
	void walkRight();
	void walkLeft();
	void stopWalking();
	void calcJump();
	void print();
	int getSprite();
	double getX();
	double getY();
	void stateHand();
	bool getLookingRight();
	void normalizePos();
private:
	wormState state;
	uint frameCount;
	double x;
	double y;
	uint sprite;
	bool lookingRight;
	double speedX;
	double speedY;
	bool keys[3];
	//										    UP						  RIGHT						    LEFT						HOLDRIGHT					  HOLDLEFT					  STOP
	//cellType wormTable[WSTATES][WEVENTS] = { { {JUMPING, WX(jump)},		 {LOOKRIGHT, WX(toggleRight)}, {LOOKLEFT, WX(toggleLeft)}, {LOOKRIGHT, WX(toggleRight)}, {LOOKLEFT, WX(toggleLeft)}, {IDLE, WX(nothing)} },				//IDLE
	//										 { {JUMPING, WX(nothing)},	 {JUMPING, WX(nothing)},	   {JUMPING, WX(nothing)},	   {JUMPING, WX(nothing)},		 {JUMPING, WX(nothing)},	 {JUMPING, WX(nothing)} },			//JUMPING
	//										 { {JUMPING, WX(jump)},		 {LOOKRIGHT, WX(walkRight)},   {LOOKLEFT, WX(toggleLeft)}, {MOVERIGHT, WX(walkRight)},	 {LOOKLEFT, WX(toggleLeft)}, {LOOKRIGHT, WX(nothing)} },		//LOOKRIGHT
	//										 { {JUMPING, WX(jump)},		 {LOOKRIGHT, WX(toggleRight)}, {LOOKLEFT, WX(walkLeft)},   {LOOKRIGHT, WX(toggleRight)}, {MOVELEFT, WX(walkLeft)},	 {LOOKLEFT, WX(nothing)} },			//LOOKLEFT
	//										 { {MOVERIGHT, WX(nothing)}, {MOVERIGHT, WX(nothing)},	   {MOVERIGHT, WX(nothing)},   {MOVERIGHT, WX(nothing)},	 {MOVERIGHT, WX(nothing)},	 {LOOKRIGHT, WX(stopWalking)} },	//MOVERIGHT
	//										 { {MOVELEFT, WX(nothing)},	 {MOVELEFT, WX(nothing)},	   {MOVELEFT, WX(nothing)},	   {MOVELEFT, WX(nothing)},		 {MOVELEFT, WX(nothing)},	 {LOOKLEFT, WX(stopWalking)} } };	//MOVELEFT
};