/*******************************************************************************
							 INCLUDE HEADER FILES
 ******************************************************************************/
#include <iostream>
#include "worm.h"

#define OFFSET 9

using namespace std;

//paredes
double XMIN = 701;
double XMAX = 1212;
double YCOORD = 616;
double MOVEINPIXELS = 27;

double G = 0.24;
double INITSPEED = 4.5;			//initial speed
double PI = 3.14159265;

/*******************************************************************************
									CYCLE
 ******************************************************************************/
 
void Worm::stateHand(void)
{
	switch(state)
	{
	case IDLE:
		if (keys[UP] == true)
			state = PREJUMP;
		if (keys[RIGHT] == true)
			state = LOOKRIGHT;
		if (keys[LEFT] == true)
			state = LOOKLEFT;
		break;
	case PREJUMP :
		if (frameCount > 4)
			state = JUMPING;
		break;
	case JUMPING :
		calcJump();
		break;
	case POSTJUMP :
		if (frameCount > 6)
			state = IDLE;
		break;
	case LOOKRIGHT :
		if (keys[UP] == true)
			state = PREJUMP;
		if (keys[RIGHT] == true)
			state = MOVERIGHT;
		if (keys[LEFT] == true)
			state = LOOKLEFT;
		break;
	case LOOKLEFT :
		if (keys[UP] == true)
			state = PREJUMP;
		if (keys[RIGHT] == true)
			state = LOOKRIGHT;
		if (keys[LEFT] == true)
			state = MOVELEFT;
		break;
	case MOVERIGHT :
		if (frameCount == 17 || frameCount == 31 || frameCount == 45)
			x += OFFSET;
		if (frameCount > 45)
			state = IDLE;
			break;
	case MOVELEFT :
		if (frameCount == 17 || frameCount == 31 || frameCount == 45)
			x -= OFFSET;
		if (frameCount > 45)
			state = IDLE;
			break;
	}
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

void Worm::jump()
{
	//inicializando el salto
	if (state == IDLE)
	{
		speedY = -sin(60 * PI / 180) * INITSPEED;	
		speedX = cos(60 * PI / 180) * INITSPEED;
		state = JUMPING;
		frameCount = 0;
	}

	//warm-up:	sprites 0, 1, 2
	if (state == JUMPING && frameCount >= 0 && frameCount < 3)
	{
		sprite = frameCount;
		frameCount++;
	}
	
	//salto:	sprite 3
	else if (state == JUMPING && frameCount == 3)
	{
		sprite = 3;

		//Nueva posicion
		x += speedX * cos(60 / 180 * PI);
		y += speedY;

		//Nueva velocidad (speedX no cambia)
		speedY = speedY + G;

		//Termina salto (post jumping)
		if (y >= YCOORD)
		{
			y = YCOORD;
			frameCount++;
		}
	}

	//post-jump:	sprites 4, 5, 6, 7, 8, 9
	else if (state == JUMPING && frameCount >= 4 && frameCount < 10)
	{
		sprite = frameCount;
		frameCount++;
	}

	//jump done
	else if (frameCount == 10)
	{
		state = IDLE;
		frameCount = 0;
	}
		
}

void Worm::walkRight()
{
	//Walking sprites de 10 a 23
	//Frames de 0 a 44 (total 45) 
	
	//inicializando walk
	if (frameCount == 0)
	{
		state = MOVERIGHT;
	}

	//warm-up:	sprites 10, 11, 12 (??)
	if (frameCount >= 0 && frameCount < 3)
	{
		sprite = frameCount + 10;
	}

	//walking:	sprites de 10 a 23
	if (frameCount >= 3 && frameCount < 17)
	{
		sprite = frameCount + 7;
		//state = HOLDRIGHT;
	}
	if (frameCount >= 17 && frameCount < 31)
	{
		sprite = frameCount - 7;
	}
	if (frameCount >= 31 && frameCount < 45)
	{
		sprite = frameCount - 21;
	}

	if (sprite == 23)
	{
		x = x + MOVEINPIXELS/3;		//cada vez 9 px adelante = 27 px total
	}

	//walk done
	if (frameCount == 44)
	{
		//algo
	}
	
	frameCount++;
}

void Worm::walkLeft()
{
	//inicializando walk
	if (frameCount == 0)
	{
		state = MOVELEFT;
	}

	//warm-up:	sprites 10, 11, 12 (??)
	if (frameCount >= 0 && frameCount < 3)
	{
		sprite = frameCount + 10;
	}

	//walking:	sprites de 10 a 23
	if (frameCount >= 3 && frameCount < 17)
	{
		sprite = frameCount + 7;
	}
	if (frameCount >= 17 && frameCount < 31)
	{
		sprite = frameCount - 7;
	}
	if (frameCount >= 31 && frameCount < 45)
	{
		sprite = frameCount - 21;
	}

	if (sprite == 23)
	{
		x = x - MOVEINPIXELS / 3;		//cada vez 9 px adelante = 27 px total
	}

	//walk done
	if (frameCount == 44)
	{
		//algo
	}

	frameCount++;
}

void Worm::stopWalking()
{
	state = IDLE;
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