#pragma once

#include <string>

class Warrior
{

private:
	std::string name;
	float damage;
	float life;
	float maxLife;

public:
	
	//Constructors
	Warrior();
	Warrior(std::string name, float damage, float life);


	//Methods
	virtual void AttackDamage(Warrior* warrior);
	virtual void ReceiveDamage(float damage);
	virtual void ShowStats();
	virtual void ResetStats();


	//Propertys
	std::string GetName() { return this->name; }
	float GetDamage() const { return this->damage; }
	float GetLife() const { return this->life; }
	float GetMaxLife() const { return this->maxLife; }

	void SetName(std::string newName) { this->name = newName; }
	void SetDamage(float newDamage) { this->damage = newDamage; }
	void SetLife(float newLife) { this->life = newLife; }
	void SetMaxLife(float newMaxLife) { this->maxLife = newMaxLife; }

	bool isAlive() const { return life > 0; }

};