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

int checkPrecedance(char ch)
{
    if(ch == '^')
        return 3;
    else if(ch == '*' || ch == '/')
        return 2;
    else
        return 1;
}

int main()
{
    std::vector<char> tokenVec;
    std::string expression;
    std::stack<char> postfixExpression;
    char token;

    std::cout << "please enter the expression which you want to be seen as converted::" << std::endl;

    std::getline(std::cin, expression);
    std::istringstream iss(expression);

    //inserting ( before every expression.
    tokenVec.push_back('(');
    while( iss >> token)
    {
        tokenVec.push_back(token);
    }
    //inserting ) in the end of every expression.
    tokenVec.push_back(')');

    std::stack<char> eval;

    for(int i = 0; i < tokenVec.size(); i++)
    {
        if(tokenVec[i] == '(' )
        {
            eval.push(tokenVec[i]);
        }
        if(tokenVec[i] == '^' || tokenVec[i] == '*' || tokenVec[i] == '+' || tokenVec[i] == '/' || tokenVec[i] == '-')
        {
            if(eval.top() != '(' && checkPrecedance(eval.top()) > checkPrecedance(tokenVec[i]))
            {
                postfixExpression.push(eval.top());
                eval.pop();
                eval.push(tokenVec[i]);
            }
            else //if(eval.top() == '(')
            {
                eval.push(tokenVec[i]);
            }
        }
        if((tokenVec[i] >= 65 && tokenVec[i] <= 90) || (tokenVec[i] >= 97 && tokenVec[i] <= 122) || (tokenVec[i] >= 48 && tokenVec[i] <= 57))
        {
            postfixExpression.push(tokenVec[i]);
        }
        if(tokenVec[i] == ')')
        {
            while(eval.top() != '(')
            {
                postfixExpression.push(eval.top());
                eval.pop();
            }
            eval.pop();
        }
    }

    std::vector<char> printstack;
    while (postfixExpression.size() != 0)
    {
        printstack.push_back(postfixExpression.top());
        postfixExpression.pop();
    }

    std::vector<char>::reverse_iterator itr;

    for(itr = printstack.rbegin(); itr != printstack.rend(); itr++)
    {
        std::cout << *itr;
    }

    // for(char c: tokenVec)
    // {
    //     std::cout << c << std::endl;
    // }
    //
    // std::cout << tokenVec.size() << std::endl;

}
