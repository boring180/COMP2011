#include<bits/stdc++.h>
using namespace std;
char mapp[20][20];
char s[20][20];
int main(){;
   // freopen("in.txt","w",stdout);
    srand((unsigned)time(NULL));
    int n=rand()%20+1;
    cout<<n<<endl;
    for(int i=1;i<=n;i++)
        printf("%c %d\n",'A'+i-1,rand()%1000+1);
    int row=rand()%10+1,col=rand()%10+1;
    while(row*col<n){
        row=rand()%10+1,col=rand()%10+1;
    }
    cout<<row<<' '<<col<<endl;
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            mapp[i][j]=(char)('.');
    for(int i=1;i<=n;i++){
        int xx=rand()%row,yy=rand()%col;
        while(mapp[xx][yy]!='.')
            xx=rand()%row,yy=rand()%col;
        mapp[xx][yy]=(char)('A'+i-1);
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            printf("%c",mapp[i][j]);
        cout<<endl;
    }
    s[0][0]='n',s[0][1]='o',s[0][2]='r',s[0][3]='t',s[0][4]='h';
    s[1][0]='s',s[1][1]='o',s[1][2]='u',s[1][3]='t',s[1][4]='h';
    s[2][0]='w',s[2][1]='e',s[2][2]='s',s[2][3]='t';
    s[3][0]='e',s[3][1]='a',s[3][2]='s',s[3][3]='t';
    int action=rand()%20+1,a_type,dire,mosub,range;
    for(int i=1;i<=action;i++){
        a_type=rand()%3;
        dire=rand()%4;
        mosub=rand()%n+1;
        range=rand()%(min(row,col))+1;
        if(a_type==0)
            printf("%c moves %s %d\n",'A'+mosub-1,s[dire],range);
        if(a_type==1)
            printf("%c hits %s\n",'A'+mosub-1,s[dire]);
        if(a_type==2)    
            printf("%c shoots %s\n",'A'+mosub-1,s[dire]);
        
    }
    printf("!\n");
    return 0;
}