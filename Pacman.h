#pragma once
#include "mydrawable.h"
class Pacman :
	public MyDrawable
{
public:
	Pacman(void);
	~Pacman(void);
	virtual void draw(void);
	void update(void);
private:
	int ang;
	int inc_ang;
};

