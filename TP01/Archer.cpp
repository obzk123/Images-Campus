#include "Archer.h"
#include <random>
#include <iostream>

Archer::Archer() : Warrior()
{
}

Archer::Archer(std::string name, float damage, float life) : Warrior(name, damage, life)
{
}

void Archer::AttackDamage(Warrior* warrior)
{
	if (warrior == nullptr) return;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 1);
    int random_number = distrib(gen);

    if (random_number == 1) {
        warrior->ReceiveDamage(this->GetDamage() * 2);
        std::cout << "HIT THE " << this->GetName() << " TO " << warrior->GetName() << " Double DMG" << std::endl;
    } else {
        std::cout << "MISS HIT THE " << this->GetName() << " TO " << warrior->GetName() << std::endl;
    }
}
