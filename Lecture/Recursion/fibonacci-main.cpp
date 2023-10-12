#include <iostream>		/* File: fibonacci-main.cpp */
using namespace std;	

void tabs(int tabs){
    for(int i=0;i<tabs;i++) cout<<'\t';
}

int fibonacci(int n,int depth)
{   
    if(n  == 1)return 1;
    if(n  == 0)return 0;
    tabs(depth);cout<<"depth: "<<depth<<" called!"<<endl;
    n = fibonacci(n-1,depth+1) + fibonacci(n - 2,depth+1);
    tabs(depth);cout<<"The amount of depth"<<depth<<"is:"<<n<<endl;
    return n;
}

int main()	
{
    int n;

    while (cin >> n)
    {
        int amount = fibonacci(n,0);
	    cout << "fibonacci(" << n << ") = " 
	     << amount << endl;
	
    }
    return 0;
}
//NP