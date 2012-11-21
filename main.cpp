#include "glut_headers.h"
#include <iostream>
#include "Game.h"
#include "Text.h"
#include "Pantalla.h"
#include <mmsystem.h>

float mat_ambient_diffuse [] = {0.0,0.0,0.0,1.0};
float mat_specular [] = {0.0,0.0,0.0,1.0};
float mat_emission [] = {0.0,0.0,0.0,1.0};
float mat_shininess = 0.4;
float focus_emission [] = {0.0,0.0,0.0,1.0};
float light_ambient [] = {0.0,0.2,0.0,1.0};
float light_diffuse_specular [] = {0.6,0.2,0.067,0.0};
float light_pos [] = {0.0,0.0,2.0,1.0};
float spot_dir [] = {0.0,0.0,-1.0};
float spot_cutoff = 50.0;
float spot_exponent = 5.0;
int rot_x[2] = {300,1.0}; //rot_x
int rot_y[2] = {0,0}; //rot_y
int rot_z[2] = {0,0}; //rot_z
int width = 1000;
int height = 800;
boolean start_screen = true;
int timer = 0;
Game* game;
Game* game2;
Pantalla* inicio;

void reshape(int x, int y)
{
	width = x;
	height = y;
    glViewport(0, 0, width, height);
	game->setDimensions(width/2, height);
	game2->setDimensions(width/2, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.5,28.5, 31.5, -1.5, -512, 512);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;

}

void menu(int option)
{
	switch (option)
	{
	case 1:
	if(!game->hasEnded()) {
		game->pause();
		game2->pause();
	}
	break;
	case 2:
	game2 = new Game();
	game = new Game();
	break;
	case 0:
	exit(0);
	break;
	}
}
void init()
{
    glEnable(GL_DEPTH_TEST);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE,GL_FALSE);
    glEnable(GL_LIGHTING);
	GLfloat globalAmbient[ ] = { 1.00, 1.00, 1.00, 0.0 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbient);
    glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE, mat_ambient_diffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
    glMaterialf(GL_FRONT,GL_SHININESS,mat_shininess);

    glClearColor(0.0,0.0,0.0,0.0);

	glutCreateMenu(menu);
    glutAddMenuEntry("pause/unpause (p)", 1);
    glutAddMenuEntry("restart game (r)", 2);
    glutAddMenuEntry("quit", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void initObjects()
{
	game = new Game();
	game->setKeys(1000+97, 1000+119, 1000+100, 1000+115);
	game2 = new Game();
	game2->setKeys(100, 101, 102,103);
	inicio = new Pantalla();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if(start_screen) {
		reshape(width, height);
		inicio->draw();
	} else if(game->isPlaying() && !game->hasEnded()) {
		glPushMatrix();
			game->setPoint(0, 0);
			game->draw();
		glPopMatrix();
		glPushMatrix();
			game2->setPoint(width/2, 0);
			game2->draw();
		glPopMatrix();
	} else if(!game->isPlaying()) {
		reshape(width, height);
		Text::drawText("Juego en pausa, presione \"p\" para resumir o \"r\" para reiniciar");
	} else if(game->hasEnded()) {
		reshape(width, height);
		glPushMatrix();
		Text::drawText("Fin del juego, presione \"r\" para reiniciar");
		glTranslatef(0, 1, 0);
		Text::drawText("Terminaste con una puntuacion de:");
		glTranslatef(0, 1, 0);
		Text::drawInt(game->score);
		glTranslatef(0, 1, 0);
		Text::drawText("Lograste alcanzar el nivel:");
		glTranslatef(0, 1, 0);
		Text::drawInt(game->level);
		glPopMatrix();
	}
    glutSwapBuffers();
}


void special(int key, int x, int y){
	if(key == 1114) 
	{
		initObjects();
		reshape(width, height);
	} else if(key == 1105) {
		game->playSound();
		start_screen = false;
	}
	game->keyListener(key, x, y);
	game2->keyListener(key, x, y);
    glutPostRedisplay();
}
void key(unsigned char key, int x, int y)
{
    // Lets try all keys as equals
    // +1000 normal keys.
    special(key+1000, x, y);
}
static void idle(void)
{
    glutPostRedisplay();
}

void myTimer(int valor)
{
	if(game->isPlaying() && !game->hasEnded()) {
		game->update();
		game2->update();
		valor = game->speed;
	}
    glutPostRedisplay();
    glutTimerFunc(valor,myTimer,valor);
}



int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(width,height);	
    glutInitWindowPosition(100,50);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Pacman");
	initObjects();
    init();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutSpecialFunc(special);
    glutIdleFunc(idle);
    glutTimerFunc(350,myTimer,350);
	
	glutMainLoop();

    return EXIT_SUCCESS;
}