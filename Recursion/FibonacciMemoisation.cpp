#include <bits/stdc++.h>

using namespace std;

int fib(int n)
{
    static vector<int> localStorage(n, -1) ;
   
    if(n <= 1)
    {
        localStorage[n] = n;
        return n;
    }
    else 
    {
        if(localStorage[n-2] == -1)
        {
            localStorage[n-2] = fib(n-2);
        }
        if(localStorage[n-1] == -1)
        {
            localStorage[n-1] = fib(n-1);
        }
        return (localStorage[n-2] + localStorage[n-1]);
    }
}

int main(int argc, char const *argv[])
{
    cout << fib(6);
    return 0;
}
