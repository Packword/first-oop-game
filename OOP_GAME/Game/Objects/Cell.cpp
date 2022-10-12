#include "Cell.h"
Cell::Cell() { Type = "EMPTY"; x = 0; y = 0; entity = nullptr; }


Cell::Cell(int x, int y, std::string typeCell) {
	this->x = x;
	this->y = y;
	this->Type = typeCell;
	entity = nullptr;
}


void Cell::setposX(int val) { this->x = val; }
void Cell::setposY(int val) { this->y = val; }
int Cell::getposX() { return this->x; }
int Cell::getposY() { return this->y; }
std::string Cell::getType() { return this->Type; }
void Cell::setType(std::string val) { this->Type = val; }
void Cell::setEntity(Entity* val) { this->entity = val; }
Entity* Cell::getEntity() { if (this != nullptr) { return entity; } }