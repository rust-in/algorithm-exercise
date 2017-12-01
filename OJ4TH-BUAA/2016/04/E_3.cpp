#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
string x;
string y;
#define N 102
int c[N][N];
int main()
{
    while(cin>>x>>y)
    {
        x.erase(remove(x.begin(),x.end(),'#'),x.end());
        y.erase(remove(y.begin(),y.end(),'#'),y.end());
        int lx=x.length();
        int ly=y.length();
        memset(c,0,sizeof(c));
        for(int i=1;i<=lx+1;i++){
            for(int j=1;j<=ly+1;j++){
                if(x[i-1]==y[j-1]||x[i-1]=='?'||y[j-1]=='?'){
                    c[i][j]=c[i-1][j-1]+1;
                }
                else if(c[i-1][j]>=c[i][j-1]){
                    c[i][j]=c[i-1][j];
                }
                else{
                    c[i][j]=c[i][j-1];
                }
            }
        }
        printf("%d\n",c[lx][ly]);
    }
}
