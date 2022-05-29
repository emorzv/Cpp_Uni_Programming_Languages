#include <iostream>

using namespace std;

template <class T>
bool match(T* arr, int size, T key_value)
{
    bool result = false;

    // loop through the array
    for( int i = 0; i < size; i++ )
    {
        // if a match is found return true and break
        if( arr[i] == key_value )
        {
            result = true;
            break;
        }
    }

    return result;
}

template <class T>
void display(T* arr, int size, T key_value)
{
    if( match(arr, size, key_value) == true )
    {
        cout << "There is a match in the array!" << endl;
    }
    else
    {
        cout << "No match in the array!" << endl;
    }
}

int main()
{
    int arr_int[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    double arr_double[] = { 1.2, 2.5, 3.34, 4.76, 5.123, 6.7, 7.98, 8.12, 9.2, 11.87, 4.5 };
    char arr_char[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'q' };

    display(arr_int, (int) (sizeof(arr_int)/sizeof(*arr_int)), 18);
    display(arr_double, (int) (sizeof(arr_double)/sizeof(*arr_double)), 4.5);
    display(arr_char, (int) (sizeof(arr_char)/sizeof(*arr_char)), 'q');

    // finish this one

    return 0;
}
