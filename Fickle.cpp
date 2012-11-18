#include "Fickle.h"

const int Fickle::mat = 5; 


Fickle::Fickle(void)
{
	my_material = mat;
	material = mat;
	move_prob = 8;
	change_prob = 4;
}


Fickle::~Fickle(void)
{
}