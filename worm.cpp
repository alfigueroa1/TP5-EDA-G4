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
	lookingRight = true;
	state = MOVERIGHT;

	//no hay pared, entero movimiento
	if (x < XMAX - MOVEINPIXELS)
	{
		//5 frames no motion
		for (unsigned int i = 0; i < 5; i++)
		{
			this->update();
		}

		//3 frames warm-up (??)
		for (unsigned int i = 0; i < 3; i++)
		{
			this->update();
		}

		frameCount = 15;
		//3 rounds of walking frames (3 x 14 frames)
		for (unsigned int i = 0; i < 3; i++)
		{
			for (unsigned int j = 0; j < frameCount; j++)
			{
				this->update();
			}
			x = x + MOVEINPIXELS / 3;	//cada vez 9 px adelante = 27 px total
		}
	}
	//hay pared, mueve hasta la pared, termina movimiento?
	else
	{
		//TODO: animation

		x = XMAX;
	}
}

void Worm::walkLeft()
{
	lookingRight = false;
	state = MOVELEFT;
	//no hay pared, entero movimiento
	if (x > XMIN + MOVEINPIXELS)
	{
		//5 frames no motion
		for (unsigned int i = 0; i < 5; i++)
		{
			this->update();
		}

		//3 frames warm-up (??)
		for (unsigned int i = 0; i < 3; i++)
		{
			this->update();
		}

		frameCount = 15;
		//3 rounds of walking frames (3 x 14 frames)
		for (unsigned int i = 0; i < 3; i++)
		{
			for (unsigned int j = 0; j < frameCount; j++)
			{
				this->update();
			}
			x = x - MOVEINPIXELS / 3;	//cada vez 9 px adelante = 27 px total
		}
	}
	//hay pared, mueve hasta la pared, termina movimiento?
	else
	{
		x = XMIN;
	}
}

void Worm::stopWalking()
{
	state = IDLE;
}

void Worm::update()
{
	//update frontend
}

//Debugging
void Worm::print()
{
	cout << "Position x: " << x << endl;
	cout << "Position y: " << y << endl;
	cout << "Looking right: " << lookingRight << endl;
	cout << "State: " << state << endl;
}