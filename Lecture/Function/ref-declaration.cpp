#include <iostream>     /* File: ref-declaration.cpp */
using namespace std;

int main()
{
    int a = 1, b = 2;
    int& x = a;         // now x = a = 1
    int &y = b;         // now y = b = 2
    int &w = a, &z = y; // now w = a = x = 1, z = b = y = 2

    a++;     cout << a << '\t' << x << '\t' << w << endl; // a = 2 2 2 2 
    x += 5;  cout << a << '\t' << x << '\t' << w << endl; // a = 7 7 7 7
    a = w - x; cout << a << '\t' << x << '\t' << w << endl; //a = 0 0 0 0

    y *= 10; cout << b << '\t' << y << '\t' << z << endl; // y = b = 20 20 20 20
    b--;     cout << b << '\t' << y << '\t' << z << endl; // b =  19 19 19 19
    z = 999; cout << b << '\t' << y << '\t' << z << endl; // z = b = 999 999 999 999

    z = a;              // that is not re-binding z to a
    cout << b << '\t' << y << '\t' << z << endl;  //0 0 0 
    return 0;
}
