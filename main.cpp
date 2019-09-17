/*******************************************************************************
							 INCLUDE HEADER FILES
 ******************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "types.h"
#include "worm.h"
#include "allegro.h"
#include "front.h"
#include "trueEv.h"
#include "keyboard.h"
#include "wormFSM.h"

TrueEvent getNextEv(ALLEGRO_EVENT* ev, ALLEGRO_EVENT_QUEUE* evQueue, TrueEvent trueEv, bool& ok);
void eventDispatcher(TrueEvent ev, Allegro& front, Worm& worm1, Worm& worm2);


int main(void) {
	if (!initFrontend())
		return 0;
	Worm worm1(701, 616);
	Worm worm2(1100, 616);
	Allegro front;
	ALLEGRO_EVENT_QUEUE* event_queue;
	ALLEGRO_EVENT ev;
	TrueEvent trueEv = NOEV;
	if (front.getDisplay() == NULL) {
		return 0;
	}
	bool ok = true, redraw = false, once = true;
	if (front.getDisplay() == NULL) {
		printf("ERROR 2\n");
		return 0;
	}
	if (front.getBackground() == NULL) {
		return 0;
	}
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_bitmap(front.getBackground(), 0, 0, 0);
	al_flip_display();
	while (ok)
	{
		trueEv = getNextEv(&ev, front.getEvQueue(), trueEv, ok);
		if(trueEv != NOEV)
			eventDispatcher(trueEv, front, worm1, worm2);
	}

	return 0;

	//Worm test
	/*
	Worm* w = new Worm(800, 616);
	w->print();
	w->walkRight();
	w->print();
	w->walkLeft();
	w->print();
	return 0;
	*/
}


TrueEvent getNextEv(ALLEGRO_EVENT *ev , ALLEGRO_EVENT_QUEUE* evQueue, TrueEvent trueEv, bool& ok) {
	TrueEvent aux = NOEV;
	if (al_get_next_event(evQueue, ev))
	{
		if (ev->type == ALLEGRO_EVENT_TIMER)
			aux = TIMERUP;
		else if (ev->type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			ok = false;
		else if (ev->type == ALLEGRO_EVENT_KEY_DOWN)
			handleKeyPress(ev, aux, true, ok);
		else if (ev->type == ALLEGRO_EVENT_KEY_UP)
			handleKeyPress(ev, aux, false, ok);
		else
			aux = NOEV;
	}
	return aux;
}

void eventDispatcher(TrueEvent ev, Allegro& front, Worm& worm1, Worm& worm2) {
	switch (ev) {
	case UPPRESS:
		worm1.jump();	break;
	case UPUNPRESS:
		worm1.noJump();	break;
	case LPRESS:
		worm1.walkLeft();	break;
	case LUNPRESS: case RUNPRESS:
		worm1.stopWalking();	break;
	case RPRESS:
		worm1.walkRight();		break;
	case WPRESS:
		worm2.jump();	break;
	case WUNPRESS:
		worm2.noJump();	break;
	case APRESS:
		worm2.walkLeft();	break;
	case AUNPRESS: case DUNPRESS:
		worm2.stopWalking();	break;
	case DPRESS:
		worm2.walkRight();	break;
	case TIMERUP:
		worm1.stateHand();
		worm2.stateHand();
		draw(front, worm1, worm2);
		break;
	//default: draw(front, worm1, worm2); break;
	}
	
	return;
}