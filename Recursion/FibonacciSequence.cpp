#include <iostream>

int fibonacci(int number, int f1 = 0, int f2 = 1)
{
    int result = 0;
    if(number != 0)
    {
        result = f1 +f2;
        f1 = f2;
        f2 = result;
        std::cout << " " << result;
        fibonacci(number-1, f1, f2);
    }
    return result;
}

int main()
{
    int number= 0;
    std::cout << "Enter the amount of fibonacci numbers you want to generate ::" << std::endl;
    std::cin >> number;
    std::cout << "0 1";
    fibonacci(number, 0, 1);
    return 0;
}
