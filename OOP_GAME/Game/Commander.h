#pragma once
#include "Controls.h"

enum Commands {
	UP, DOWN, RIGHT, LEFT, NOTHING, SAVE, LOAD,
};


class Commander
{
private:
	Controls *controls;
public:
	Commander() { controls = new Controls; };
	Commands determinate_the_command();
	~Commander() { delete controls; }
};