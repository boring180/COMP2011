#include <iostream> 	/* File: toh-main.cpp */	
using namespace std;	
void tabs(int tabs){
    for(int i=0;i<tabs;i++) cout<<'\t';
}

void tower_of_hanoi(int disknum, char pegA, char pegB, char pegC,int lit)
{    
    if(disknum == 0)return;
    tabs(lit);cout<<"Enter iteration "<<lit<<endl;
    tower_of_hanoi(disknum - 1,pegA,pegC,pegB,lit+1);
       tabs(lit);cout<<"Move disk "<<disknum<<" from  "<<pegA<<" to "<<pegC<<endl;
    tower_of_hanoi(disknum - 1,pegB,pegA,pegC,lit+1);
}

int main()	
{
    int n;

    while (cin >> n)
    	tower_of_hanoi(n, 'A', 'B', 'C',0);
    return 0;
}
//NP