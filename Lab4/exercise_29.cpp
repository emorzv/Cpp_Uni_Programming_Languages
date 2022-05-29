#include <iostream>
#include <string.h>

using namespace std;

#define NAME_LEN ((int) 15)

// abstract class
class Node
{
    char* name;

public:
    Node* left;
    Node* right;

    Node()
    {
        left = right = NULL;
        this->name = new char[NAME_LEN];
    }
    ~Node()
    {
        delete[] this->name;
    }

    virtual void displayData() = 0;

    // parameters used by the derived classes
    virtual void retrieve(char*, int*) = 0;

    virtual int nodeType() = 0;

};

class Person : public Node
{
    int age;

public:
    Person(int age) : Node()
    {
        this->age = age;
    }

    ~Person()
    {
        // nothing allocated to be deleted
    }

    virtual void displayData()
    {
        cout << "Age: " << this->age << endl;
    }

    // the not used parameter is there
    // just to satisfy the pure virtual function prototype
    virtual void retrieve(char* not_used, int* age)
    {
        *age = this->age;
    }

    virtual int nodeType()
    {
        return 0;
    }
};

class Car : public Node
{
    int prod_year;
    char* brand;

public:
    Car(char* brand, int prod_year) : Node()
    {
        int len = strlen(brand);

        this->brand = new char[len+1];

        strcpy(this->brand, brand);
        this->prod_year = prod_year;
    }

    ~Car()
    {
        delete[] this->brand;
    }

    virtual void displayData()
    {
        cout << "Brand: " << this->brand << endl;
        cout << "Prod. Year: " << this->prod_year << endl;
    }

    virtual void retrieve(char* brand, int* prod_year)
    {
        *prod_year = this->prod_year;
        strcpy(brand, this->brand);
    }

    virtual int nodeType()
    {
        return 1;
    }

};

int main()
{
    Node* person = new Person(21);
    Node* car_left = new Car("BMW", 2020);
    Node* car_right = new Car("Tesla", 2021);

    person->left = car_left;
    person->right = car_right;

    int tempAge;
    person->retrieve(NULL, &tempAge);

    cout << "Person's name: " << tempAge << endl;
    cout << "Person's type number: " << person->nodeType() << endl;

    cout << endl;

    char tempCarRight[10];
    char tempCarLeft[10];
    int tempProdYearRight;
    int tempProdYearLeft;
    person->right->retrieve(tempCarRight, &tempProdYearRight);
    person->left->retrieve(tempCarLeft, &tempProdYearLeft);

    cout << "Person's left car brand: " << tempCarLeft << " and production year: " << tempProdYearLeft << endl;
    cout << "Person's left car type number: " << person->left->nodeType() << endl;
    cout << endl;

    cout << "Person's right car brand: " << tempCarRight << " and production year: " << tempProdYearRight << endl;
    cout << "Person's right car type number: " << person->right->nodeType();

    return 0;
}
