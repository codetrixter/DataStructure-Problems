/**
 * @file listAM.cpp
 * @author Abhishek
 * @brief header of my version of stl lists, this is the first iteration, 
 * it will be updated as the understanding grows better.
 * @version 0.1
 * @date 2022-05-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

class listAM
{
    public:

    listAM(int *data);

    private:
    struct Node
    {
        int data;
        Node *next;
    }
    
};