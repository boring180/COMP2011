#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("comparezjy.txt","w",stdout);
    int cnt=1000;
    while(cnt--){
        system("data.exe > in.txt");
        system("pa1sym.exe < in.txt > symout.txt");
        system("pa1zjy.exe < in.txt > zjyout.txt");
        if(system("fc symout.txt zjyout.txt")) break;
        //else printf("case %d : success!", 10-cnt);
    }   
    return 0;
}