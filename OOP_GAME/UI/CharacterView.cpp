#include "CharacterView.h"


CharacterView::CharacterView(Character& obj) : mainChar(obj) {}
void CharacterView::print() {
	std::cout << "\n�������������� �����: �������� - " << mainChar.getHealth() << ", ����� - " << mainChar.getArmor() << ", ���� - " << mainChar.getAttack() << "\n";
}