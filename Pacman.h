#pragma once
#include "mydrawable.h"
class Pacman :
	public MyDrawable
{
public:
	Pacman(void);
	~Pacman(void);
	void keyListener(int key, int x, int y);
	virtual void draw(void);
	int update(char gameboard[][28]);
	int getX(void);
	int getY(void);
	void die(void);
	boolean isDead(void);
	int lives;
private:
	int ang;
	int inc_ang;
	int dir;
	float step;
	void wrap(void);
	int getNextX(void);
	int getNextY(void);
	void incrementX(void);
	void incrementY(void);
	void animate(int val);
};

