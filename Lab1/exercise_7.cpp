#include <iostream>
#include <string.h>

using namespace std;

class Person
{
    char*   name;
    int     age;

public:
    // getter and setter for the name
    void setName(char* name)
    {
        int len = strlen(name);

        this->name = new char[len+1];

        strcpy(this->name, name);
    }
    const char* getName() const
    {
        return this->name;
    }

    // getter and setter for the age
    void setAge(int age)
    {
        this->age = age;
    }
    int getAge()
    {
        return this->age;
    }
};


int main()
{
    Person person;

    char name[] = "Ivan Shpirov";

    person.setAge(17);
    person.setName(name);

    cout << "Name: " << person.getName() << endl;
    cout << "Age : " << person.getAge() << endl;

    return 0;
}
