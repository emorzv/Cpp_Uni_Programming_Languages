#include <iostream>
#include <cstring>

using namespace std;

#define ARR_SIZE ((int) 10)

class A
{
    int arr[ARR_SIZE];

public:
    A()
    {
        // input
        cout << "Type in " << ARR_SIZE << " numbers!\n";
        for( int i = 0; i < ARR_SIZE; i++ )
        {
            cin >> arr[i];
        }
    }

    A& operator += (const A& rhs)
    {
        // loop through each element from both arrays and add them
        for( int i = 0; i < ARR_SIZE; i++ )
        {
            this->arr[i] += rhs.arr[i];
        }

        return *this;
    }

    A& operator -= (const A& rhs)
    {
        // loop through each element from both arrays and subtract them
        for( int i = 0; i < ARR_SIZE; i++ )
        {
            this->arr[i] -= rhs.arr[i];
        }

        return *this;
    }

    int* getArr()
    {
        return this->arr;
    }
};

int main()
{
    // create two objects
    A obj_a;
    A obj_b;

    // add their inner arrays
    obj_a += obj_b;
    // print the array of obj_a
    for( int i = 0; i < ARR_SIZE; i++ )
    {
        cout << obj_a.getArr()[i] << " ";
    }

    cout << endl;

    // subtract their inner arrays
    obj_b -= obj_a;
    // print the array of obj_b
    for( int i = 0; i < ARR_SIZE; i++ )
    {
        cout << obj_b.getArr()[i] << " ";
    }

    return 0;
}
