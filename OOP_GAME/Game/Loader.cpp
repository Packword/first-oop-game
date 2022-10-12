#include "Loader.h"



bool Loader::try_load(Snapshot saver, std::string filename) {
	std::ifstream filetest(filename);
	if (filetest.fail() == true) {
		std::cout << "Файл не существует или битый, невозможно загрузить\n";
		return 0;
	}
	std::ifstream file;
	file.open("hash" + filename); // ДОБАВИТЬ ПРОВЕРКУ НА КОРРЕКТНОСТЬ ФАЙЛА
	if (file.fail() == true) {
		std::cout << "Файл не существует или битый, невозможно загрузить\n";
		return 0;
	}
	int hash2;
	file >> hash2;
	file.close();
	int hash1 = saver.hash_func_ret(filename);
	if (hash1 == hash2) {
		return 1;
	}
	else {
		std::cout << "Файл не существует или битый, невозможно загрузить\n";
		return 0;
	}
}


Field* Loader::load_from_file(std::string filename) {
	std::ifstream file;
	file.open(filename);
	int width, height, enemyCount, y, x, tmp;
	std::string skip;
	file >> skip;
	file >> width;
	file >> skip;
	file >> height;
	Field* saveModel = new Field(width, height);
	file >> skip;
	file >> enemyCount;
	(*saveModel).enemies.clear();
	for (int i = 0; i < (*saveModel).getWidth(); i++) {
		for (int j = 0; j < (*saveModel).getHeight(); j++) {
			file >> skip;
			file >> skip;
			(*saveModel).board[i][j] = Cell(i, j, skip);
			file >> skip;
			file >> skip;
			if (skip == "Heal") { Heal* potion = new Heal; (*saveModel).board[i][j].setEntity(potion); }
			if (skip == "Protect") { Protect* potion = new Protect; (*saveModel).board[i][j].setEntity(potion); }
			if (skip == "Damage") { Damage* potion = new Damage; (*saveModel).board[i][j].setEntity(potion); }
		}
	}
	file >> skip;
	file >> y;
	file >> skip;
	file >> x;
	Character* Hero = new Character;
	(*saveModel).board[x][y].setEntity(Hero);
	(*saveModel).setHero(&(*saveModel).board[x][y]);
	file >> skip;
	file >> tmp;
	dynamic_cast<Character*>((*saveModel).getHero()->getEntity())->setHealth(tmp);
	file >> skip;
	file >> tmp;
	dynamic_cast<Character*>((*saveModel).getHero()->getEntity())->setAttack(tmp);
	file >> skip;
	file >> tmp;
	dynamic_cast<Character*>((*saveModel).getHero()->getEntity())->setArmor(tmp);
	for (int i = 0; i < enemyCount; i++) {
		std::string type;
		Commands dir;
		int hp;
		file >> skip;
		file >> type;
		file >> skip;
		file >> y;
		file >> skip;
		file >> x;
		file >> skip;
		file >> hp;
		file >> skip;
		file >> skip;
		if (skip == "UP") { dir = UP; }
		if (skip == "DOWN") { dir = DOWN; }
		if (skip == "RIGHT") { dir = RIGHT; }
		if (skip == "LEFT") { dir = LEFT; }
		if (type == "Goblin") { 
			Goblin* temp = new Goblin(); 
			temp->setHealth(hp); 
			temp->set_direction(dir); 
			(*saveModel).board[x][y].setEntity(temp); 
			(*saveModel).enemies.push_back(&(*saveModel).board[x][y]); 
		}
		if (type == "Ogr") {
			Ogr* temp = new Ogr();
			temp->setHealth(hp);
			temp->set_direction(dir);
			(*saveModel).board[x][y].setEntity(temp);
			(*saveModel).enemies.push_back(&(*saveModel).board[x][y]);
		}
		if (type == "Troll") {
			Troll* temp = new Troll();
			temp->setHealth(hp);
			temp->set_direction(dir);
			(*saveModel).board[x][y].setEntity(temp);
			(*saveModel).enemies.push_back(&(*saveModel).board[x][y]);
		}
	}
	file.close();
	return saveModel;
}