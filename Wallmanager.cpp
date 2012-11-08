#include "Wallmanager.h"


Wallmanager::Wallmanager(void)
{
	x = 0;
	y = 0;
	z = 0;
	material = 3;
	list_ptr = glGenLists(1);
	glNewList(list_ptr, GL_COMPILE);
    glPushMatrix(); //dibuja el tope
		glutSolidCube(1);
    glPopMatrix();
	glEndList();
}


Wallmanager::~Wallmanager(void)
{
}
