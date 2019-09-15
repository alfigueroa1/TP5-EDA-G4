#pragma once

#include "allegro.h"

#define SCREEN_H 696
#define SCREEN_W 1920
#define FPS	50.0

bool draw(Allegro& front, Worm& worm1, Worm& worm2);
bool initFrontend();
bool initEvGen(Allegro& front);
bool initDisplay(Allegro& front);
bool initDrawables(Allegro& front);