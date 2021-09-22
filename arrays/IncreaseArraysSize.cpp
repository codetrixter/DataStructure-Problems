/**
 * The reason why the array size cannot be resized is due to the fact the array is contiguous in nature and we dont know what 
 * memory location is occupying just after the array ends in stack or heap.
 */

#include <stdio.h>
#include <cstdlib>

int main() 
{
    int *P = new int[5];
    P[0] = 1;
    P[1] = 2;
    P[2] = 3;
    P[3] = 4;
    P[4] = 5;

    int *Q = new int[10];

    for(int i = 0; i < 5; i ++)
    {
        Q[i] = P[i];
    }

    free(P);
    P = Q;
    Q = NULL;

    return 0;
}