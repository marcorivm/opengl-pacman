#pragma once
#include "ghost.h"
class Fickle :
	public Ghost
{
public:
	Fickle(void);
	~Fickle(void);
	const static int mat;
	int dir;
};

