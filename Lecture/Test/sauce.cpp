#include <iostream>
using namespace std;
//012345A 67891011B 121314151617C 181920212223D 242526272829E
int search(int tocheck[],int length,char letter)
{   
    if(letter == 'A')for(int i = 0;i<length;i++)if(tocheck[i] <= 5)return 1;
    if(letter == 'B')for(int i = 0;i<length;i++)if(tocheck[i] > 5 && tocheck[i]<= 11)return 1;
    if(letter == 'C')for(int i = 0;i<length;i++)if(tocheck[i] > 11 && tocheck[i]<= 17)return 1;
    return 0;
}

int check(int sauce_brand[],int length)
{
    if(search(sauce_brand,length,'C') == 0)return 0;
    if(search(sauce_brand,length,'A') == 0 && search(sauce_brand,length,'B') == 0)return 0;
    return 1;
}

int main()
{
    int count = 0;
    int sauce[4];
    for(int a = 0;a<30;a++)for(int b = a;b<30;b++)for(int c = b;c<30;c++)for(int d = c;d <30;d++)
    {
        sauce[0] = a;
        sauce[1] = b;
        sauce[2] = c;
        sauce[3] = d;
        count += check(sauce,4);
        if(check(sauce,4))
        {
            cout<<sauce[0]<<" "<<sauce[1]<<" "<<sauce[2]<<" "<<sauce[3]<<endl;
        }
    }
    cout<<count;
    return 0;
}