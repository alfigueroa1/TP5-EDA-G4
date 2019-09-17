/*******************************************************************************
							 INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include "keyboard.h"
#include "front.h"
#include "types.h"
 
 /*********************************************************************************
						GLOBAL FUNCTION DEFINITIONS
 ********************************************************************************/
void handleKeyInputs(bool keyPressed[KEYS]) {
	if (keyPressed[KEY_UP] == true) {
		
	}
	if (keyPressed[KEY_RIGHT] == true) {
		
	}
	if (keyPressed[KEY_LEFT] == true) {
		
	}
	if (keyPressed[KEY_W] == true) {
		
	}
	if (keyPressed[KEY_A] == true) {

	}
	if (keyPressed[KEY_D] == true) {

	}
	return;
}


void handleKeyPress(ALLEGRO_EVENT* ev, TrueEvent& trueEv, bool down, bool &ok) {
	bool press;
	if (down)
		press = true;
	else
		press = false;
	switch (ev->keyboard.keycode) {
		case ALLEGRO_KEY_UP:
			if(press)
				trueEv = UPPRESS;
			else 
				trueEv = UPUNPRESS;
			break;
		case ALLEGRO_KEY_LEFT:
			if (press)
				trueEv = LPRESS;
			else
				trueEv = LUNPRESS;
			break;
		case ALLEGRO_KEY_RIGHT:
			if (press)
				trueEv = RPRESS;
			else
				trueEv = RUNPRESS;
			break;
		case ALLEGRO_KEY_W:
			if (press)
				trueEv = WPRESS;
			else
				trueEv = WUNPRESS;
			break;
		case ALLEGRO_KEY_A:
			if (press)
				trueEv = APRESS;
			else
				trueEv = AUNPRESS;
			break;
		case ALLEGRO_KEY_D:
			if (press)
				trueEv = DPRESS;
			else
				trueEv = DUNPRESS;
			break;
		case ALLEGRO_KEY_ESCAPE:
			if(press == false)
				ok = false;
	}
	return;
 }
