#include "Snapshot.h"


void Snapshot::hash_func_to_file(std::string filename) {
	std::ifstream file;
	std::ofstream hash_file;
	std::string hash_file_name = "hash" + filename;
	file.open(filename);
	hash_file.open(hash_file_name);
	int hash = 0;
	char skip = 'a';
	while (!file.eof()) {
		file >> skip;
		hash = (256 * hash + skip) % 115249;
	}
	hash_file << hash;
	file.close();
	hash_file.close();
}


int Snapshot::hash_func_ret(std::string filename) {
	std::ifstream file;
	file.open(filename);
	int hash = 0;
	char skip = 'a';
	while (!file.eof()) {
		file >> skip;
		hash = (256 * hash + skip) % 115249;
	}
	file.close();
	return hash;
}


void Snapshot::save_to_file(Field* modelField, std::string filename, int mode) {
	std::ofstream file;
	file.open(filename, std::ofstream::trunc);
	file << "Width " << modelField->getWidth() << '\n';
	file << "Height " << modelField->getHeight() << '\n';
	file << "EnemyCount " << modelField->enemies.size() << '\n';
	for (int i = 0; i < modelField->getWidth(); i++){
		for (int j = 0; j < modelField->getHeight(); j++) {
			file << "CellType " << modelField->board[i][j].getType() << '\n';
			if (modelField->board[i][j].getEntity() == nullptr) {
				file << "CellEntity None" << '\n';
			}
			if ((dynamic_cast<Character*>(modelField->board[i][j].getEntity()))) {
				file << "CellEntity Hero" << '\n';
			}
			if ((dynamic_cast<Goblin*>(modelField->board[i][j].getEntity()))) {
				file << "CellEntity Goblin" << '\n';
			}
			if ((dynamic_cast<Troll*>(modelField->board[i][j].getEntity()))) {
				file << "CellEntity Troll" << '\n';
			}
			if ((dynamic_cast<Ogr*>(modelField->board[i][j].getEntity()))) {
				file << "CellEntity Ogr" << '\n';
			}
			if ((dynamic_cast<Protect*>(modelField->board[i][j].getEntity()))) {
				file << "CellEntity Protect" << '\n';
			}
			if ((dynamic_cast<Damage*>(modelField->board[i][j].getEntity()))) {
				file << "CellEntity Damage" << '\n';
			}
			if ((dynamic_cast<Heal*>(modelField->board[i][j].getEntity()))) {
				file << "CellEntity Heal" << '\n';
			}
		}
	}
	file << "HeroCoordY " << modelField->getHero()->getposY() << '\n';
	file << "HeroCoordX " << modelField->getHero()->getposX();
	file << "HeroHealth " << (dynamic_cast<Character&>(*modelField->getHero()->getEntity())).getHealth() << '\n';
	file << "HeroAttack " << (dynamic_cast<Character&>(*modelField->getHero()->getEntity())).getAttack() << '\n';
	file << "HeroArmor " << (dynamic_cast<Character&>(*modelField->getHero()->getEntity())).getArmor() << '\n';
	for (int i = 0; i < modelField->enemies.size(); i++) {
		if ((dynamic_cast<Goblin*>(modelField->enemies[i]->getEntity()))) {
			file << "CellEntity Goblin" << '\n';
		}
		if ((dynamic_cast<Troll*>(modelField->enemies[i]->getEntity()))) {
			file << "CellEntity Troll" << '\n';
		}
		if ((dynamic_cast<Ogr*>(modelField->enemies[i]->getEntity()))) {
			file << "CellEntity Ogr" << '\n';
		}
		file << "EnemyCoordY " << modelField->enemies[i]->getposY() << '\n';
		file << "EnemyCoordX " << modelField->enemies[i]->getposX() << '\n';
		file << "EnemyHealth " << (dynamic_cast<Enemy&>(*modelField->enemies[i]->getEntity())).getHealth() << '\n';
		file << "EnemyDir " << (dynamic_cast<Enemy&>(*modelField->enemies[i]->getEntity())).get_direction_str() << '\n';
	}
	file.close();
	hash_func_to_file(filename);
}