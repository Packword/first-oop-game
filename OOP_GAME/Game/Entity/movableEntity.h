#pragma once
#include "Entity.h"


class movableEntity : public Entity {
protected:
	int Armor;
	int Health;
	int Attack;
public:
	virtual void setArmor(int val) = 0;
	virtual void setHealth(int val) = 0;
	virtual void setAttack(int val) = 0;
	virtual const  int getArmor() const = 0;
	virtual const  int getAttack() const = 0;
	virtual const  int getHealth() const = 0;
	virtual void plusHealth(int val) = 0;
	virtual void fight(Entity* enemy) = 0;

};