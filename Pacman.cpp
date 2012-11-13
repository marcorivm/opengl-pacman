#include "Pacman.h"


Pacman::Pacman(void)
{
	x = 0;
	y = 0;
	z = 0;
	material = 23;
	ang = 0;
	inc_ang = -5;
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
	glPushMatrix();
       glShadeModel (GL_SMOOTH);
       glTranslatef(x, y, 0.0);
       glRotatef(45+ang, 0.0, 0.0, 1.0);
       glCallList(list_ptr);
    glPopMatrix();
    glPushMatrix();
        glShadeModel (GL_SMOOTH);
        glTranslatef(x, y, 0.0);
        glRotatef(45-ang, 0.0, 0.0, 1.0);
        glCallList(list_ptr);
    glPopMatrix();
}
void Pacman::update(void)
{
	if(ang >= 45 || ang <= 0) {
        inc_ang = inc_ang * -1;
    }
    ang += inc_ang;
}
/*
    glPushMatrix();
       glShadeModel (GL_SMOOTH);
       glTranslatef(x, y, 0.0);
       glRotatef(45+ang, 0.0, 0.0, 1.0);
       glCallList(startList);
    glPopMatrix();
    glPushMatrix();
        glShadeModel (GL_SMOOTH);
        glTranslatef(x, y, 0.0);
        glRotatef(45-ang, 0.0, 0.0, 1.0);
        glCallList(startList);
    glPopMatrix();
*/