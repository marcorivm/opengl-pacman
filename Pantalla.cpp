#include "Pantalla.h"
#include <mmsystem.h>


Pantalla::Pantalla(void)
{
	material = 1;
	x = 0;
	y = 0;
	z = 0;
	list_ptr = glGenLists(1);
	glNewList(list_ptr, GL_COMPILE);
	glPushMatrix();
		Text::drawText("Pacman!");
		glTranslatef(0, 1, 0);
		Text::drawText("Marco Rivadeneyra Morales\n A01099497");
    glPopMatrix();
	glEndList();

	PlaySound((LPCSTR) "pacman_beginning.wav", NULL, SND_FILENAME | SND_ASYNC);
}


Pantalla::~Pantalla(void)
{
}