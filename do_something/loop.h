#pragma once
#include "object.h"
#include <iostream>
#include <windows.h>

void gotoxy(int x, int y);
void set_gravity(object* obj);
void set_box_collision(object* obj);
void renderer(object* obj);
void main_loop();