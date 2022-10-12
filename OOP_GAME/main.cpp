#include "Game/Game.h"


int main()
{
	setlocale(0, "");
	srand(static_cast<unsigned int>(time(0)));
	Game<Rules<1>> newGame;
	newGame.game();
}