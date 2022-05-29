#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

#define MAX_PEOPLE      ((int) 5)
#define MAX_ADDRESSES   ((int) 5)

// base class
class Person
{
    char* name;
    char* egn;
    char* address;

public:
    Person()
    {
        this->name = new char[30]; // first and last name
        this->egn = new char[11]; // 10 + 1 for the \0
        this->address = new char[60]; // just in case

        cout << "========================================================" << endl;
        cout << "Name: "; cin.getline(this->name, 30, '\n');
        cout << "Egn : "; cin.getline(this->egn, 11, '\n');
        cout << "Living address: "; cin.getline(this->address, 60, '\n');
        cout << "--------------------------------------------------------" << endl;
    }

    ~Person()
    {
        delete[] this->name;
        delete[] this->egn;
        delete[] this->address;
    }

    char* getName()
    {
        return this->name;
    }
    char* getEgn()
    {
        return this->egn;
    }
    char* getAddress()
    {
        return this->address;
    }
};

// derived class
class Addresses : public Person
{
    char** addrs;

    // keeps track of the number of rows (because we're using pointers)
    int rows;

public:
    Addresses() : Person()
    {
        int tempNumberOfProperties;

        do
        {
            cout << "Number of properties(max 5): "; cin >> tempNumberOfProperties;
            cin.ignore();

        } while (tempNumberOfProperties > MAX_ADDRESSES);

        this->addrs = (char**) malloc(sizeof(char*) * tempNumberOfProperties);

        for( int j = 0; j < tempNumberOfProperties; j++ )
        {
            this->addrs[j] = new char[60];
            cout << "Property address: "; cin.getline(this->addrs[j], 60, '\n');
        }
        cout << "========================================================" << endl;

        this->rows = tempNumberOfProperties;
    }

    ~Addresses()
    {
        // deallocate each row (columns dimension)
        for( int i = 0; i < this->rows; i++ )
        {
            delete[] this->addrs[i];
        }

        // deallocate the rows (rows dimension)
        delete[] this->addrs;
    }

    // returns the whole two-dimensional array (the array of addresses)
    char** getAddresses()
    {
        return addrs;
    }

    int getNumberOfProperties()
    {
        return this->rows;
    }

    friend ostream& operator << (ostream& os, Addresses* ppl);
};

// ====================================================================================
// operator overload function
//
// - first one is to display property addresses
// - second one is to display the full information about the person
// ====================================================================================

ostream& operator << (ostream& os, Addresses& ppl)
{
    os << endl << "=========================================" << endl;
    os <<         "Name           : " << ppl.getName()     << endl;
    os <<         "Egn            : " << ppl.getEgn()      << endl;
    os <<         "Living address : " << ppl.getAddress()  << endl;
    os <<         "-----------------------------------------" << endl;

    // display each person's property addresses
    char** propertyAddresses = ppl.getAddresses();

    // loop through the addresses
    for( int i = 0; i < ppl.getNumberOfProperties(); i++ )
    {
        os << "Address " << i << ": " << propertyAddresses[i] << endl;
    }

    return os;
}

// ====================================================================================
// display functions
//
// - displayMatching() - display people with matching living and one property address
// - displayByEgn(char* egn) - display a person's properties by a given EGN
// ====================================================================================

void displayMatching(Addresses* people, int size)
{
    // loop through all the people in the array
    for( int i = 0; i < size; i++ )
    {
        // current person's property addresses
        char** propertyAddresses = people[i].getAddresses();

        // current person's living address
        char* livingAddress = people[i].getAddress();

        // get the number of properties for the current person
        int numberOfProperties = people[i].getNumberOfProperties();

        // loop through each person's property addresses
        for( int j = 0; j < numberOfProperties; j++ )
        {
            // check if current property address matches the living one
            if( (strcmp(livingAddress, *(propertyAddresses + j))) == 0 )
            {
                // display the info (pass in pointers)
                cout << people[i];
                break;
            }
        }
    }
}

void displayByEgn(Addresses* people, int size, char* egn)
{
    // loop through all people
    for( int i = 0; i < size; i++ )
    {
        // check for a match in the egn
        if( (strcmp(people[i].getEgn(), egn)) == 0 )
        {
            // person's property addresses
            char** propertyAddresses = people[i].getAddresses();

            // get the number of properties for the current person
            int numberOfProperties = people[i].getNumberOfProperties();

            // loop through the addresses
            cout << endl << "====================================================" << endl;
            cout << people[i].getName() << "'s addresses with EGN " << people[i].getEgn() << endl;
            cout << "----------------------------------------------------" << endl;

            for( int i = 0; i < numberOfProperties; i++ )
            {
                cout << "Address " << i << ": " << propertyAddresses[i] << endl;
            }
            cout << "====================================================" << endl;

            // egns are unique. No other person will have the same => no need to keep looping
            break;
        }
    }
}

// ====================================================================================
// file functions
//
// - writeToFile(Addresses* people, int numberOfPeople) - opens a file and writes the
//                                                        information for each person
// ====================================================================================

void writeToFile(Addresses* people, int numberOfPeople)
{
    // create the file object
    ofstream fout;

    // open the file (if it does not exists it gets created)
    // (the file is in the .cpp file's directory - we can pass just the name of the file)
    fout.open("people.txt");

    // check if the file opened correctly
    if( fout.is_open() )
    {
        // write each person to the file
        for( int i = 0; i < numberOfPeople; i++ )
        {
            fout << people[i];
        }

        // close the file
        fout.close();
    }
    else
    {
        cout << "could not open the file...\n";
    }
}

int main()
{
    int numberOfPeople;
    do
    {
        cout << "Number of people(max 5): ";
        cin >> numberOfPeople;
        cin.ignore();
    } while( numberOfPeople > MAX_PEOPLE );

    // create the people
    Addresses people[numberOfPeople];

    // print the people's info
    for( int i = 0; i < numberOfPeople; i++ )
    {
        cout << people[i];
    }

    // functions
    displayMatching(people, numberOfPeople);

    char egnToCompare[] = "1231231231";
    displayByEgn(people, numberOfPeople, egnToCompare);


    // store the info for each person in a txt file
    writeToFile(people, numberOfPeople);

    return 0;
}
