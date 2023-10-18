//This is Q8 of 17F MT
#include <iostream>
using namespace::std;

int array_max(const int line[],int c)
{
    if(c == 0)return line[c];
    else return (array_max(line,c-1)>line[c])?(array_max(line,c-1)):line[c];
}

int main()
{
    const int M = 10, N = 8;
    int x[N] = { 10,7,4,6,4,2,5,7};
    //int y[M][N] = { /* assume proper initialization */ };
    cout << array_max(x, 5) << endl;
    //cout << matrix_max(y, 9, 7) << endl;
}