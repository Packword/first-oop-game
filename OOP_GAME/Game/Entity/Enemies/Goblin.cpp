#include "Goblin.h"


Goblin::Goblin() { setHealth(4); setArmor(0); setAttack(1); }
void Goblin::fight(Entity* enemy) { plusHealth(-(dynamic_cast<Character&>(*enemy).getAttack() * (1 - getArmor() / 100))); };
void Goblin::change_dir(int iter) {
	if (iter % 4 == 0) { set_direction(UP); }
	if (iter % 4 == 1) { set_direction(LEFT); }
	if (iter % 4 == 2) { set_direction(DOWN); }
	if (iter % 4 == 3) { set_direction(RIGHT); }
}
