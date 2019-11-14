#include <iostream>
#define THRESHOLD 100

void incrementTheNumber(int, int);

void printTheNumber(int n, int threshold)
{
    std::cout << n << " ";

    incrementTheNumber(n, threshold);
}

void incrementTheNumber(int n, int threshold)
{
    n++;
    if(n <= threshold)
    {
        printTheNumber(n, threshold);
    }
}

int main(int argc, char const *argv[])
{
    int number = 1;

    printTheNumber(number, THRESHOLD);
    return 0;
}
