#include <iostream>

int computeAckk(int n, int m)
{
    if(n == 0)
    {
        return m+1;
    }
    else if(m == 0 && n > 0)
    {
        std::cout << "computeAckk(" << n-1 << ", " << 1 << ")" << std::endl; 
        return computeAckk(n-1, 1);
    }
    else
    {
        std::cout << "computeAckk(" << n-1 << ", " << "computeAckk(" << n << ", " << m-1 << ")" << std::endl;
        return computeAckk(n-1, computeAckk(n, m-1));
    }
}

int main(int argc, char const *argv[])
{
    int n = 0, m = 0;

    std::cout << "Enter the values of n and m:: " << std::endl;
    std::cin >> n >> m;

    std::cout << computeAckk(n, m);

    return 0;
}
