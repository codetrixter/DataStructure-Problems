/**
 * This problem is resolved by dividing the problem into smaller subset of problems and then solving those smaller problems,
 *  which ultimately solves the original bigger problem.
 */

#include <iostream>

void Hanoi(int pegs, char from, char to, char spare)
{
    if(pegs == 1)
    {
        std::cout << "Move peg :: " << from << " to :: " << to << " Leaving out :: " << spare << std::endl;
        return;
    }
    else
    {
        Hanoi(pegs-1, from, spare, to);
        Hanoi(1, from, to, spare);
        Hanoi(pegs-1, spare, to, from);
    }
}

int main(int argc, char const *argv[])
{
    int initialTotalPegs = 0;
    std::cout << "Enter the Total pegs for Towers of Hanoi problem:: " << std::endl;
    std::cin >> initialTotalPegs;

    Hanoi(initialTotalPegs, 'A', 'C', 'B');

    return 0;
}
