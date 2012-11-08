#pragma once
#include "mydrawable.h"
class Text :
	public MyDrawable
{
public:
	Text(char* my_text);
	~Text(void);
	void draw(void);
};

