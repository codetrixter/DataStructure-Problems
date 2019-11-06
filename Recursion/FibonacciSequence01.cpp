#include <iostream>

int fib(int element)
{
    if(element == 0)
    {
        return 0;
    } 
    else if(element == 1)
    {
        return 1;
    }
    else
    {
        return fib(element-1) + fib(element-2); 
    }
}

int main(int argc, char const *argv[])
{
    int fibNumber;
    std::cout <<"Enter the numberyou want to see the fibonacci number at :: " << std::endl;
    std::cin >> fibNumber;

    std::cout << fib(fibNumber);

    return 0;
}
