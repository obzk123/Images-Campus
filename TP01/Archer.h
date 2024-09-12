#pragma once
#include "Warrior.h"
class Archer : public Warrior
{
public:
	Archer();

	Archer(std::string name, float damage, float life);
	virtual void AttackDamage(Warrior* warrior) override;
};

