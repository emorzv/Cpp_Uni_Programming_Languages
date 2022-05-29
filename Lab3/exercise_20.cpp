#include <iostream>

using namespace std;

class Animal
{
public:
    virtual void makeSound() = 0;
};

class Bear: public Animal
{
    int eatenFish;
public:
    Bear()
    {
        this->eatenFish = 0;
    }

    void makeSound()
    {
        cout << "bear sound.." << endl;
    }

    void eatFish()
    {
        cout << "fish eaten.." << endl;
        this->eatenFish += 1;
    }
};

class Bird: public Animal
{
    int distanceFlown;

public:
    Bird()
    {
        this->distanceFlown = 0;
    }

    void makeSound()
    {
        cout << "bird sound.." << endl;
    }

    void flyAway()
    {
        cout << "flying.." << endl;
        this->distanceFlown += 100;
    }
};

class Lion: public Animal
{
    int eatenAntelopes;

public:
    Lion()
    {
        this->eatenAntelopes = 0;
    }

    void makeSound()
    {
        cout << "lion sound.." << endl;
    }

    void eatAntelope()
    {
        cout << "eating.." << endl;
        this->eatenAntelopes += 1;
    }
};

int main()
{
    Lion lion;
    lion.eatAntelope();

    Bird bird;
    bird.flyAway();

    Bear bear;
    bear.eatFish();


    Animal* animal;

    animal = &lion;
    animal->makeSound(); // only makeSound is available, because the pointer is of type Animal
    animal = &bear;
    animal->makeSound(); // only makeSound is available, because the pointer is of type Animal
    animal = &bird;
    animal->makeSound(); // only makeSound is available, because the pointer is of type Animal


    return 0;
}
