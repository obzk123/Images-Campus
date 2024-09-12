#pragma once

#include "Warrior.h"
#include <vector>

class Game
{

private:
	int countWarriorGroup = 0;
	std::vector<Warrior*> groupOne;
	std::vector<Warrior*> groupTwo;

public:
	Game(int groupCount);
	~Game();
	void initGame();
	void loopGame();
	void combatLoop();
	void fight(int round, Warrior* warrior1, Warrior* warrior2);
	void showStats();
	bool continueGame();
	void play();
	void selectWarriors();
	Warrior* createWarrior(int number);

};

