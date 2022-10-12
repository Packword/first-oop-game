#pragma once
#include <string>
#include <iostream>
#include"../Entity/Entity.h"


class Cell {
private:
	Entity* entity = nullptr;
	int x;
	int y;
	std::string Type; // EMPTY, WALL, START, FINISH

public:
	Cell();
	Cell(int x, int y, std::string typeCell);
	void setposX(int val);
	void setposY(int val);
	int getposX();
	int getposY();
	std::string getType();
	void setType(std::string val);
	void setEntity(Entity* val);
	Entity* getEntity();

};
