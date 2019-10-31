#include <iostream>

int factorial(int factor)
{
    if(factor == 0)
    {
        factor = 1;
        return factor;
    }

    factor = factor * factorial(factor-1);

    return factor;
}

int main()
{
    int number = 0;
    std::cout << "Enter a number for which you find the factorial of::" << std::endl;
    std::cin >> number;

    int result = factorial(number);

    std::cout << "Factorial of "<< number << " is ::" << result << std::endl;
    return 0;
}
