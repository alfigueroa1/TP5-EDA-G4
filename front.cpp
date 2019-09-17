#include <iostream>
#include "allegro.h"
#include "worm.h"
#include "front.h"

void draw(Allegro& front, Worm& worm1, Worm& worm2) {
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_bitmap(front.getBackground(), 0,0,0);
	if (worm1.getSprite() < 0 || worm1.getSprite() >= DRAWABLES)
		printf("Culpa de worm1\n");
	else {
		if (worm1.getLookingRight() == true)
			al_draw_bitmap(front.getDrawElement(worm1.getSprite()), worm1.getX(), worm1.getY(), ALLEGRO_FLIP_HORIZONTAL);
		else
			al_draw_bitmap(front.getDrawElement(worm1.getSprite()), worm1.getX(), worm1.getY(), 0);
	}
	if (worm2.getSprite() < 0 || worm2.getSprite() >= DRAWABLES)
		printf("Culpa de worm2\n");
	else {
		if (worm2.getLookingRight() == true)
			al_draw_bitmap(front.getDrawElement(worm2.getSprite()), worm2.getX(), worm2.getY(), ALLEGRO_FLIP_HORIZONTAL);
		else
			al_draw_bitmap(front.getDrawElement(worm2.getSprite()), worm2.getX(), worm2.getY(), 0);
	}
	al_flip_display();
	return;
}

bool initFrontend() {
	bool ret = 0;
	if (!al_init())
		printf("Failed to initialize Allegro\n");
	else if (!al_init_image_addon())
		printf("Failed to initialize Image Addon\n");
	else if (!al_install_keyboard())
		printf("Failed to initialize Keyboard Addon\n");
	else if (!al_init_primitives_addon())
		printf("Failed to initialize primitives Addon!\n");
	else if (!al_init_font_addon())
		printf("Failed to initialize Font Addon\n");
	else if (!al_init_ttf_addon())
		printf("Failed to initialize TTF Addon\n");
	else
		ret = 1;
	return ret;
}