#include <iostream>
#include <string.h>

using namespace std;

class Person
{
    char*   name;
    int     age;

public:
    Person(char* name, int age)
    {
        // get the size of the argument name
        int len = strlen(name);

        // allocate memory for class name
        this->name = new char[len+1]; // +1 is for the termination char \0

        strcpy(this->name, name);

        // assign the age
        this->age = age;
    }

    ~Person()
    {
        // delete operator should only be used either for the pointers
        // pointing to the memory allocated using new operator or for a NULL pointer

        delete[] this->name;

        cout << "Destruction!\n";
    }

    const char* getName() const
    {
        return this->name;
    }
    int getAge()
    {
        return this->age;
    }
};

int main()
{
    int age = 21;
    char name[] = "Emiliyan";

    Person person(name, age);

    cout << "Name: " << person.getName() << endl;
    cout << "Age: " << person.getAge() << endl;

    return 0;
}
