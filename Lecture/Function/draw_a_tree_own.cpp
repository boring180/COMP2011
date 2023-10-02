#include <iostream>
using namespace std;

int max(int number1,int number2)
{
    return (number1 > number2) ? number1 : number2;
}

void draw_line(int space,int object)
{   
    char symbol = '*';
    for(int i = 1;i <= space;i++)cout<<' ';
    for(int i = 1;i <= object;i++)cout<<symbol;
    cout <<endl;
}

void draw_trunk(int leaves_height,int trunk_radius)
{
    for(int i = 1;i <= 4;i++)draw_line(leaves_height - trunk_radius + 3,2 * trunk_radius + 1);
}

void draw_pot(int leaves_height)
{
    for(int i = 1;i <= 3;i++)draw_line(leaves_height + i - 2 , 11 - 2 * i);
}

void draw_leaves(int leaves_height)
{
    for(int i = 1;i <= leaves_height;i++)draw_line(leaves_height-i+4,2 * i-1);
}


void assign(int leaves_height)
{
    draw_leaves(leaves_height);
    int trunk_radius = max(1,(leaves_height - leaves_height % 3) / 3); // Try to remove this part later
    draw_trunk(leaves_height,trunk_radius);
    draw_pot(leaves_height);
}

int main()
{
    int height;
    cout << "Please input your desired height:";
    cin >> height;
    assign(height);
    return 0;
}
