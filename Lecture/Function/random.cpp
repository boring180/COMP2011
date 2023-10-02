#include <iostream>
#include <stdlib.h>
using namespace std;

int seed = 8;

int main()
{
    srand(seed);
    cout<<rand() % 100<<endl;
    cout<<rand() % 100<<endl;
}