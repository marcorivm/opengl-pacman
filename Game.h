#pragma once
#include "Ambusher.h"
#include "Chaser.h"
#include "Fickle.h"
#include "Stupid.h"
#include "Pacman.h"
#include "Powerup.h"
#include "Dot.h"
#include "Wallmanager.h"
class Game
{
public:
	Game(void);
	~Game(void);
	void draw(void);
	void update(void);
private:
	void initGameboard(void);
	Chaser* chaser;
	Ambusher* ambusher;
	Fickle* fickle;
	Stupid* stupid;
	Pacman* pacman;
	Powerup* powerup;
	Dot* dot;
	Wallmanager* wallmanager;
	const static char initial_gameboard[31][28];
	char gameboard[31][28];
};

