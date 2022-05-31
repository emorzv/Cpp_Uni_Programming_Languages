#ifndef WARRIOR
#define WARRIOR "defined"

// included system libs
#include <string>

using namespace std;

class Warrior
{
private:
	string name;
	int healthPoints;
	int attackPower;
	int blockPower;

public:
	/* Main functionalities */
	int Attack();
	int Block();

	/* List of constructors */
	Warrior();
	Warrior(string name, int healthPoints, int attackPower, int blockPower);
	Warrior(const Warrior& warrior);
	Warrior(Warrior&&) = delete;

	/* Destructor */
	~Warrior();

	/* Getters */
	string GetName() const;
	int GetHP() const;
	int GetAttackPower() const;
	int GetBlockPower() const;

	/* Setters */
	void SetName(string name);
	void SetHP(int hp);
	void SetAttackPower(int attackPower);
	void SetBlockPower(int blockPower);

	/* Operator overloading */
};
#endif // !WARRIOR