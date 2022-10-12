#include "Ogr.h"


Ogr::Ogr() { setHealth(7); setArmor(1); setAttack(2); }
void Ogr::fight(Entity* enemy) { plusHealth(-(dynamic_cast<Character&>(*enemy).getAttack() * (1 - getArmor() / 100))); };
void Ogr::change_dir(int iter) {
	if (iter % 8 == 0) { set_direction(LEFT); }
	if (iter % 8 == 2) { set_direction(UP); }
	if (iter % 8 == 4) { set_direction(RIGHT); }
	if (iter % 8 == 6) { set_direction(DOWN); }
}