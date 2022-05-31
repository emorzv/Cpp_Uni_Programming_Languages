#include <iostream>
#include <ctime>
#include "Warrior.h"

/* Defualt constructor */
Warrior::Warrior() : name(""), healthPoints(0), attackPower(0), blockPower(0)
{
	cout << "Warrior constructed with an initializer list" << endl;
}

/* Parameterized contructor */
Warrior::Warrior(string name, int healthPoints, int attackPower, int blockPower)
{
	this->name = name;
	this->healthPoints = healthPoints;
	this->attackPower = attackPower;
	this->blockPower = blockPower;

	cout << "Warrior contructed with a parameterized constructor" << endl;
}

/* Copy contructor */
Warrior::Warrior(const Warrior& warrior)
{
	this->name = warrior.name;
	this->healthPoints = warrior.healthPoints;
	this->attackPower = warrior.attackPower;
	this->blockPower = warrior.blockPower;

	cout << "Warrior contructed with a copy constructor" << endl;
}

Warrior::~Warrior()
{
	cout << "Destructing a warrior" << endl;
}

/* Getters */
string Warrior::GetName()	  const { return name; }
int Warrior::GetHP()		  const { return healthPoints; }
int Warrior::GetAttackPower() const { return attackPower; }
int Warrior::GetBlockPower()  const { return blockPower; }

/* Setters */
void Warrior::SetName(string name)			  { this->name = name; }
void Warrior::SetHP(int hp)					  { this->healthPoints = hp; }
void Warrior::SetAttackPower(int attackPower) { this->attackPower = attackPower; }
void Warrior::SetBlockPower(int blockPower)	  { this->blockPower = blockPower; }

/* Functionaloties */
int Warrior::Attack()
{
	// Use the system time to generate a random number
	srand(time(NULL));

	// Generate the attack damage for the current attack
	// from 1 to the attack power of the warrior
	int tempAttackDamage = (1 + (rand() % this->attackPower));

	return tempAttackDamage;
}

int Warrior::Block()
{
	// Use the system time to generate a random number
	srand(time(NULL));

	// Generate the Block power for the current defense
	// from 1 to the block power of the warrior
	int tempBlockPower = (1 + (rand() % this->blockPower));

	return tempBlockPower;
}