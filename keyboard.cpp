/*******************************************************************************
							 INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include "keyboard.h"
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


void handleKeyPress(ALLEGRO_EVENT &ev, bool keyPressed[KEYS], bool down, bool &ok) {
	bool press;
	if (down)
		press = true;
	else
		press = false;
	switch (ev.keyboard.keycode) {
		case ALLEGRO_KEY_UP:
			keyPressed[KEY_UP] = press;		break;
		case ALLEGRO_KEY_LEFT:
			keyPressed[KEY_LEFT] = press;	break;
		case ALLEGRO_KEY_RIGHT:
			keyPressed[KEY_RIGHT] = press;	break;
		case ALLEGRO_KEY_W:
			keyPressed[KEY_W] = press;		break;
		case ALLEGRO_KEY_D:
			keyPressed[KEY_D] = press;		break;
		case ALLEGRO_KEY_A:
			keyPressed[KEY_A] = press;		break;
		case ALLEGRO_KEY_ESCAPE:
			if(press == false)
				ok = false;
	}
	return;
 }
