#include "Commander.h"

Commands Commander::determinate_the_command() {
	char dir = controls->get_command();
	if (dir == controls->get_up()) {
		return UP;
	}
	if (dir == controls->get_down()) {
		return DOWN;
	}
	if (dir == controls->get_left()) {
		return LEFT;
	}
	if (dir == controls->get_right()) {
		return RIGHT;
	}
	if (dir == controls->get_none()) {
		return NOTHING;
	}
	if (dir == controls->get_save()) {
		return SAVE;
	}
	if (dir == controls->get_load()) {
		return LOAD;
	}
}