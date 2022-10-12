#include "Controls.h"

char Controls::get_command() {
	std::cout << "Введите направление движения персонажа, где " << get_up() << " - наверх, "
		<< get_down() << " - вниз, " << get_right() << " - вправо, " << get_left() << " - влево\nИли сохранитесь нажав " << get_save() << "\nИли загрузитесь нажав " << get_load() << '\n';
	char cur_control;
	std::cin >> cur_control;
	if (cur_control == up || cur_control == down || cur_control == right || cur_control == left || cur_control == save || cur_control == load) {
		return cur_control;
	}
	else {
		return none;
	}
}
