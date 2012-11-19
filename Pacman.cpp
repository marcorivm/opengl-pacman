#include "Pacman.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>

Pacman::Pacman(void)
{
	lives = 3;
	dir = 0;
	x = 0;
	y = 0;
	z = 0;
	step = 1.00;
	material = 6;
	ang = 0;
	inc_ang = -1;
	list_ptr = glGenLists(1);
	GLUquadricObj *qobj = gluNewQuadric();   
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricNormals(qobj, GLU_NONE);
	glNewList(list_ptr, GL_COMPILE);
    glPushMatrix(); //dibuja el tope
      gluPartialDisk(qobj, 0.0, 0.5, 20, 4, 0.0, 270.0);
    glPopMatrix();
	glEndList();
}

Pacman::~Pacman(void)
{
}

void Pacman::draw(void)
{
	if(ang >= 45 || ang <= 0) {
        inc_ang = inc_ang * -1;
    }
    ang += inc_ang;
	setMaterial(material);
	glPushMatrix();
       glShadeModel (GL_SMOOTH);
	   glTranslatef(x, y, 0);
	   glRotatef(dir*90, 0.0, 0.0, 1.0);
       glRotatef(45+ang, 0.0, 0.0, 1.0);
       glCallList(list_ptr);
    glPopMatrix();
    glPushMatrix();
        glShadeModel (GL_SMOOTH);
	    glTranslatef(x, y, 0);
		glRotatef(dir*90, 0.0, 0.0, 1.0);
        glRotatef(45-ang, 0.0, 0.0, 1.0);
        glCallList(list_ptr);
    glPopMatrix();
}

int Pacman::update(char gameboard[][28])
{
	int new_x = getNextX();
	int new_y = getNextY();
	boolean move = true;
	switch(gameboard[new_y][new_x]) {
		case 'd':
		case 'u':
		case '0':
			break;
		case '9':
			wrap();
			break;
		case 'a':
		case 'c':
		case 'f':
		case 's':
			//die();
			// :(
		default:
			move = false;
			break;
	}
	if(move) {
		incrementX();
		incrementY();
	}
	return gameboard[int(y)][int(x)];
}

void Pacman::die(void)
{
	lives--;
	setPoint(13,23);
	dir = 0;
}
boolean Pacman::isDead(void)
{
	return (lives < 0);
}
void Pacman::wrap(void)
{
	setPoint(abs(x-27), y);
}

void Pacman::incrementX(void)
{
	if (dir == 2) {
		x = x + step;
	} else if(dir == 0) {
		x = x - step;
	}
}

void Pacman::incrementY(void)
{
	if (dir == 3) {
		y = y + step;
	} else if(dir == 1) {
		y = y - step;
	}
}

int Pacman::getX(void)
{
	if(dir == 0) {
		return ceil(x);
	} else {
		return floor(x);
	}
}

int Pacman::getY(void)
{
	if(dir == 1) {
		return ceil(y);
	} else {
		return floor(y);
	}
}

int Pacman::getNextY(void)
{
	if (dir == 3) {
		return ceil(y + step);
	} else if(dir == 1) {
		return floor(y - step);
	}
	return y;
}
int Pacman::getNextX(void)
{
	if (dir == 2) {
		return ceil(x + step);
	} else if(dir == 0) {
		return floor(x - step);
	}
	return x;
}

void Pacman::keyListener(int key, int x, int y)
{
	switch (key)
	{
		case 100:
			dir = 0;
			break;
		case 101:
			dir = 1;
			break;
		case 102:
			dir = 2;
			break;
		case 103:
			dir = 3;
			break;
	}
}