#pragma once
#include "../movableEntity.h"
#include "../Character/Character.h"
#include "../../Commander.h"


class Enemy : public movableEntity {
private:
	Commands dir = UP;
public:
	const Commands get_direction() const;
	const std::string get_direction_str() const;
	void set_direction(Commands val);
	const int getArmor() const;
	void setArmor(int val);
	const int getHealth() const;
	void setHealth(int val);
	const int getAttack() const;
	void setAttack(int val);
	void plusHealth(int val);
	friend std::ostream& operator<<(std::ostream& out, const Enemy& enemy);
};