#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "keyboard.h"

int frontend() {
	bool ok = false;


	if (!initFrontend())
		return ok;


	return ok;
}

int initFrontend() {
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

