#include "Warrior.h"
#include <iostream>

Warrior::Warrior()
{
	this->SetName("Default name");
	this->SetDamage(0);
	this->SetLife(0);
	this->SetMaxLife(0);
}

Warrior::Warrior(std::string name, float damage, float life) 
{
	this->SetName(name);
	this->SetDamage(damage);
	this->SetLife(life);
	this->SetMaxLife(life);
}


void Warrior::AttackDamage(Warrior* warrior) 
{
	if (warrior == nullptr) return;
	warrior->ReceiveDamage(this->GetDamage());
	std::cout << "HIT THE " << this->GetName() << " TO " << warrior->GetName() << std::endl;
}

void Warrior::ReceiveDamage(float damage) 
{
	this->SetLife(this->GetLife() - damage);
	if (this->GetLife() < 0) this->SetLife(0);
}

void Warrior::ShowStats() 
{
	std::cout << "Name: " << this->GetName() << "\nLife: " << this->GetLife() << "\nDamage: " << this->GetDamage() << std::endl;
}

void Warrior::ResetStats()
{
	this->SetLife(this->GetMaxLife());
}
