/**
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, 
 * compute how much water it is able to trap after raining.
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 */

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

int trapRain(std::vector<int> height)
{
    std::vector<int> leftWall, rightWall;
    int max = 0, waterCollected = 0;

    for(int i = 0; i < height.size(); i++)
    {
        if(leftWall.empty())
        {
            leftWall.push_back(0);
        }
        else
        {
            if(height.at(i-1) > max)
            {
                max = height.at(i-1);
                leftWall.push_back(max);
            }
            else
            {
                leftWall.push_back(max);
            }
        }
    }

    max = 0;
    for(int i = height.size()-1; i >= 0; i--)
    {
        if(rightWall.empty())
        {
            rightWall.push_back(0);
        }
        else
        {
            if(height.at(i+1) > max)
            {
                max = height.at(i+1);
                rightWall.push_back(max);
            }
            else
            {
                rightWall.push_back(max);
            }
        }
    }

    std::reverse(rightWall.begin(), rightWall.end());

    for(int i = 0; i < height.size(); i++)
    {
        int tempWater = std::min(leftWall.at(i), rightWall.at(i)) - height.at(i);
        if(tempWater >= 0)
        {
            waterCollected += tempWater;
        }
    }

    return waterCollected;
}

int main(int argc, char const *argv[])
{
    std::vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    std::cout << trapRain(height);
    return 0;
}
