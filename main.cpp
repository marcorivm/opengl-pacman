#include "glut_headers.h"
#include <iostream>
#include "Game.h"

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
Game* game;

void init()
{
    glEnable(GL_DEPTH_TEST);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE,GL_FALSE);
    glEnable(GL_LIGHTING);
	GLfloat globalAmbient[ ] = { 0.70, .70, .70, 0.0 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbient);
    glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE, mat_ambient_diffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
    glMaterialf(GL_FRONT,GL_SHININESS,mat_shininess);

    glClearColor(0.0,0.0,0.0,0.0);
}
void initObjects()
{
	game = new Game();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	game->draw();
    glutSwapBuffers();
}


void reshape(int x, int y)
{
    glViewport(0, 0, x, y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.5,28.5, 31.5, -1.5, -512, 512);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;

}

void special(int key, int x, int y){
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
    // Let's not be idle
}

void myTimer(int valor)
{
	game->update();
    glutPostRedisplay();
    glutTimerFunc(350,myTimer,valor);


}



int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1000,1000);	
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
    glutTimerFunc(350,myTimer,0);



    glutMainLoop();

    return EXIT_SUCCESS;
}