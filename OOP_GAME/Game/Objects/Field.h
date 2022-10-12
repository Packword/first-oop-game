#pragma once
#include "Cell.h"
#include "../Entity/Entity.h"
#include "../Entity/Character/Character.h"
#include "../Entity/Items/Item.h"
#include "../Entity/Enemies/Goblin.h"
#include "../Entity/Enemies/Ogr.h"
#include "../Entity/Enemies/Troll.h"
#include "../Commander.h"
#include <vector>

class Field {
private:
	int width;
	int height;
	Cell* enter;
	Cell* exit;
	Cell* hero;
	int start_enemy_count = 0;
public:
	Cell** board;
	//Cell* enemies[46];
	std::vector <Cell*> enemies;


	Field();
	int getStartEnemyCount();
	Cell* getEnter();
	Cell* getExit();
	Cell* getHero();
	int getWidth();
	int getHeight();
	int getEnemyIndex(Cell* obj);
	void setEnter(Cell* obj);
	void setExit(Cell* obj);
	void setHero(Cell* obj);
	void setWidth(int value);
	void setHeight(int value);
	void start_finish_generate();
	void spawn_hero();
	void spawn_walls();
	void generate_enemies();
	void generate_items();
	void moveEntity(Cell cell, Commands command, int enemy_Number = 0);
	Field(int user_width, int user_height);
	//конструктор копирования
	Field(const Field& obj);
	Field& operator=(const Field& obj);
	//конструктор перемещения
	Field(Field&& obj);
	Field& operator=(Field&& obj);
	~Field();
};