/**
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * An input string is valid if:
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Note that an empty string is also considered valid.
 */

#include <iostream>
#include <string>
#include <stack>

bool isOpenning(char ch)
{
    if((ch == '(') || (ch == '{') || (ch == '['))
        return true;
    else
        return false;
}

bool isClosed(char ch)
{
    if((ch == ')') || (ch == '}') || (ch == ']'))
        return true;
    else
        return false;
}

bool isValid(std::string str)
{
    std::stack<char> validateString;
    bool stillValid = false;

    //checking for base conditions
    if(((str.length()%2) != 0) || isClosed(str[0]))
    {
        //std::cout << str.length();
        return false;
    }

    for(int i = 0; i < str.length(); i++)
    {
        if(isOpenning(str[i]))
        {
            //std::cout << str[i];
            validateString.push(str[i]);
        }
        else
        {
            if(isClosed(str[i]) && ((str[i] == ')' && validateString.top() == '(')) || ((str[i] == ']' && validateString.top() == '[')) || 
            ((str[i] == '}' && validateString.top() == '{')))
            {
                //std::cout << str[i];
                validateString.pop();
            }
            else
            {
                stillValid = false;
                break;
            }
        } 
    }
    if(validateString.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, char const *argv[])
{
    // std::cout << 
    std::cout << isValid("([)[]{})");
    return 0;
}


