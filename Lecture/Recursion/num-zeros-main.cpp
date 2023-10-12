#include <iostream>		/* File: num-zeros-main.cpp */
using namespace std;	

int num_zeros(int number)
{
  if(number == 0)return 1;
  if (number>0 && number < 10)return 0;
  return num_zeros(number / 10) + num_zeros(number % 10);
}

int main()	
{
    int n;

    while (cin >> n)
		cout << "num_zeros(" << n << ") = " << abs(num_zeros(n)) << endl;
	
    return 0;
}
//NP