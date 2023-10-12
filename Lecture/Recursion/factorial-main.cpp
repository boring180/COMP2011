#include <iostream>	/* File: factorial-main.cpp */ //Written by BX
using namespace std;	

int factorial(int x)
{
    if(x < 0)return -1;
    if(x == 0)return 1;
    else return x * factorial(x-1);
}

int main()	
{
    int x;
    int result;

    while (cin >> x)
    {
        result = factorial(x);
        if (result < 0)
            cout << "Input must be >= 0" << endl;
        else
            cout << "factorial(" << x << ") = " << result << endl;
    }
    
    
    return 0;
}

//NP