#include "Tank.h"
#include <iostream>

Tank::Tank() : Warrior() 
{
	this->SetShield(100);
	this->SetShield(100);
}

Tank::Tank(std::string name, float damage, float life, float shield) : Warrior(name, damage, life) 
{
	this->SetShield(shield);
	this->SetMaxShield(shield);
}

void Tank::ReceiveDamage(float damage) 
{
	float totalLife = this->GetLife() + this->GetShield();
	totalLife -= damage;
	if (damage > this->GetShield())
	{
		this->SetShield(0);
		this->SetLife(this->GetLife() - (damage - this->GetShield()) );
		if (this->GetLife() < 0) this->SetLife(0);
	} 
	else 
	{
		this->SetShield(this->GetShield() - damage);
	}
}

void Tank::ShowStats() 
{
	Warrior::ShowStats();
	std::cout << "Shield: " << this->GetShield() << std::endl;
}

void Tank::ResetStats()
{
	Warrior::ResetStats();
	this->SetShield(this->GetMaxShield());
}
