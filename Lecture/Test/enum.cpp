#include <iostream>
using namespace::std;
//This is a code for verifying the 16F midterm paper

enum DAYS {MON = 1 ,TUE,WED,THUR,FRI,SAT,SUN};

void weekdatSwitchCase(DAYS day)
{
    switch(day)
    {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        cout<<"This is a weekday"<<endl;break;
        case 6:
        case 7:
        cout<<"This si a weekend"<<endl;break;
        default:
        cout<<"Nor a legal day"<<endl;
    }
}

int main()
{
    weekdatSwitchCase(MON);
}