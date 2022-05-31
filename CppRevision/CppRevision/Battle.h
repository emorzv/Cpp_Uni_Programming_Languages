#ifndef BATTLE
#define BATTLE "defined"

#include <Windows.h>
#include "Warrior.h"

bool ConstructResult(int, int, Warrior&, Warrior&);

class Battle
{
public:
	static void StartBattle(Warrior w1, Warrior w2);
	static bool GetAttackResult(Warrior& w1, Warrior& w2, char whoseTurn);
};

#endif // !BATTLE




