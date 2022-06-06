#include <iostream>
#include "CustomScopedArray.h"


template <typename T>
void InitArray(CustomScopedArray<T>& arr);
template <typename T>
void PrintArray(CustomScopedArray<T>& arr);

int main()
{
    {
        CustomScopedArray<string> arr(5);

        cout << arr.GetSize() << endl;

        /* Init the whole array */
        // InitArray(arr);
        arr.SetAt(4) = "kef";
        arr.SetAt(3) = "emo";
        arr.SetAt(2) = "e";
        arr.SetAt(1) = "mnogo";
        arr.SetAt(0) = "gotin";

        /* Print the whole array */
        PrintArray(arr);
    }

    cout << "Array destructed at this point\n";

    return 0;
}

template <typename T>
void InitArray(CustomScopedArray<T>& arr)
{
    for (int i = 0; i < arr.GetSize(); i++)
    {
        arr.SetAt(i) = i + 1;
    }
}

template <typename T>
void PrintArray(CustomScopedArray<T>& arr)
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