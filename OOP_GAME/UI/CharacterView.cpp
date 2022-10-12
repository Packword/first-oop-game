#include "CharacterView.h"


CharacterView::CharacterView(Character& obj) : mainChar(obj) {}
void CharacterView::print() {
	std::cout << "\nХарактеристики героя: здоровье - " << mainChar.getHealth() << ", броня - " << mainChar.getArmor() << ", урон - " << mainChar.getAttack() << "\n";
}