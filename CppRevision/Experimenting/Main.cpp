#include <iostream>
#include <string>
#include <memory>       // Pointers being smart
#include <vector>       //For the usage of vector - dynamic array representation.

class Animal
{
protected:
    std::string name;
    int years;
    std::string type;

public:
    Animal() : name(""), years(0), type("animal") 
    {
        std::cout << "Animal constructed through initializer list" << std::endl;
    }

    Animal(std::string name, int years, std::string type)
    {
        this->name = name;
        this->years = years;
        this->type = type;

        std::cout << "Animal constructed through parameterized constructor" << std::endl;
    }

    Animal(const Animal& animal)
    {
        this->name = animal.name;
        this->years = animal.years;
        this->type = animal.type;

        std::cout << "Animal constructed through copy constructor" << std::endl;
    }

    Animal(const Animal&& animal) = delete;

    ~Animal()
    {
        std::cout << "Animal destroyed" << std::endl;
    }

    virtual void MakeSound() = 0;
    virtual void Walk() = 0;

    void PrintName()
    {
        std::cout << name << std::endl;
    }
    void PrintYears()
    {
        std::cout << years << std::endl;
    }
    void PrintType()
    {
        std::cout << type << std::endl;
    }
};

class Wolf : public Animal
{
private:
    std::string positionInThePack;

public:
    Wolf(std::string name, int years, std::string positionInThePack) : Animal(name, years, "wolf")
    {
        this->positionInThePack = positionInThePack;
    }

    Wolf() : Animal()
    {
        this->positionInThePack = "";
        this->type = "wolf";
    }

    Wolf(const Wolf& wolf) : Animal(wolf)
    {
        this->positionInThePack = wolf.positionInThePack;
    }

    ~Wolf()
    {
        std::cout << "Wolf destroyed" << std::endl;
    }

    void MakeSound() override
    {
        std::cout << "I'm a wolf" << std::endl;
    }

    void Walk() override
    {
        std::cout << "I walk like a wolf" << std::endl;
    }

    void PrintPosition()
    {
        std::cout << this->positionInThePack << std::endl;
    }

};

class Bear : public Animal
{
private:
    int weight;

public:
    Bear(std::string name, int years, int weight) : Animal(name, years, "bear")
    {
        this->weight = weight;
    }

    Bear() : Animal()
    {
        this->weight = 0;
        this->type = "bear";
    }

    Bear(const Bear& bear) : Animal(bear)
    {
        this->weight = bear.weight;
    }

    ~Bear()
    {
        std::cout << "Bear destroyed" << std::endl;
    }

    void MakeSound() override
    {
        std::cout << "I'm a bear" << std::endl;
    }

    void Walk() override
    {
        std::cout << "I walk like a bear" << std::endl;
    }
};

int main()
{
    /* Bear created on the stack. Initialized through the initializer_list constructor */
    Bear bear;
    bear.MakeSound();
    bear.Walk();
    std::cout << "-----------------------------------------" << std::endl;

    /* Wolf created through its Base class on the Heap. Initialized throught the init_list constructor */
    Animal* dyn_animal = new Wolf();
    dyn_animal->MakeSound();
    dyn_animal->Walk();
    std::cout << "-----------------------------------------" << std::endl;

    /* Wolf created through its Base class on the Heap. Initialized throught the parameterized constructor */
    Animal* dyn_wolf = new Wolf("Alpha", 22, "alpha");
    dyn_wolf->PrintName();
    dyn_wolf->PrintYears();
    dyn_wolf->PrintType();
    std::cout << "-----------------------------------------" << std::endl;

    /* Smart unique pointer - Bear object constructed with copy constructor */
    std::unique_ptr<Bear> smart_unique_bear = std::make_unique<Bear>(bear);
    std::cout << "smart_unique_bear" << std::endl;
    smart_unique_bear->MakeSound();
    smart_unique_bear->Walk();
    smart_unique_bear->PrintName();
    smart_unique_bear->PrintType();
    smart_unique_bear->PrintYears();
    std::cout << "-----------------------------------------" << std::endl;

    /* Smart shared pointer - Wolf object contructed with parameters */
    std::shared_ptr<Wolf> smart_shared_wolf_1 = std::make_shared<Wolf>("Rizov", 22, "alpha");
    std::cout << "smart_shared_wolf_1\n";
    smart_shared_wolf_1->MakeSound();
    smart_shared_wolf_1->Walk();
    smart_shared_wolf_1->PrintName();
    smart_shared_wolf_1->PrintType();
    smart_shared_wolf_1->PrintYears();
    smart_shared_wolf_1->PrintPosition();
    std::cout << "Reference_count: " << smart_shared_wolf_1.use_count() << std::endl;
    std::cout << "-----------------------------------------" << std::endl;

    /*/* Test shared pointers 
    {
        std::shared_ptr<Wolf> smart_shared_wolf_2 = smart_shared_wolf_1;
        std::cout << "smart_shared_wolf_2\n";
        smart_shared_wolf_2->MakeSound();
        smart_shared_wolf_2->Walk();
        smart_shared_wolf_2->PrintName();
        smart_shared_wolf_2->PrintType();
        smart_shared_wolf_2->PrintYears();
        smart_shared_wolf_2->PrintPosition();
        std::cout << "Reference_count: " << smart_shared_wolf_1.use_count() << std::endl;
        std::cout << "-----------------------------------------" << std::endl;
    }
    std::cout << "Reference_count: " << smart_shared_wolf_1.use_count() << std::endl;
    */


    /* Create a dynamic array/vector */
    std::vector<Wolf> vector_of_wolves;
    

    return 0;
}

