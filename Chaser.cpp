#include "Chaser.h"

const int Chaser::mat = 4; 

Chaser::Chaser(void)
{
	my_material = mat;
	material = mat;
	move_prob = 10;
	change_prob = 0;
}


Chaser::~Chaser(void)
{
}
