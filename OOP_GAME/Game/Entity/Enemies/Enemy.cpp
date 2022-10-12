#include "Enemy.h"


const Commands Enemy::get_direction() const {
	return this->dir;
}


const std::string Enemy::get_direction_str() const {
	if (this->dir == UP) {
		return "UP";
	}
	if (this->dir == DOWN) {
		return "DOWN";
	}
	if (this->dir == LEFT) {
		return "LEFT";
	}
	if (this->dir == RIGHT) {
		return "RIGHT";
	}
}


void Enemy::set_direction(Commands val){
	this->dir = val;
}


const int Enemy::getArmor() const {
	return this->Armor;
}
void Enemy::setArmor(int val) {
	this->Armor = val;
}
const int Enemy::getHealth() const {
	return this->Health;
}
void Enemy::setHealth(int val) {
	this->Health = val;
}
const int Enemy::getAttack() const {
	return this->Attack;
}
void Enemy::setAttack(int val) {
	this->Attack = val;
}
void Enemy::plusHealth(int val) {
	this->Health += val;
}

std::ostream& operator<<(std::ostream& out, const Enemy& enemy) {
	std::string text = "\nEnemy info: \nHealth: " + std::to_string(enemy.getHealth()) + "\nDamage: " + std::to_string(enemy.getAttack()) + "\nArmor: " + std::to_string(enemy.getArmor()) + '\n';
	out << text;
	return out;
}