#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#define DRAWABLES 25

class Allegro {
public:
	Allegro();
	~Allegro();
	ALLEGRO_DISPLAY* getDisplay();
	ALLEGRO_TIMER* getTimer();
	ALLEGRO_BITMAP* getDrawElement(int i);
	ALLEGRO_BITMAP* getBackground();
	ALLEGRO_EVENT* getEv();
	ALLEGRO_EVENT_QUEUE* getEvQueue();

	void setDisplay(ALLEGRO_DISPLAY*);
	void setTimer(ALLEGRO_TIMER*);
	void setDrawElement(ALLEGRO_BITMAP*, int i);
	void setBackground(ALLEGRO_BITMAP*);
	void setEv(ALLEGRO_EVENT*);
	void setEvQueue(ALLEGRO_EVENT_QUEUE*);

private:
	ALLEGRO_DISPLAY* display;
	ALLEGRO_TIMER* timer;
	ALLEGRO_BITMAP* drawList[DRAWABLES];
	ALLEGRO_BITMAP* background;
	ALLEGRO_EVENT* ev;
	ALLEGRO_EVENT_QUEUE* event_queue;
	
};