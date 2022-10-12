#pragma once
#include "Enemy.h"


class Ogr : public Enemy {
public:
	Ogr();
	void fight(Entity* enemy);
	void change_dir(int iter);
};