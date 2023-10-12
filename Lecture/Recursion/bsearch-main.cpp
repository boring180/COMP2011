#include <iostream>		/* File: bsearch-main.cpp */
using namespace std;	
const int NOT_FOUND = -1;
int bsearch(const int data[], int low, int high, int num)
{
    int mid = (low + high) / 2;
     if (high < low)          // Base case #1
        return NOT_FOUND;
    if(data[mid] == num)return mid;
    if(data[mid] < num)return bsearch(data,mid+1,high,num);
    if(data[mid] > num) return bsearch(data,low,mid-1,num);
}

int data[] = { 3, 5, 7, 9, 11, 13, 15, 17 };

int main()	
{
    int x;
    int num_data = sizeof(data)/sizeof(int);

    while (cin >> x)
	cout << bsearch(data, 0, num_data-1, x) << endl;
	
    return 0;
}
