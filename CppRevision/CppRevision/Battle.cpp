#include <iostream>
#include "Battle.h"

using namespace std;

#define WARRIOR_ONE_ATTACKS 1
#define WARRIOR_TWO_ATTACKS 2

void Battle::StartBattle(Warrior w1, Warrior w2)
{
	// Start with warrior one
	char whoseTurn = WARRIOR_ONE_ATTACKS;

	bool isDead = false;
	cout << "-----------------------START-----------------------" << endl;
	while (!isDead)
	{
		// Attack
		isDead = Battle::GetAttackResult(w1, w2, whoseTurn);

		// Change turn
		if (WARRIOR_ONE_ATTACKS == whoseTurn)
		{
			whoseTurn = WARRIOR_TWO_ATTACKS;
		}
		else
		{
			whoseTurn = WARRIOR_ONE_ATTACKS;
		}

		Sleep(500);
	}
	cout << "-----------------------END----------------------" << endl;
}

bool Battle::GetAttackResult(Warrior& w1, Warrior& w2, char whoseTurn)
{
	bool isDead = false;

	if (WARRIOR_ONE_ATTACKS == whoseTurn)
	{
		// Generate attack damage for warrior one
		int warriorOneAttackDamage = w1.Attack();

		// Generate block power for warrior two
		int warriorTwoBlockPower = w2.Block();

		// Generate the final result of the attack
		isDead = ConstructResult(warriorOneAttackDamage, warriorTwoBlockPower, w1, w2);
	}
	else if (WARRIOR_TWO_ATTACKS == whoseTurn)
	{
		// Generate attack damage for warrior two
		int warriorTwoAttackDamage = w2.Attack();

		// Generate block power for warrior one
		int warriorOneBlockPower = w1.Block();

		// Generate the final result of the attack
		isDead = ConstructResult(warriorTwoAttackDamage, warriorOneBlockPower, w2, w1);
	}
	else
	{
		;
	}

	return isDead;
}

bool ConstructResult(int attackDamage, int blockPower, Warrior& attacker, Warrior& defender)
{
	int damageDone = attackDamage - blockPower;
	bool isDead = false;

	// In case the block power is greater than the attack damage
	if (damageDone < 0)
	{
		damageDone = 0;
	}

	cout << attacker.GetName() << " attacks " << defender.GetName() << " and deals " << damageDone << endl;

	// Damage the defender
	defender.SetHP(defender.GetHP() - damageDone);

	// Check if the defender is dead
	if (defender.GetHP() <= 0)
	{
		cout << defender.GetName() << " has Died and " << attacker.GetName() << " is Victorious" << endl;
		cout << "Game Over" << endl;
		isDead = true;
	}

	return isDead;
}