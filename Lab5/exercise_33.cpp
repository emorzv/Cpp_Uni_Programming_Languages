#include <iostream>
#include <string>

using namespace std;

template <class T>
T compare(T var1, T var2)
{
    return var1 > var2 ? var1 : var2;
}

int main()
{
    int one = 5;
    int two = 7;

    double dOne = 16.489;
    double dTwo = 13.429;

    char cOne = 'b';
    char cTwo = 'o';

    string sOne = "emiliyan";
    string sTwo = "rizov";

    cout << compare(one, two) << endl;
    cout << compare(dOne, dTwo) << endl;
    cout << compare(cOne, cTwo) << endl;
    cout << compare(sOne, sTwo) << endl;

    return 0;
}
