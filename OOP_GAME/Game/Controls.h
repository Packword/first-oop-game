#pragma once
#include <iostream>

class Controls {
private:
	char up = 'u', down = 'b', right = 'k', left = 'h', none = '@', save = 's', load = 'l';
public:
	Controls() = default;
	char get_up() { return up; }
	char get_down() { return down; }
	char get_left() { return left; }
	char get_right() { return right; }
	char get_none() { return none; }
	char get_save() { return save; }
	char get_load() { return load; }

	char get_command();
};