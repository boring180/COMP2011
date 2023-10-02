//This is fromP6 of 17F MT

#include <iostream>
using namespace std;

void hat(int height)
{
    for(int i = 1; i <= height - 1;i++)cout<<'#';
    cout<<'*';
    for(int i = 1; i <= height - 1;i++)cout<<'#';
    cout<<endl;
    for(int row = 2;row <= height;row++)
    {
        for(int i = 1;i <= height - row;i++)cout<<'#';
        cout<<'*';
        for(int i = 1;i <= 2 * row - 3;i++)cout<<'#';
        cout<<'*';
        for(int i = 1;i <= height - row;i++)cout<<'#';
        cout<<endl;
    }
}

int main()
{   
    int height;
    cin>>height;
    hat(height);
}