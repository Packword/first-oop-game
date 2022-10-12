#pragma once
#include "../Logs/LoggerPull.h"
#include "../UI/FieldView.h"
#include "../Rules/Rules.h"
#include "Commander.h"
#include "Snapshot.h"
#include "Loader.h"


template<class WinChecker>
class Game {
private:
	Field* modelField;
	FieldView* field;
	LoggerPull* logger;
    Snapshot saver;
    Loader loader;
    WinChecker rules;
    Commander commander;
    int mode;
    int iter = 0;
public:
    void game();
    void Initialize();
};


template<class WinChecker>
void Game<WinChecker>::game() {
    Initialize();
	(*field).print();
	while (rules.game_not_end((*modelField), (*modelField).getStartEnemyCount() - (*modelField).enemies.size())) {
		Commands cur_com = commander.determinate_the_command();
		if (cur_com != NOTHING) {
			if (cur_com == UP || cur_com == DOWN || cur_com == RIGHT || cur_com == LEFT) {
				(*modelField).moveEntity(*(*modelField).getHero(), cur_com);
			}
			if (cur_com == SAVE) {
				std::cout << "Куда сохранить? Введите название файла в формате <filename>.txt\n";
				std::string filename;
				std::cin >> filename;
				saver.save_to_file(&(*modelField), filename, mode);
			}
			else {
				if (cur_com == LOAD) {
					std::cout << "Откуда загрузить? Введите название файла в формате <filename>.txt\n";
					std::string filename;
					std::cin >> filename;
					if(loader.try_load(saver, filename)){
						delete modelField;
						modelField = loader.load_from_file(filename);
						field = new FieldView(*modelField);
						logger = new LoggerPull(mode, (*modelField).getHero()->getEntity(), (*modelField).enemies);
					}
				}
				else {
					for (int i = 0; i < (*modelField).enemies.size(); i++) {
						if (typeid(*((*(*modelField).enemies[i]).getEntity())).name() == typeid(Goblin).name()) {
							(dynamic_cast<Goblin&>(*(*modelField).enemies[i]->getEntity())).change_dir(iter);
						}
						if (typeid(*((*(*modelField).enemies[i]).getEntity())).name() == typeid(Ogr).name()) {
							(dynamic_cast<Ogr&>(*(*modelField).enemies[i]->getEntity())).change_dir(iter);
						}
						if (typeid(*((*(*modelField).enemies[i]).getEntity())).name() == typeid(Troll).name()) {
							(dynamic_cast<Troll&>(*(*modelField).enemies[i]->getEntity())).change_dir(iter);
						}
						(*modelField).moveEntity(*(*modelField).enemies[i], (dynamic_cast<Enemy&>(*(*modelField).enemies[i]->getEntity())).get_direction(), i);
					}
					if (dynamic_cast<Character&>(*(*modelField).getHero()->getEntity()).getHealth() != (*(*logger).mainLogger).hero_stats[0] || dynamic_cast<Character&>(*(*modelField).getHero()->getEntity()).getAttack() != (*(*logger).mainLogger).hero_stats[1] || dynamic_cast<Character&>(*(*modelField).getHero()->getEntity()).getArmor() != (*(*logger).mainLogger).hero_stats[2]) {
						(*logger).writeHero();
						(*(*logger).mainLogger).clone_Character();
					}
					for (int i = 0; i < (*modelField).enemies.size(); i++) {
						if (dynamic_cast<Enemy&>(*(*modelField).enemies[i]->getEntity()).getHealth() != (*(*logger).mainLogger).enemy_stats[(*modelField).enemies[i]->getEntity()][0]) {
							(*logger).writeEnemy((*modelField).enemies[i]->getEntity());
							(*(*logger).mainLogger).clone_Enemy((*modelField).enemies[i]->getEntity());
						}
					}
					iter++;
				}
			}
			field->print();
		}
	}
}

template <class WinChecker>
void Game<WinChecker>::Initialize() {
    int user_height, user_width;
    std::cout << "Введите размеры поля.\nШирина = ";
    std::cin >> user_height;
    std::cout << "\nВысота = ";
    std::cin >> user_width;
    std::cout << '\n';
    std::cout << "Куда выводить логи? 0 - консоль, 1 - файл, 2 - файл и консоль:";
    std::cin >> mode;
    std::cout << '\n';
    modelField = new Field(user_width, user_height);
    field = new FieldView(*modelField);
    logger = new LoggerPull(mode, (*modelField).getHero()->getEntity(), (*modelField).enemies);
}