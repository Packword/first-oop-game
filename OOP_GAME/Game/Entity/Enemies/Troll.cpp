#include "Troll.h"


Troll::Troll() { setHealth(10); setArmor(2); setAttack(3); }
void Troll::fight(Entity* enemy) { plusHealth(-(dynamic_cast<Character&>(*enemy).getAttack() * (1 - getArmor() / 100))); };
void Troll::change_dir(int iter) {
	if (iter % 12 == 0) { set_direction(RIGHT); }
	if (iter % 12 == 3) { set_direction(UP); }
	if (iter % 12 == 6) { set_direction(LEFT); }
	if (iter % 12 == 9) { set_direction(DOWN); }
}