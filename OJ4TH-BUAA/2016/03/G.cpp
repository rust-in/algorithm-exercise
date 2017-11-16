#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#define MON 1000007
using namespace std;

int one[207][207],two[207][207];

int main()
{
    int n,m,x,y,i,j,k,p;
    while(~scanf("%d%d%d%d",&n,&m,&x,&y))
    {
        memset(one,0,sizeof(one));
        memset(two,0,sizeof(two));
        for(i=1;i<=x;i++)   one[i][0]=1;
        for(j=1;j<=y;j++)   two[0][j]=1;
        //dp过程
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++){
                for(k=1;k<=x&&k<=i;k++) //计算队尾为0的情况
                {
                    one[i][j]+=two[i-k][j];
                    one[i][j]%=MON;
                }
                for(p=1;p<=y&&p<=j;p++) //计算队尾为1的情况
                {
                    two[i][j]+=one[i][j-p];
                    two[i][j]%=MON;
                }
            }
        //计算结果
        int ans=one[n][m]+two[n][m];
        ans%=MON;
        printf("%d\n",ans);
    }

}
