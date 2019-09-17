#include "allegro.h"
#include "worm.h"
#include <iostream>


Allegro::Allegro() {
	bool ok = true;
	display = NULL;
	timer = NULL;
	for (int i = 0; i < DRAWABLES; i++)
		drawList[i] = NULL;
	//background = NULL;
	ev = NULL;
	/*if (!initDisplay(display)) {
		printf("Can't init display!\n");
		ok = false;
	}*/
	display = al_create_display(SCREEN_W, SCREEN_H);
	if (display == NULL) {
		printf("Can't init display!\n");
		ok = false;
	}
		
	/*if (!initDrawables(drawList, background)) {
		printf("Can't init drawables!\n");
		ok = false;
	}*/
	drawList[0] = al_load_bitmap("wjump\\wjump-F1.png");
	drawList[1] = al_load_bitmap("wjump\\wjump-F2.png");
	drawList[2] = al_load_bitmap("wjump\\wjump-F3.png");
	drawList[3] = al_load_bitmap("wjump\\wjump-F4.png");
	drawList[4] = al_load_bitmap("wjump\\wjump-F5.png");
	drawList[5] = al_load_bitmap("wjump\\wjump-F6.png");
	drawList[6] = al_load_bitmap("wjump\\wjump-F7.png");
	drawList[7] = al_load_bitmap("wjump\\wjump-F8.png");
	drawList[8] = al_load_bitmap("wjump\\wjump-F9.png");
	drawList[9] = al_load_bitmap("wjump\\wjump-F10.png");

	drawList[10] = al_load_bitmap("wwalking\\wwalk-F1.png");
	drawList[11] = al_load_bitmap("wwalking\\wwalk-F2.png");
	drawList[12] = al_load_bitmap("wwalking\\wwalk-F3.png");
	drawList[13] = al_load_bitmap("wwalking\\wwalk-F4.png");
	drawList[14] = al_load_bitmap("wwalking\\wwalk-F5.png");
	drawList[15] = al_load_bitmap("wwalking\\wwalk-F6.png");
	drawList[16] = al_load_bitmap("wwalking\\wwalk-F7.png");
	drawList[17] = al_load_bitmap("wwalking\\wwalk-F8.png");
	drawList[18] = al_load_bitmap("wwalking\\wwalk-F9.png");
	drawList[19] = al_load_bitmap("wwalking\\wwalk-F10.png");
	drawList[20] = al_load_bitmap("wwalking\\wwalk-F11.png");
	drawList[21] = al_load_bitmap("wwalking\\wwalk-F12.png");
	drawList[22] = al_load_bitmap("wwalking\\wwalk-F13.png");
	drawList[23] = al_load_bitmap("wwalking\\wwalk-F14.png");
	drawList[24] = al_load_bitmap("wwalking\\wwalk-F15.png");

	background = al_load_bitmap("Scenario.png");
	if (background == NULL) {
		printf("Failed to load background!\n");
		ok = false;
	}
	for (int i = 0; i < DRAWABLES; i++) {
		if (drawList[i] == NULL) {
			printf("Failed to load picture!\n");
			ok = false;
		}
	}
	if (background == NULL) {
		printf("Error 8\n");
	}
	if (background == NULL) {
		printf("Error 5\n");
	}
	if (ok == false) {
		display = NULL;
		return;
	}

	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);
	//Registra fuentes de eventos relevantes
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_start_timer(timer);
}

Allegro::~Allegro() {
	for (int i = 0; i < DRAWABLES; i++) {
		if (drawList[i] != NULL)
			al_destroy_bitmap(drawList[i]);
	}
	if(background != NULL)
		al_destroy_bitmap(background);
	if (timer != NULL)
		al_destroy_timer(timer);
	if (display != NULL)
		al_destroy_display(display);
	if (event_queue != NULL)
		al_destroy_event_queue(event_queue);

	return;
}

ALLEGRO_TIMER* Allegro::getTimer() {
	return timer;
}

ALLEGRO_DISPLAY* Allegro::getDisplay() {
	return display;
}

ALLEGRO_BITMAP* Allegro::getDrawElement(int i) {
	return drawList[i];
}
ALLEGRO_BITMAP* Allegro::getBackground() {
	return background;
}

ALLEGRO_EVENT* Allegro::getEv() {
	return ev;
}
ALLEGRO_EVENT_QUEUE* Allegro::getEvQueue() {
	return event_queue;
}

void Allegro::setDisplay(ALLEGRO_DISPLAY* _display) {
	display = _display;
}
void Allegro::setTimer(ALLEGRO_TIMER* _timer) {
	timer = _timer;
}
void Allegro::setDrawElement(ALLEGRO_BITMAP* _element, int i) {
	drawList[i] = _element;
}
void Allegro::setBackground(ALLEGRO_BITMAP* back) {
	background = back;
}
void Allegro::setEv(ALLEGRO_EVENT* _ev) {
	ev = _ev;
}
void Allegro::setEvQueue(ALLEGRO_EVENT_QUEUE* _eventQueue) {
	event_queue = _eventQueue;
}

bool Allegro::initDrawables(ALLEGRO_BITMAP* drawList[DRAWABLES], ALLEGRO_BITMAP* background) {
	bool r = true;
	//cargo todas las imagenes

	drawList[0] = al_load_bitmap("wjump\\wjump-F1.png");
	drawList[1] = al_load_bitmap("wjump\\wjump-F2.png");
	drawList[2] = al_load_bitmap("wjump\\wjump-F3.png");
	drawList[3] = al_load_bitmap("wjump\\wjump-F4.png");
	drawList[4] = al_load_bitmap("wjump\\wjump-F5.png");
	drawList[5] = al_load_bitmap("wjump\\wjump-F6.png");
	drawList[6] = al_load_bitmap("wjump\\wjump-F7.png");
	drawList[7] = al_load_bitmap("wjump\\wjump-F8.png");
	drawList[8] = al_load_bitmap("wjump\\wjump-F9.png");
	drawList[9] = al_load_bitmap("wjump\\wjump-F10.png");

	drawList[10] = al_load_bitmap("wwalking\\wwalk-F1.png");
	drawList[11] = al_load_bitmap("wwalking\\wwalk-F2.png");
	drawList[12] = al_load_bitmap("wwalking\\wwalk-F3.png");
	drawList[13] = al_load_bitmap("wwalking\\wwalk-F4.png");
	drawList[14] = al_load_bitmap("wwalking\\wwalk-F5.png");
	drawList[15] = al_load_bitmap("wwalking\\wwalk-F6.png");
	drawList[16] = al_load_bitmap("wwalking\\wwalk-F7.png");
	drawList[17] = al_load_bitmap("wwalking\\wwalk-F8.png");
	drawList[18] = al_load_bitmap("wwalking\\wwalk-F9.png");
	drawList[19] = al_load_bitmap("wwalking\\wwalk-F10.png");
	drawList[20] = al_load_bitmap("wwalking\\wwalk-F11.png");
	drawList[21] = al_load_bitmap("wwalking\\wwalk-F12.png");
	drawList[22] = al_load_bitmap("wwalking\\wwalk-F13.png");
	drawList[23] = al_load_bitmap("wwalking\\wwalk-F14.png");
	drawList[24] = al_load_bitmap("wwalking\\wwalk-F15.png");

	background = al_load_bitmap("Scenario.png");
	if (background == NULL) {
		printf("Failed to load background!\n");
		r = false;
	}
	for (int i = 0; i < DRAWABLES; i++) {
		if (drawList[i] == NULL) {
			printf("Failed to load picture!\n");
			r = false;
		}
	}
	if (background == NULL) {
		printf("Error 8\n");
	}
	return r;
}

bool Allegro::initDisplay(ALLEGRO_DISPLAY* display) {
	bool ret = true;
	display = al_create_display(SCREEN_W, SCREEN_H);
	if (display == NULL)
		ret = false;
	return ret;
}