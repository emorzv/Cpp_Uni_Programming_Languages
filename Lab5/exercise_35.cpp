#include <iostream>

using namespace std;

#define SIZE ((int) 5)

template <class T>
class Stack
{
    T stack[SIZE];
    int top;
    int size;

public:
    Stack()
    {
        this->top = -1;
        this->size = SIZE;
    }

    bool isFull()
    {
        return (this->top == (this->size-1));
    }

    bool isEmpty()
    {
        return (this->top == -1);
    }

    void push(T item)
    {
        if( isFull() )
        {
            cout << "stack overflow... cannot push..\n";
            exit (EXIT_FAILURE);
        }
        else
        {
            this->stack[++top] = item;
        }
    }

    T pop()
    {
        if( isEmpty() )
        {
            cout << "empty stack... cannot pop..\n";
            exit (EXIT_FAILURE);
        }
        else
        {
            return this->stack[top--];
        }
    }

    T peek()
    {
        if( isEmpty() )
        {
            cout << "empty stack... cannot peek..\n";
            exit (EXIT_FAILURE);
        }
        else
        {
            return this->stack[top];
        }
    }

    int getNumberOfEntries()
    {
        return (this->size - (this->size - this->top) + 1);
    }
};

int main()
{
    Stack<string> names;
    Stack<int> ints;

    // push 5 names
    names.push("Emo");
    names.push("Rizov");
    names.push("Pepi");
    names.push("Filipov");
    names.push("Rumen");

    // pop name
    cout << "Pop: " << names.pop() << endl;
    cout << "Pop: " << names.pop() << endl;
    cout << "Pop: " << names.pop() << endl;
    cout << "Pop: " << names.pop() << endl;

    // peek name
    string temp = names.peek();
    cout << "Peek:" << temp << endl;

    cout << "Pop: " << names.pop() << endl;

    // get used size
    cout << names.getNumberOfEntries() << endl;

    // try to add 6 ints
    int num1 = 1;
    int num2 = 2;
    int num3 = 3;
    int num4 = 4;
    int num5 = 5;
    int num6 = 6;

    // push int
    ints.push(num1);
    ints.push(num2);
    ints.push(num3);
    ints.push(num4);
    ints.push(num5);
    // this one should throw stack overflow
    // and should not be pushed
    // ints.push(num6);

    // pop int
    int tempInt = ints.pop();
    cout << "Popped int: " << tempInt << endl;

    // peek int
    tempInt = ints.peek();
    cout << "Peeked int: " << tempInt << endl;

    // get used size
    cout << ints.getNumberOfEntries() << endl;

    return 0;
}
