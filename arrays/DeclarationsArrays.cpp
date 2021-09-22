#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int A[] = {2, 4, 6, 8, 0};

    for(int i = 0; i < 5; i++)
    {
        printf("%d", A[2]);
        printf("%d", 2[A]);
        printf("%d", *(A+2));
    }
    return 0;
}

