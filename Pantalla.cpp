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
		Text::drawText("Marco Rivadeneyra Morales");
		glTranslatef(0, 1, 0);
		Text::drawText("A01099497");
		glTranslatef(0, 1, 0);
		Text::drawText("Presiona \"i\" para iniciar");
    glPopMatrix();
	glEndList();

	PlaySound((LPCSTR) "pacman_beginning.wav", NULL, SND_FILENAME | SND_ASYNC);
}


Pantalla::~Pantalla(void)
{
}