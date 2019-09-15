#include "allegro.h"


Allegro::Allegro() {
	display = NULL;
	timer = NULL;
	for (int i = 0; i < DRAWABLES; i++)
		drawList[i] = NULL;
	background = NULL;
	event_queue = NULL;
	ev = NULL;
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