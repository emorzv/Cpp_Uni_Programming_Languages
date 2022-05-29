#include <iostream>

using namespace std;

#define DECEMBER ((int) 12)
#define MONTHLY_RATE ((double) 0.42)

class Date
{
    int day;
    int month;
    int year;

public:
    Date(void)
        // : day(13), month(7), year(2000)
    {
        cout << "Day: "; cin >> this->day;
        cout << "Month: "; cin >> this->month;
        cout << "Year: "; cin >> this->year;
    }

    int getDay(void)
    {
        return this->day;
    }

    int getMonth(void)
    {
        return this->month;
    }

    int getYear(void)
    {
        return this->year;
    }
};

class Person
{
    string name;
    int age;
    int investment;
    Date* date;

public:
    Person()
    {
        cout << "Name: "; cin >> this->name;
        cout << "Age: "; cin >> this->age;
        cout << "Investment: "; cin >> this->investment;
        date = new Date();
    }

    string getName(void)
    {
        return this->name;
    }

    int getAge(void)
    {
        return this->age;
    }

    int getInvestment(void)
    {
        return this->investment;
    }
    Date* getDate()
    {
        return this->date;
    }

    double yearlyRate()
    {
        // 5% yearly ~ 0.42% monthly
        // get the months in debt
        int tempMonths = DECEMBER - this->date->getMonth();

        // get the rate for the months in debt
        return tempMonths * MONTHLY_RATE;
    }

    double calculateInterest()
    {
        // calculates how much money is the interest
        // for that period
        return (this->investment*yearlyRate()) / 100;
    }
};

void displayPersonWithHighestInterest(Person* person, int size)
{
    // we set the pointer to point to the first person from the array
    Person* highest_interest_person = person;
    for( int i = 0; i < size; i++ )
    {
        // check if the current person from the array has a higher interest than
        // the current person with the highest interest
        if (person[i].calculateInterest() > highest_interest_person->calculateInterest())
        {
            highest_interest_person = &person[i];
        }
        // display his data
        cout << "Name       : " << person[i].getName()           << endl;
        cout << "Age        : " << person[i].getAge()            << endl;
        cout << "Investment : " << person[i].getInvestment()     << endl;
        cout << "Interest   : " << person[i].calculateInterest() << endl;
    }

    // display his data
    cout << "Name             : " << highest_interest_person->getName()           << endl;
    cout << "Age              : " << highest_interest_person->getAge()            << endl;
    cout << "Day of investment: " << highest_interest_person->getDate()->getDay() << "/" << highest_interest_person->getDate()->getMonth() << "/" << highest_interest_person->getDate()->getYear() << endl;
    cout << "Investment       : " << highest_interest_person->getInvestment()     << endl;
    cout << "Interest         : " << highest_interest_person->calculateInterest() << endl;
}

int main()
{

    Person person[5];

    displayPersonWithHighestInterest(person, 5);

    return 0;
}
