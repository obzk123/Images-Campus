#pragma once
#include "Warrior.h"
class Wizard :public Warrior
{
public:
	Wizard();

	Wizard(std::string name, float damage, float life);

	virtual void AttackDamage(Warrior* warrior) override;
};

