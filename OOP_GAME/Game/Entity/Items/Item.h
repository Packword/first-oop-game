#pragma once
#include "../Entity.h"


class Item : public Entity {
protected:
	int Value;
public:
	int getValue();
};