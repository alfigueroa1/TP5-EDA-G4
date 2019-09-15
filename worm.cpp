/*******************************************************************************
							 INCLUDE HEADER FILES
 ******************************************************************************/
#include <iostream>
#include "worm.h"

using namespace std;

//paredes
double XMIN = 701;
double XMAX = 1212;
double YCOORD = 616;
double MOVEINPIXELS = 27;

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
}

void Worm::jump()
{
	if (state == IDLE)
	{
		//do jump
		//(parable etc.)

		state = IDLE;	//Termina salto
	}
}

void Worm::walkRight()
{
	//Walking sprites de 10 a 23
	//Frames de 8 a 49 (total 42)

	if (frameCount < 22)
	{
		sprite = frameCount + 2;
	}
	if (22 <= frameCount < 36)
	{
		sprite = frameCount - 12;
	}
	if (36 <= frameCount < 50)
	{
		sprite = frameCount - 26;
	}

	if (sprite = 23)
	{
		x = x + MOVEINPIXELS/3;		//cada vez 9 px adelante = 27 px total
	}
	
}

void Worm::walkLeft()
{
	if (frameCount < 22)
	{
		sprite = frameCount + 2;
	}
	if (22 <= frameCount < 36)
	{
		sprite = frameCount - 12;
	}
	if (36 <= frameCount < 50)
	{
		sprite = frameCount - 26;
	}

	if (sprite = 23)
	{
		x = x - MOVEINPIXELS / 3;		//cada vez 9 px adelante = 27 px total
	}
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

//Debugging
void Worm::print()
{
	cout << "Position x: " << x << endl;
	cout << "Position y: " << y << endl;
	cout << "Looking right: " << lookingRight << endl;
	cout << "State: " << state << endl;
}