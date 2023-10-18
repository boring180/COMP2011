//This is Q6 of 16F MT
#include <iostream>
using namespace std;
/*
* Helper function to print the positive decimal integer
*/
void arrayPrint(const int arr[], int n)
{
for (int i=0; i<n; i++)
cout << arr[i];
}
// Function definition of arrayAdd is presumed to be here

bool arrayAdd(const int arrA[],const int arrB[],int arrSum[],int n)
{
    for(int i = 0;i<n;i++) arrSum[i] = 0;
    for(int i = 0;i<n;i++)
    {
        arrSum[n-i]+=(arrA[n-i]+arrB[n-i]);
        if(arrSum[n-i]>=10)
        {
            arrSum[n-i]-=10;
            if(n-i<1)return 1;
            arrSum[n-i-1]+=1;
        }
    }
    return 0;
}


int main()
{
int op1[4] = {1,5,8,1}; // op1 = 1581
int op2[4] = {2,9,3,0}; // op2 = 2930
/* more examples:
* op1[4] = {0,1,3,5} represents the integer 135
* op1[4] = {0,0,0,0} represents the integer 0
*/
int sum[4];
bool overflow;
overflow = arrayAdd(op1, op2, sum, 4);
arrayPrint(op1, 4);
cout << " + ";
arrayPrint(op2, 4);
cout << " = ";
arrayPrint(sum, 4);
cout << endl; // print out 1581 + 2930 = 4511
if (overflow) // e.g. overflow happens when 9812 + 1306
cout << "The sum is wrong due to overflow" << endl;
return 0;
}