#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>

//bool initEvGen(Allegro* front);

bool draw() {
	bool ok = false;

	return ok;
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

/*bool initDrawables(Allegro* front) {
	bool r = true;
	//cargo todas las imagenes

	front->setDrawElement(al_load_bitmap("wjump\\wjump-F1.png"), JUMP1);
	front->setDrawElement(al_load_bitmap("wjump\\wjump-F2.png"), JUMP2);
	front->setDrawElement(al_load_bitmap("wjump\\wjump-F3.png"), JUMP3);
	front->setDrawElement(al_load_bitmap("wjump\\wjump-F4.png"), JUMP4);
	front->setDrawElement(al_load_bitmap("wjump\\wjump-F5.png"), JUMP5);
	front->setDrawElement(al_load_bitmap("wjump\\wjump-F6.png"), JUMP6);
	front->setDrawElement(al_load_bitmap("wjump\\wjump-F7.png"), JUMP7);
	front->setDrawElement(al_load_bitmap("wjump\\wjump-F8.png"), JUMP8);
	front->setDrawElement(al_load_bitmap("wjump\\wjump-F9.png"), JUMP9);
	front->setDrawElement(al_load_bitmap("wjump\\wjump-F10.png"), JUMP10);

	front->setDrawElement(al_load_bitmap("wwalking\\wwalk-F1.png"), WALK1);
	front->setDrawElement(al_load_bitmap("wwalking\\wwalk-F2.png"), WALK2);
	front->setDrawElement(al_load_bitmap("wwalking\\wwalk-F3.png"), WALK3);
	front->setDrawElement(al_load_bitmap("wwalking\\wwalk-F4.png"), WALK4);
	front->setDrawElement(al_load_bitmap("wwalking\\wwalk-F5.png"), WALK5);
	front->setDrawElement(al_load_bitmap("wwalking\\wwalk-F6.png"), WALK6);
	front->setDrawElement(al_load_bitmap("wwalking\\wwalk-F7.png"), WALK7);
	front->setDrawElement(al_load_bitmap("wwalking\\wwalk-F8.png"), WALK8);
	front->setDrawElement(al_load_bitmap("wwalking\\wwalk-F9.png"), WALK9);
	front->setDrawElement(al_load_bitmap("wwalking\\wwalk-F10.png"), WALK10);
	front->setDrawElement(al_load_bitmap("wwalking\\wwalk-F11.png"), WALK11);
	front->setDrawElement(al_load_bitmap("wwalking\\wwalk-F12.png"), WALK12);
	front->setDrawElement(al_load_bitmap("wwalking\\wwalk-F13.png"), WALK13);
	front->setDrawElement(al_load_bitmap("wwalking\\wwalk-F14.png"), WALK14);
	front->setDrawElement(al_load_bitmap("wwalking\\wwalk-F15.png"), WALK15);
	front->setBackground(al_load_bitmap("Scenario.png"));
	if (front->getBackground() == NULL) {
		printf("Failed to load background!\n");
		r = false;
	}
	for (int i = 0; i < DRAWABLES; i++) {
		if (front->getDrawElement(i) == NULL) {
			printf("Failed to load picture!\n");
			r = false;
		}
	}
	return r;
}

bool initDisplay(Allegro& front) {
	bool ret = true;
	front.setDisplay(al_create_display(SCREEN_W, SCREEN_H));
	if (front.getDisplay() == NULL)
		ret = false;
	return ret;
}*/
bool initEvGen(Allegro* front){
	bool ret = true;
	front->setTimer(al_create_timer(1.0 / FPS));
	front->setEvQueue(al_create_event_queue());
	if (front->getTimer() == NULL || front->getEvQueue() == NULL)
		ret = false;
	return ret;
}