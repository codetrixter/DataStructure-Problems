/**
* program to convert and expression from infix to postfix.
*
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <cstring>
#include <iterator>
#include <cmath>

int checkPrecedance(char ch)
{
    if(ch == '^')
        return 3;
    else if(ch == '*' || ch == '/')
        return 2;
    else
        return 1;
}

bool isDigit(char element)
{
    if(element >= 48 && element <= 57)
        return true;
    else
        return false;
}

bool isAlpha(char element)
{
    if((element >= 65 && element <= 90) || (element >= 97 && element <= 122))
        return true;
    else
        return false;
}

bool isOperator(char element)
{
    if(element == '^' || element == '*' || element == '+' || element == '/' || element == '-')
        return true;
    else
        return false;
}
int main()
{
    std::vector<char> printstack;
    std::string expression;
    char token;

    std::cout << "please enter the expression which you want to be seen as evaluated::" << std::endl;

    std::getline(std::cin, expression);
    std::istringstream iss(expression);

    while( iss >> token)
    {
        printstack.push_back(token);
    }

    //Evaluating expression printStack.
    std::stack<int> evaluationStack;
    for(int i = 0; i < printstack.size(); i++)
    {
        int operation = 0;
        if(isDigit(printstack[i]))
        {
            evaluationStack.push(printstack[i] - '0');
        }
        else if(isOperator(printstack[i]))
        {
            int tempA = evaluationStack.top();
            evaluationStack.pop();
            int tempB = evaluationStack.top();
            evaluationStack.pop();
            switch(printstack[i])
            {
                case '^':
                {
                    operation = pow(tempB, tempA);
                }
                break;
                case '*':
                {
                    operation = tempB * tempA;
                }
                break;
                case '/':
                {
                    operation = tempB / tempA;
                }
                break;
                case '-':
                {
                    operation = tempB - tempA;
                }
                break;
                case '+':
                {
                    operation = tempB + tempA;
                }
                break;
                default:
                std::cout << "incorrect opearator...";
            }
            evaluationStack.push(operation);
        }
    }

    std::cout << evaluationStack.top();


    // for(char c: tokenVec)
    // {
    //     std::cout << c << std::endl;
    // }
    //
    // std::cout << tokenVec.size() << std::endl;

}
