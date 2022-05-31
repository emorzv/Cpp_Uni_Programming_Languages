#include <iostream>
#include "Battle.h"
#include "Warrior.h"


int main()
{
    
    // Construct WarriorOne with the parameterized constructor
    Warrior warriorOne("Rizov", 100, 50, 25);

    // Construct WarriorTwo with the parameterized constructor
    Warrior warriorTwo("Rizov's Shadow", 250, 20, 5);

    // Start the fight
    // Passing by value triggers the copy constructors
    Battle::StartBattle(warriorOne, warriorTwo);

    return 0;
}
