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
		x = x + MOVEINPIXELS;
	}
	//hay pared, mueve hasta la pared, termina movimiento?
	else
	{
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
		x = x - MOVEINPIXELS;
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

}

//Debugging
void Worm::print()
{
	cout << "Position x: " << x << endl;
	cout << "Position y: " << y << endl;
	cout << "Looking right: " << lookingRight << endl;
	cout << "State: " << state << endl;
}