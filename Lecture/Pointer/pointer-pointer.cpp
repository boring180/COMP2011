#include <iostream>     /* File: pointer-pointer.cpp */
using namespace std;	
    
int main()	
{
    int x = 16;
    int* xp = &x;       // xp --> x
    int** xpp = &xp;    // xpp --> xp --> x
    int*** xppp = &xpp; // xppp --> xpp --> xp --> x

    cout << "x address    = " << &x   << "  x    = " << x << endl; //Address of x;16
    cout << "xp address   = " << &xp  << "  xp   = " << xp //The address of xp;The address of x;16
         << "  *xp   = "      << *xp  << endl; 

    cout << "xpp address  = " << &xpp << "  xpp  = " << xpp 
         << "  *xpp  = "      << *xpp << "  **xpp  = " << **xpp << endl;  //The address of xpp;The address of xp;the address of x;16

    cout << "xppp address = " << &xppp   << "  xppp = " << xppp 
         << "  *xppp = "      << *xppp   << "  **xppp = " << **xppp//The address of xppp;the address of xpp;the address of xp;the adress of x;16
         << "  ***xppp = "    << ***xppp << endl; 
    return 0;
}
