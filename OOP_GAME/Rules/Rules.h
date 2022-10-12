#pragma once

template<int EnemiesDied> 
class Rules {
public:
    Rules() = default;
    bool EnemiesChecker(int count);
	bool game_not_end(Field& field, int count);
};


template<int EnemiesDied>
bool Rules<EnemiesDied>::EnemiesChecker(int count) {
    return EnemiesDied <= count;
}

template<int EnemiesDied>
bool Rules<EnemiesDied>::game_not_end(Field& field, int count) {
	if ((field.getExit() == field.getHero()) || ((dynamic_cast<Character&>(*field.getHero()->getEntity())).getHealth() <= 0)) {
		if ((dynamic_cast<Character&>(*field.getHero()->getEntity())).getHealth() <= 0) {
			std::cout << "��� ����� ����.\n";
		}
		else {
			if (EnemiesChecker(count)) {
				std::cout << "�� ��������!\n";
			}
			else {
				std::cout << "����� ������������ ������!\n";
				return 1;
			}
		}
		return 0;
	}
	else {
		return 1;
	}
}