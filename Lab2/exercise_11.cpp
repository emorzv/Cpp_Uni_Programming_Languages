#include <iostream>

using namespace std;

#define NUM_OF_LETTERS ((int) 26)

// the offset of upper to lower case chars in the ascii table
#define DIFFERENCE_LOW_TO_UPP ((int) 32)

class Stack
{
    char lower_case[NUM_OF_LETTERS];
    char upper_case[NUM_OF_LETTERS];

    int upper_buff_size;
    int lower_buff_size;

public:
    Stack()
    {
        // initialize the buffers
        char first_ascii_letter = 'a';
        for( int i = 0; i < NUM_OF_LETTERS; i++ )
        {
            lower_case[i] = first_ascii_letter + i;
            upper_case[i] = (first_ascii_letter + i) - DIFFERENCE_LOW_TO_UPP;
        }

        upper_buff_size = NUM_OF_LETTERS;
        lower_buff_size = NUM_OF_LETTERS;
    }

    void print_lower_case()
    {
        int temp_count = 1;
        cout << endl << "==LOWER LETTERS==" << endl;
        for( int i = 0; i < NUM_OF_LETTERS; i++ )
        {
            if ((temp_count%6) == 0) // after every forth letter, a new row will be added
            {
                cout << this->lower_case[i] << endl;
            }
            else
            {
                cout << this->lower_case[i] << " ";
            }
            temp_count++;
        }
        cout << endl << "=================" << endl;
    }

    void print_upper_case()
    {
        int temp_count = 1;
        cout << endl << "==UPPER LETTERS==" << endl;
        for( int i = 0; i < NUM_OF_LETTERS; i++ )
        {
            if ((temp_count%6) == 0) // after every forth letter, a new row will be added
            {
                cout << this->upper_case[i] << endl;
            }
            else
            {
                cout << this->upper_case[i] << " ";
            }
            temp_count++;
        }
        cout << endl << "=================" << endl;
    }

    bool is_empty(int size)
    {
        if( size >= 0 ) // >= 0 because it is zero based indexing
        {
            return false;
        }

        return true;
    }

    char pop_upper()
    {
        // if not empty - pop
        if( !is_empty(this->upper_buff_size) )
        {
            return upper_case[--this->upper_buff_size];
        }
        else
        {
            return ' ';
        }
    }

    char pop_lower()
    {
        // if not empty - pop
        if( !is_empty(this->lower_buff_size) )
        {
            return lower_case[--this->lower_buff_size];
        }
        else
        {
            return ' ';
        }
    }
};

int main()
{
    Stack stack;

    stack.print_upper_case();
    stack.print_lower_case();

    // pop upper
    for( int i = 0; i < NUM_OF_LETTERS; i++ )
    {
        cout << stack.pop_upper() << " ";
    }
    cout << endl;

    // pop lower
    for( int i = 0; i < NUM_OF_LETTERS; i++ )
    {
        cout << stack.pop_lower() << " ";
    }

    return 0;
}
