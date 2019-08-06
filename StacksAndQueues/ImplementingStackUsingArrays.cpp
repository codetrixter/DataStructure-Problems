#include <iostream>
#define MAX 1000

class Stacking
{
private:
    int top = -1;

public:
    void push(int arr[], int item)
    {
        if(top == MAX)
        {
            std::cout << "Overflow" << std::endl;
        }
        top += 1;
        arr[top] = item; 
    }

    void pop(int arr[])
    {
        if(top == -1)
        {
            std::cout << "Underflow" << std::endl;
        }

        top -= 1;
    }

    void printStack(int arr[])
    {
        //Range based loops can only be used when we know the size of the array.
        if(top == -1)
        {
            std::cout << "stack is empty... nothing to print..." << std::endl;
            return;
        }
        for(int ind = top; ind >= 0; --ind)
        {
            std::cout << arr[ind] << std::endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    int options, element = 0;
    int stackArray[MAX];
    Stacking *st = new Stacking();
    do
    {
        std::cout << "Please select the following options to perform the respective actions on Stack implemented with array..." << std::endl;
        std::cout << "1: push an Element into the stack" << std::endl;
        std::cout << "2: pop an Element from the stack" << std::endl;
        std::cout << "3: Print the stack" << std::endl;
        std::cout << "0: Exit" << std::endl;
        std::cin >> options;

        switch (options)
        {
        case 1:
            std::cin >> element;
            st->push(stackArray, element);
            std::cout << "pushed...." << std::endl;
            break;
        case 2:
            st->pop(stackArray);
            std::cout << "popped..." << std::endl;
            break;
        case 3:
            st->printStack(stackArray);
            std::cout << std::endl;
            break;
        case 0:
            std::cout << "O Entered.... exiting..." << std::endl;
            std::exit(0);
        default:
            std::cout << "Invalid entry" << std::endl;
        }
    } while (options != 0);

    return 0;
}
