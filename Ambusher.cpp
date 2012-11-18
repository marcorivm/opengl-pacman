#include "Ambusher.h"

const int Ambusher::mat = 6; 

Ambusher::Ambusher(void)
{
	my_material = mat;
	material = mat;
	move_prob = 9;
	change_prob = 1;
}


Ambusher::~Ambusher(void)
{
}
