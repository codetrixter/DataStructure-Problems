#include <stdio.h>
#include <stdlib.h> //for malloc 

int main() 
{
    int A[5] = {1, 2, 3, 4, 5};     // allocating memory of array in stack
    int *p;

    p = new int[5];     //c++ way of allocating heap memory
    //p = (int *)malloc(5*(sizeof(int))); // c way of allocating memory of array in heap
    p[0] = 10;
    for(int i = 0; i < 5; i++)
    {
        printf("%d", p[i]);
    }
    return 0;
}