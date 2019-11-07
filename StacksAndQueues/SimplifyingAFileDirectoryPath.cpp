/**
 * Given an absolute path, simplify it.
 * example::
 * "/a/./"   --> means stay at the current directory 'a'
 * "/a/b/.." --> means jump to the parent directory
 *             from 'b' to 'a'
 * "////"    --> consecutive multiple '/' are a  valid  
              path, they are equivalent to single "/".
*/

#include <iostream>
#include <stack>
#include <string>
#include <iterator>
#include <vector>

bool isAlpha(char element)
{
    if((element >= 65 && element <= 90) || (element >= 97 && element <= 122))
        return true;
    else
        return false;
}

std::stack<char> simplify(std::vector<char> absolutePath)
{
    std::stack<char> evaluate;
    int count = 0;
    evaluate.push('/');

    for(char c: absolutePath)
    {
        if(isAlpha(c))
        {
            evaluate.push(c);
            count = 0;
        }
        else if(c == '/')
        {
            if(evaluate.top() != '/')
            {
                evaluate.push(c);
            }
        }
        else if(c == '.')
        {
            if(count > 0)
            {
                if(evaluate.size() > 1)
                {
                    evaluate.pop();     //removing forward slash.
                    evaluate.pop();     //removing the directory name.
                    count = 0;
                }
            }
            else
            {
                count += 1;
            }
        }
    }
    if(evaluate.top() == '/' && evaluate.size() != 1)
        evaluate.pop();             //rmoving the last froward slash '/'.
    return evaluate;
}

void printStack(std::stack<char> directoryPath)
{
    if(directoryPath.empty())
    {
        return;
    }
    else
    {
        char temp = directoryPath.top();
        directoryPath.pop();
        printStack(directoryPath);

        std::cout << temp;
    }
}

int main(int argc, char const *argv[])
{
    std::string path = "";
    std::stack<char> result;

    std::cout << "Enter an Absolute path that you want to simplify:: " <<std::endl;
    std::cin >> path;
    std::vector<char> vec(path.begin(), path.end());
    
    result = simplify(vec);

    printStack(result);

    return 0;
}
