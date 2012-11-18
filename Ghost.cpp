#include "Ghost.h"
#include <stdio.h>
#include <iostream>

const int Ghost::mat = 3; 

Ghost::Ghost(void)
{
	x = 0;
	y = 0;
	z = 0;
	step = 1;
	dir = rand() % 4;
	move_prob = 5;
	change_prob = 10;
	mortal = 0;
	material = mat;
	moving = true;
	going_out = true;
	list_ptr = glGenLists(1);
	glNewList(list_ptr, GL_COMPILE);
    glPushMatrix(); //dibuja el tope
		glutSolidTorus(0.15, 0.3, 25,25);
    glPopMatrix();
	glEndList();
}


Ghost::~Ghost(void)
{
}

boolean Ghost::update(int x, int y, char gameboard[][28])
{
	if(mortal > 0){
		mortal--;
		if(mortal == 0) {
			material = my_material;
		}
	}
	if(going_out && moving && this->y > 11) {
		if(this->x < 13) {
			this->x += step;
		} else if (this->x > 14) {
			this->x -= step;
		} else {
			this->y -= step;
		}
	} else if (going_out && moving) {
		going_out = false;
	} else if(moving) {
		if(this->x == x && this->y == y) {
			if(mortal > 0) {
				die();
				return false;
			} else {
				return true;
			}
		}
		walk(x, y, gameboard);
		if(this->x == x && this->y == y) {
			if(mortal > 0) {
				die();
				return false;
			} else {
				return true;
			}
		}
	}
	return false;
}
void Ghost::walk(int x, int y, char gameboard[][28])
{
	if((rand() % 10) < move_prob) {
		if((rand() % 10) < change_prob) {
			dir = rand() % 4;
		}
		while (!goTo(dir, gameboard))
		{
			dir = rand() % 4;
		}
	}
}
boolean Ghost::goTo(int dir, char gameboard[][28])
{
	int x = 0;
	int y = 0;
	switch (dir)
	{
		case 0:
			x -= step;
			break;
		case 1:
			y -= step;
			break;
		case 2:
			x = step;
			break;
		case 3:
			y = step;
			break;
	}
	switch (gameboard[int(this->y+y)][int(this->x+x)])
	{
		case '0':
		case 'd':
		case 'u':
			this->y += y;
			this->x += x;
			return true;
		case '9':
			wrap();
		default:
			return false;
			break;
	}
}
void Ghost::wrap(void)
{
	setPoint(abs(x-27), y);
}

void Ghost::makeMortal(void)
{
	mortal = 40;
	material = 0;
}

void Ghost::die(void)
{
	mortal = 0;
	x = 13;
	y = 14;
	going_out = true;
	material = my_material;
}