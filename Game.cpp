#include "Game.h"
#include <stdio.h>
#include <iostream>
#include <mmsystem.h>

const char Game::initial_gameboard[31][28] = {{'1','2','2','2','2','2','2','2','2','2','2','2','2','3','1','2','2','2','2','2','2','2','2','2','2','2','2','3'},
											{'8','d','d','d','d','d','d','d','d','d','d','d','d','4','8','d','d','d','d','d','d','d','d','d','d','d','d','4'},
											{'8','d','1','2','2','3','d','1','2','2','2','3','d','8','4','d','1','2','2','2','3','d','1','2','2','3','d','4'},
											{'8','u','8','0','0','4','d','8','0','0','0','4','d','8','4','d','8','0','0','0','4','d','8','0','0','4','u','4'},
											{'8','d','7','6','6','5','d','7','6','6','6','5','d','7','5','d','7','6','6','6','5','d','7','6','6','5','d','4'},
											{'8','d','d','d','d','d','d','d','d','d','d','d','d','d','d','d','d','d','d','d','d','d','d','d','d','d','d','4'},
											{'8','d','1','2','2','3','d','1','3','d','1','2','2','2','2','2','2','3','d','3','1','d','1','2','2','3','d','4'},
											{'8','d','7','6','6','5','d','8','4','d','7','6','6','3','1','6','6','5','d','4','8','d','7','6','6','5','d','4'},
											{'8','d','d','d','d','d','d','8','4','d','d','d','d','8','4','d','d','d','d','4','8','d','d','d','d','d','d','4'},
											{'7','2','2','2','2','3','d','8','7','2','2','3','0','8','4','0','1','2','2','5','8','d','7','2','2','2','2','5'},
											{'0','0','0','0','0','4','d','8','1','6','6','5','0','7','5','0','7','6','6','3','8','d','8','0','0','0','0','0'},
											{'0','0','0','0','0','4','d','8','4','0','0','0','0','0','0','0','0','0','0','4','8','d','8','0','0','0','0','0'},
											{'0','0','0','0','0','4','d','8','4','0','1','2','2','-','-','2','2','3','0','4','8','d','8','0','0','0','0','0'},
											{'6','6','6','6','6','5','d','7','5','0','8','0','0','0','0','0','0','4','0','5','7','d','7','6','6','6','6','6'},
											{'9','0','0','0','0','0','d','0','0','0','8','0','0','0','0','0','0','4','0','0','0','d','0','0','0','0','0','9'},
											{'2','2','2','2','2','3','d','1','3','0','8','0','0','0','0','0','0','4','0','1','3','d','1','2','2','2','2','2'},
											{'0','0','0','0','0','4','d','8','4','0','7','6','6','6','6','6','6','5','0','8','4','d','8','0','0','0','0','0'},
											{'0','0','0','0','0','4','d','8','4','0','0','0','0','0','0','0','0','0','0','8','4','d','8','0','0','0','0','0'},
											{'0','0','0','0','0','4','d','8','4','0','1','2','2','2','2','2','2','3','0','8','4','d','8','0','0','0','0','0'},
											{'1','6','6','6','6','5','d','7','5','0','7','6','6','3','1','6','6','5','0','7','5','d','7','6','6','6','6','3'},
											{'8','d','d','d','d','d','d','d','d','d','d','d','d','8','4','d','d','d','d','d','d','d','d','d','d','d','d','4'},
											{'8','d','1','2','2','3','d','1','2','2','2','3','d','8','4','d','1','2','2','2','3','d','1','2','2','3','d','4'},
											{'8','d','7','6','3','4','d','7','6','6','6','5','d','7','5','d','7','6','6','6','5','d','8','1','6','5','d','4'},
											{'8','u','d','d','8','4','d','d','d','d','d','d','d','0','0','d','d','d','d','d','d','d','8','4','d','d','u','4'},
											{'7','2','3','d','8','4','d','1','3','d','1','2','2','2','2','2','2','3','d','1','3','d','8','4','d','1','6','5'},
											{'1','6','5','d','7','5','d','8','4','d','7','6','6','3','1','6','6','5','d','8','4','d','7','5','d','7','2','3'},
											{'8','d','d','d','d','d','d','8','4','d','d','d','d','8','4','d','d','d','d','8','4','d','d','d','d','d','d','4'},
											{'8','d','1','2','2','2','2','5','7','2','2','3','d','8','4','d','1','2','2','2','2','5','7','2','2','3','d','4'},
											{'8','d','7','6','6','6','6','6','6','6','6','5','d','7','5','d','7','6','6','6','6','6','6','6','6','5','d','4'},
											{'8','d','d','d','d','d','d','d','d','d','d','d','d','d','d','d','d','d','d','d','d','d','d','d','d','d','d','4'},
											{'7','6','6','6','6','6','6','6','6','6','6','6','6','6','6','6','6','6','6','6','6','6','6','6','6','6','6','5'}};

Game::Game(void)
{
	wallmanager = new Wallmanager();
	dot = new Dot();
	powerup = new Powerup();
	pacman = new Pacman();
	ambusher = new Ambusher();
	chaser = new Chaser();
	fickle = new Fickle();
	stupid = new Stupid();
	speed = 200;
	level = 1;
	score = 0;
	paused = false;
	initHeaders();
	newLevel();
}
void Game::playSound(void)
{
	PlaySound((LPCSTR) "pacman_chomp.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}
void Game::initHeaders(void)
{
	lives_header = new Text("Vidas:");
	author_header = new Text("Marco Rivadeneyra Morales\na01099497");
	level_header = new Text("Nivel:");
	score_header = new Text("Puntuacion:");
}

Game::~Game(void)
{
}
void Game::setPoint(int x, int y)
{
	this->x = x;
	this->y = y;
}
void Game::draw(void)
{
	glViewport(x,y, width * 0.7, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.5,28.5, 31.5, -1.5, -512, 512);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity() ;

	for (int i = 0; i < 31; i++)
	{
		for (int j = 0; j < 28; j++)
		{
			
			glPushMatrix();
				glTranslatef(j,i,0);
				switch (gameboard[i][j])
				{
				case 'd':
					dot->draw();
					break;
				case 'u':
					powerup->draw();
					break;
				case '0':
				case '9':
					 break;
				default:
					wallmanager->draw(gameboard[i][j]);
					break;
				}
			glPopMatrix();
		}
	}
	pacman->draw();
	ambusher->draw();
	chaser->draw();
	fickle->draw();
	stupid->draw();

	glViewport(width * 0.7 + x, 0 + y, width * 0.3, height);	
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-150,150, 500, -500, -512, 512);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
	
	glPushMatrix();
		glTranslatef(-50, -500, 0);
		drawScore();
		drawLives();
		drawLevel();
		//drawAuthor();
	glPopMatrix();
}
void Game::setKeys(int l, int t, int r, int b) {
	pacman->setKeys(l,t,r,b);
}
void Game::drawLevel()
{
	MyDrawable::newMaterial(1,0,1,0);
	glTranslatef(0, 150, 0);
	level_header->draw();
	glPushMatrix();
	glTranslatef(50, 30, 0);
	Text::drawInt(level);
	glPopMatrix();
}
void Game::drawLives()
{
	MyDrawable::newMaterial(1,1,1,0);
	glTranslatef(0, 150, 0);
	lives_header->draw();
	glPushMatrix();
	glTranslatef(50, 30, 0);
	Text::drawInt(pacman->lives);
	glPopMatrix();
}
void Game::drawScore()
{
	MyDrawable::newMaterial(1,1,0,0);
	glTranslatef(0, 150, 0);
	score_header->draw();
	glPushMatrix();
	glTranslatef(50, 30, 0);
	Text::drawInt(score);
	glPopMatrix();
}
void Game::drawAuthor()
{
	MyDrawable::newMaterial(1,1,1,1);
	glTranslatef(-100, 150, 0);
	author_header->draw();
}
void Game::superPacman(void)
{
	switch (level)
	{
		case 4:
			ambusher->makeMortal();
		case 3:
			chaser->makeMortal();
		case 2:
			fickle->makeMortal();
		case 1:
			stupid->makeMortal();
	}
}
void Game::update(void)
{
	if(dots > 0) {
		pacman->update(gameboard);
		int x = pacman->getX();
		int y = pacman->getY();
		switch (gameboard[y][x]) {
			case 'u':
				superPacman();
				score++;
			case 'd':
				score++;
				dots--;
				gameboard[y][x] = '0';
				break;
		}
		boolean hit = false;
		switch (level)
		{
			case 4:
				hit = ambusher->update(x, y, gameboard) || hit;
			case 3:
				hit = chaser->update(x, y, gameboard) || hit;
			case 2:
				hit = fickle->update(x, y, gameboard) || hit;
			case 1:
				hit = stupid->update(x, y, gameboard) || hit;
		}
		if(hit) {
			score -= 30;
			pacman->die();
		}
	} else {
		levelUp();
	}
}
void Game::levelUp(void) 
{
	level++;
	if(level % 5 == 0) {
		pacman->lives++;
	}
	if(speed > 100) {
		speed -= 20;
	}
	newLevel();
}
void Game::newLevel(void)
{
	pacman->setPoint(13,23);
	ambusher->die();
	chaser->die();
	fickle->die();
	stupid->die();
	ambusher->setPoint(12,14);
	chaser->setPoint(13,14);
	fickle->setPoint(14,14);
	stupid->setPoint(15,14);
	dots = 0;
	initGameboard();
}
void Game::pause(void)
{
	paused = !paused;
}
boolean Game::isPlaying(void) {
	return !paused;
}

boolean Game::hasEnded(void) {
	return pacman->isDead();
}

void Game::initGameboard(void)
{
	for (int i = 0; i < 31; i++)
	{
		for (int j = 0; j < 28; j++)
		{
			if(this->initial_gameboard[i][j] == 'd' || this->initial_gameboard[i][j] == 'u'){
				dots++;
			}
			gameboard[i][j] = this->initial_gameboard[i][j];
		}
	}
}

void Game::keyListener(int key, int x, int y)
{
	if(key == 1112) {
		paused = !paused;
	}
	pacman->keyListener(key, x, y);
}

void Game::setDimensions(int x, int y)
{
	width = x;
	height = y;
}