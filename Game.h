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
private:
	Chaser* chaser;
	Ambusher* ambusher;
	Fickle* fickle;
	Stupid* stupid;
	Pacman* pacman;
	Powerup* powerup;
	Dot* dot;
	Wallmanager* wallmanager;
};

