#pragma once
#include "Enemy.h"


class Goblin : public Enemy {
public:
	Goblin();
	void fight(Entity* enemy);
	void change_dir(int iter);
};