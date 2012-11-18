#pragma once
#include "mydrawable.h"
class Ghost :
	public MyDrawable
{
public:
	Ghost(void);
	~Ghost(void);
	boolean update(int x, int y, char gameboard[][28]);
	int mortal;
	virtual void makeMortal(void);
	const static int mat;
	void die(void);
protected:
	float step;
	boolean going_out;
	boolean moving;
	boolean goTo(int dir, char gameboard[][28]);
	virtual void walk(int x, int y, char gameboard[][28]);
	void wrap(void);
	int dir;
	int my_material;
	float move_prob;
	float change_prob;
};

