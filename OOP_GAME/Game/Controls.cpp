#include "Controls.h"

char Controls::get_command() {
	std::cout << "������� ����������� �������� ���������, ��� " << get_up() << " - ������, "
		<< get_down() << " - ����, " << get_right() << " - ������, " << get_left() << " - �����\n��� ����������� ����� " << get_save() << "\n��� ����������� ����� " << get_load() << '\n';
	char cur_control;
	std::cin >> cur_control;
	if (cur_control == up || cur_control == down || cur_control == right || cur_control == left || cur_control == save || cur_control == load) {
		return cur_control;
	}
	else {
		return none;
	}
}
