#include "game.h"
#include "Tank.h"
#include "Archer.h"
#include "Wizard.h"
#include <iostream>
#include <random>


Game::Game(int groupCount)
{
	this->countWarriorGroup = groupCount;
}

void Game::play()
{
	this->initGame();
	this->loopGame();
}

void Game::initGame()
{
	this->groupOne.resize(this->countWarriorGroup);
	this->groupTwo.resize(this->countWarriorGroup);
}


void Game::selectWarriors()
{
	std::random_device rd; 
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(0, 2);

	for (int i = 0; i < this->countWarriorGroup; i++)
	{
		this->groupOne[i] = createWarrior(distrib(gen));
		this->groupTwo[i] = createWarrior(distrib(gen));
	}
}

Warrior* Game::createWarrior(int number)
{
	Warrior* newWarrior = nullptr;
	switch (number)
	{
	case 0:
		newWarrior = new Tank("Tank", 10, 100.f, 50.f);
		break;
	case 1:
		newWarrior = new Archer("Archer", 15.f, 100.f);
		break;
	case 2:
		newWarrior = new Wizard("Wizard", 15.f, 100.f);
		break;
	default:
		newWarrior = new Tank("Default", 1.f, 100.f, 50.f);
		break;
	}
	return newWarrior;
}


Game::~Game()
{
	for (int i = 0; i < this->countWarriorGroup; i++)
	{
		if (this->groupOne[i] != nullptr)
		{
			delete this->groupOne[i];
			this->groupOne[i] = nullptr;
		}

		if (this->groupTwo[i] != nullptr)
		{
			delete this->groupTwo[i];
			this->groupTwo[i] = nullptr;
		}
	}
}


void Game::loopGame()
{
	bool isPlaying = true;
	do 
	{
		this->selectWarriors();
		this->combatLoop();
		this->showStats();
		isPlaying = this->continueGame();
	} while (isPlaying);
}

void Game::combatLoop()
{
	for (int i = 0; i < this->countWarriorGroup; i++)
	{
		this->fight(i+1, this->groupOne[i], this->groupTwo[i]);
	}
}

void Game::fight(int round, Warrior* warrior1, Warrior* warrior2)
{
	std::cout << "Round " << round << std::endl;
	bool continueFight = true;
	do
	{
		if (warrior1->isAlive())
		{
			warrior1->AttackDamage(warrior2);
		}
		else
		{
			continueFight = false;
		}
		
		if (warrior2->isAlive())
		{
			warrior2->AttackDamage(warrior1);
		}
		else
		{
			continueFight = false;
		}

	} while (continueFight);
	std::cout << "End Round " << round << std::endl << std::endl;


}

void Game::showStats()
{
	int groupOneLives = 0;
	int groupTwoLives = 0;

	for (int i = 0; i < this->countWarriorGroup; i++)
	{
		if (this->groupOne[i]->isAlive())
		{
			groupOneLives++;
		}
		else
		{
			groupTwoLives++;
		}
	}


	if (groupOneLives > groupTwoLives)
	{
		std::cout << "The winner is group one with " << groupOneLives << " lives against " << groupTwoLives << std::endl;
	}
	else if (groupTwoLives > groupOneLives)
	{
		std::cout << "The winner is group two with " << groupTwoLives << " lives against " << groupOneLives << std::endl;
	}
	else
	{
		std::cout << "It's a tie with " << groupOneLives << " lives" << std::endl;
	}
}

bool Game::continueGame()
{
	char answer;
	std::cout << "Want you play again? Y / N" << std::endl;
	std::cin >> answer;
	return answer == 'Y' || answer == 'y' ? true : false;
}
