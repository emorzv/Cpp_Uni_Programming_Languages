#include <iostream>
#include "CustomScopedArray.h"

using std::cout;
using std::endl;
using std::string;

CustomScopedArray::CustomScopedArray(int size)
{
    /* Out of bounds check */
    if (size < 0) { exit(1); }

    this->size = size;
    arr = new int[size];
    cout << "Custom array constructed\n";
}

CustomScopedArray::~CustomScopedArray()
{
    delete[]arr;
    cout << "Custom array destructed\n";
}

int& CustomScopedArray::SetAt(int index)
{
    /* Out of bounds check */
    if ((index >= this->size) || (index < 0))
    {
        exit(1);
    }

    return arr[index];
}

int CustomScopedArray::GetAt(int index)
{
    /* Out of bounds check */
    if ((index >= this->size) || (index < 0))
    {
        exit(1);
    }

    return arr[index];
}

int CustomScopedArray::GetSize()
{
    return this->size;
}

void InitArray(CustomScopedArray& arr);
void PrintArray(CustomScopedArray& arr);

int main()
{
    {
        CustomScopedArray arr(10);

        cout << arr.GetSize() << endl;

        /* Init the whole array */
        InitArray(arr);

        /* Print the whole array */
        PrintArray(arr);
    }

    cout << "Array destructed at this point\n";

    return 0;
}

void InitArray(CustomScopedArray& arr)
{
    for (int i = 0; i < arr.GetSize(); i++)
    {
        arr.SetAt(i) = i + 1;
    }
}

void PrintArray(CustomScopedArray& arr)
{
    for (int i = 0; i < arr.GetSize(); i++)
    {
        cout << arr.GetAt(i) << " ";
    }
    cout << endl;
}

/* 
    TODO:
        - Possibly do operator overloading for initializing the whole array at the construction?
*/