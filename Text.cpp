#include "Text.h"
#include <iostream>

Text::Text(char* my_text)
{
	glNewList(list_ptr, GL_COMPILE);
        glRasterPos3d(0.0,5.0,0);
        int p=0;
        while (my_text[p]!='\0') {
			std::cout << my_text[p];
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, my_text[p]);
			p++;
        }
    glEndList();
}


Text::~Text(void)
{
}

void Text::draw(void)
{
	glPushMatrix();
		glCallList(list_ptr);
	glPopMatrix();
}