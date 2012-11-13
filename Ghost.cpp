#include "Ghost.h"


Ghost::Ghost(void)
{
	x = 0;
	y = 0;
	z = 0;
	material = 7;
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
