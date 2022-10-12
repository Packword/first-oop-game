#pragma once

#include "Controls.h"
#include "Objects/Field.h"
class Controller {
private:
	Controls controls;
public:
	Controller() { Controls controls; };
	void action(Field& modelField);

};