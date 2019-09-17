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
#include "keyboard.h"
#include "wormFSM.h"

int main(void) {
	Worm worm1(500, 500);
	Worm worm2(700, 700);
	Allegro front;
	ALLEGRO_EVENT_QUEUE* event_queue;
	ALLEGRO_EVENT ev;
	TrueEvent trueEv;

	bool ok = true, redraw = false, once = true;
	bool keyPressed[KEYS] = { false, false, false, false, false, false};
	if (!initFrontend() || !initDrawables(front) || !initDisplay(front) || !initEvGen(front))
		return 0;
	if (front.getDisplay() == NULL) {
		printf("ERROR 2\n");
		return 0;
	}
	if (front.getEvQueue() == NULL) {
		printf("ERROR 1\n");
		return 0;
	}
	al_register_event_source(front.getEvQueue(), al_get_display_event_source(front.getDisplay()));
	al_register_event_source(front.getEvQueue(), al_get_keyboard_event_source());
	al_register_event_source(front.getEvQueue(), al_get_timer_event_source(front.getTimer()));
	al_start_timer(front.getTimer());

	event_queue = front.getEvQueue();

	while (ok)
	{
		trueEv = getNextEv(front.getEv(), front.getEvQueue, trueEv, ok);
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
	TrueEvent aux;
	al_get_next_event(evQueue, ev);
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
	return trueEv;
}

void eventDispatcher(TrueEvent ev, Allegro& front, Worm& worm1, Worm& worm2) {
	switch (ev) {
	case UPPRESS:
		worm1.jump();	break;
	case UPUNPRESS:
		worm1.stopJumping();	break;
	case LPRESS:
		worm1;
	}
	return;
}