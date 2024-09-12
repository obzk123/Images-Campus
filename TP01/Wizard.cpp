#include "Wizard.h"

#include <random>
#include <iostream>

Wizard::Wizard() : Warrior() { }

Wizard::Wizard(std::string name, float damage, float life) : Warrior(name, damage, life) { }

void Wizard::AttackDamage(Warrior* warrior)
{
    if (warrior == nullptr) return;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 3);
    int random_number = distrib(gen);
    if (random_number == 0) 
    {
        warrior->ReceiveDamage(this->GetDamage() * 2);
        std::cout <<"HIT THE " << this->GetName() << " TO " << warrior->GetName() << " Double DMG" << std::endl;
    } 
    else 
    {
        warrior->ReceiveDamage(this->GetDamage());
        std::cout <<"HIT THE " << this->GetName() << " TO " << warrior->GetName() << std::endl;
    }
}

