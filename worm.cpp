/*******************************************************************************
							 INCLUDE HEADER FILES
 ******************************************************************************/
#include <iostream>
#include "worm.h"

#define OFFSET 9
#define PI		3.14159265358979323846		
#define RAD(x)	((x)/180.*PI)
#define JUMP_SPEED 4.5
#define LOW_LIMIT 616
#define UP_LIMIT	500
#define R_LIMIT 1212
#define L_LIMIT	701

using namespace std;

//paredes
double XMIN = 701;
double XMAX = 1212;
double YCOORD = 616;
double MOVEINPIXELS = 27;

double G = 0.24;
double INITSPEED = 4.5;			//initial speed

/*******************************************************************************
									CYCLE
 ******************************************************************************/
 
void Worm::stateHand(void)
{	
	frameCount++;
	switch (state)
	{
	case IDLE:
		frameCount = 0;
		sprite = IDLE;
		speedY = 0;
		if (keys[UP] == true)
			state = PREJUMP;
		else if (keys[RIGHT] == true)
			state = LOOKRIGHT;
		else if (keys[LEFT] == true)
			state = LOOKLEFT;
		break;
	case PREJUMP:
		if (frameCount > 3)
			state = JUMPING;
		sprite = frameCount;
		break;
	case JUMPING:
		sprite = --frameCount;
		calcJump();
		break;
	case POSTJUMP:
		speedY = 0;
		if (frameCount >= 10)
			state = IDLE;
		sprite = frameCount;
		break;
	case LOOKRIGHT:
		sprite = WALK1;
		if (keys[UP] == true)
			state = PREJUMP;
		if (keys[RIGHT] == true && frameCount >= 5)
			state = MOVERIGHT;
		if (keys[LEFT] == true)
			state = LOOKLEFT;
		break;
	case LOOKLEFT:
		sprite = WALK1;
		if (keys[UP] == true)
			state = PREJUMP;
		if (keys[RIGHT] == true)
			state = LOOKRIGHT;
		if (keys[LEFT] == true && frameCount >= 5)
			state = MOVELEFT;
		break;
	case MOVERIGHT:
		if (frameCount < 17)
			sprite = frameCount - JUMP10;
		else if (frameCount < 31)
			sprite = frameCount - JUMP10 - 17;
		else if (frameCount < 45)
			sprite = frameCount - JUMP10 - 31;
		if (frameCount == 17 || frameCount == 31 || frameCount == 45){
			x += OFFSET;
			sprite = WALK1;
		}
		if (frameCount > 45)
			state = IDLE;
		break;
	case MOVELEFT :
		if (frameCount < 17)
			sprite = frameCount - JUMP10;
		else if (frameCount < 31)
			sprite = frameCount - JUMP10 - 17;
		else if (frameCount < 45)
			sprite = frameCount - JUMP10 - 31;
		if (frameCount == 17 || frameCount == 31 || frameCount == 45) {
			x -= OFFSET;
			sprite = WALK1;
		}
		if (frameCount > 45)
			state = IDLE;
		break;
	default: state = IDLE;	break;
	}
	normalizePos();
}

 /*********************************************************************************
						 GLOBAL FUNCTION DEFINITIONS
  ********************************************************************************/

//Inicializando el worm
Worm::Worm(double pos_x, double pos_y)
{
	state = IDLE;
	frameCount = 0;
	x = pos_x;
	y = pos_y;
	lookingRight = true;
	sprite = 0;
	speedY = 0;
	speedX = 0;
}

void Worm::normalizePos() {
	if (x < L_LIMIT) {
		x = L_LIMIT;
	}
	else if (x > R_LIMIT) {
		x = R_LIMIT;
	}

	if (y < UP_LIMIT) {
		y = UP_LIMIT;
		speedY *= -1;
	}
	else if (y > LOW_LIMIT) {
		y = LOW_LIMIT;
		speedY = 0;
		state = IDLE;
	}
}
void Worm::noJump()
{
	keys[UP] = false;
}

void Worm::jump()
{
	if (state == IDLE) {
		state = PREJUMP;
		keys[UP] = true;
	}
	////inicializando el salto
	//if (state == IDLE)
	//{
	//	speedY = -sin(60 * PI / 180) * INITSPEED;	
	//	speedX = cos(60 * PI / 180) * INITSPEED;
	//	state = JUMPING;
	//	frameCount = 0;
	//}

	////warm-up:	sprites 0, 1, 2
	//if (state == JUMPING && frameCount >= 0 && frameCount < 3)
	//{
	//	sprite = frameCount;
	//	frameCount++;
	//}
	//
	////salto:	sprite 3
	//else if (state == JUMPING && frameCount == 3)
	//{
	//	sprite = 3;

	//	//Nueva posicion
	//	x += speedX * cos(60 / 180 * PI);
	//	y += speedY;

	//	//Nueva velocidad (speedX no cambia)
	//	speedY = speedY + G;

	//	//Termina salto (post jumping)
	//	if (y >= YCOORD)
	//	{
	//		y = YCOORD;
	//		frameCount++;
	//	}
	//}

	////post-jump:	sprites 4, 5, 6, 7, 8, 9
	//else if (state == JUMPING && frameCount >= 4 && frameCount < 10)
	//{
	//	sprite = frameCount;
	//	frameCount++;
	//}

	////jump done
	//else if (frameCount == 10)
	//{
	//	state = IDLE;
	//	frameCount = 0;
	//}
		
}

void Worm::walkRight()
{
	if (state == IDLE || state == LOOKRIGHT)
		state = LOOKRIGHT;
	////Walking sprites de 10 a 23
	////Frames de 0 a 44 (total 45) 
	//
	////inicializando walk
	//if (frameCount == 0)
	//{
	//	state = MOVERIGHT;
	//}

	////warm-up:	sprites 10, 11, 12 (??)
	//if (frameCount >= 0 && frameCount < 3)
	//{
	//	sprite = frameCount + 10;
	//}

	////walking:	sprites de 10 a 23
	//if (frameCount >= 3 && frameCount < 17)
	//{
	//	sprite = frameCount + 7;
	//	//state = HOLDRIGHT;
	//}
	//if (frameCount >= 17 && frameCount < 31)
	//{
	//	sprite = frameCount - 7;
	//}
	//if (frameCount >= 31 && frameCount < 45)
	//{
	//	sprite = frameCount - 21;
	//}

	//if (sprite == 23)
	//{
	//	x = x + MOVEINPIXELS/3;		//cada vez 9 px adelante = 27 px total
	//}

	////walk done
	//if (frameCount == 44)
	//{
	//	//algo
	//}
	//
	//frameCount++;
}

void Worm::walkLeft()
{
	if (state == IDLE || state == LOOKLEFT)
		state = LOOKLEFT;
	////inicializando walk
	//if (frameCount == 0)
	//{
	//	state = MOVELEFT;
	//}

	////warm-up:	sprites 10, 11, 12 (??)
	//if (frameCount >= 0 && frameCount < 3)
	//{
	//	sprite = frameCount + 10;
	//}

	////walking:	sprites de 10 a 23
	//if (frameCount >= 3 && frameCount < 17)
	//{
	//	sprite = frameCount + 7;
	//}
	//if (frameCount >= 17 && frameCount < 31)
	//{
	//	sprite = frameCount - 7;
	//}
	//if (frameCount >= 31 && frameCount < 45)
	//{
	//	sprite = frameCount - 21;
	//}

	//if (sprite == 23)
	//{
	//	x = x - MOVEINPIXELS / 3;		//cada vez 9 px adelante = 27 px total
	//}

	////walk done
	//if (frameCount == 44)
	//{
	//	//algo
	//}

	//frameCount++;
}

void Worm::stopWalking()
{
	if (state != MOVERIGHT && state != MOVELEFT && state != JUMPING)
		state = IDLE;
	return;
}

void Worm::calcJump() {

	speedY += G;

	if (lookingRight == false)
		x -= JUMP_SPEED * cos(RAD(60));
	else
		x += JUMP_SPEED * cos(RAD(60));

	y -= speedY;
	if (y >= LOW_LIMIT) {
		state = POSTJUMP;
		y = LOW_LIMIT;
		speedY = 0;
	}
	return;
}

int Worm::getSprite()
{
	return sprite;
}

double Worm::getX()
{
	return x;
}

double Worm::getY()
{
	return y;
}

void Worm::toggleRight(void)
{
	lookingRight = true;
}

void Worm::toggleLeft(void)
{
	lookingRight = false;
}

bool Worm::getLookingRight(void)
{
	return lookingRight;
}

void Worm::nothing(void){}

//void Worm::next(int event)
//{
//	temp = pTableFSM[static_cast<unsigned int>(state) * columnCount + event];
//	auto f = bind(temp.action, this);
//	f();
//	state = pTableFSM[state * columnCount + event].nextState;
//}

//Debugging
void Worm::print()
{
	cout << "Position x: " << x << endl;
	cout << "Position y: " << y << endl;
	cout << "Looking right: " << lookingRight << endl;
	cout << "State: " << state << endl;
}