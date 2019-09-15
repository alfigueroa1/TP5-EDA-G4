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

int main(void) {
	Worm worm1(500, 500);
	Worm worm2(700, 700);
	Allegro front;
	ALLEGRO_EVENT_QUEUE* event_queue;
	ALLEGRO_EVENT ev;
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
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
			//poner las consecuencias del teclado
			handleKeyInputs(keyPressed);
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			ok = false;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			handleKeyPress(ev, keyPressed, true, ok);
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			handleKeyPress(ev, keyPressed, false, ok);
		}
		if (redraw && al_is_event_queue_empty(event_queue) && once) {
			redraw = false;

			/****** Dibujar en pantalla acá ******/

			draw(front, worm1, worm2);
			
			al_flip_display();																//se grafica la pantalla
		}
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