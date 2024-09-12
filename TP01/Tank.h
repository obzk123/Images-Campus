#pragma once
#include "Warrior.h"

class Tank : public Warrior
{
private:
	float shield;
	float maxShield;

public:
	Tank();

	Tank(std::string name, float damage, float life, float shield);

	virtual void ReceiveDamage(float damage) override;
	virtual void ShowStats() override;
	virtual void ResetStats() override;

	float GetShield() const { return this->shield; }
	void SetShield(float newShield) { this->shield = newShield; }

	float GetMaxShield() const { return this->maxShield; }
	void SetMaxShield(float newMaxShield) { this->maxShield = newMaxShield; }
};

