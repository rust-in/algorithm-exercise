#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int nod[205][205];
int res[205][205];
int ans[205][205];
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        memset(res,0,sizeof(res));
        memset(ans,0,sizeof(ans));
        memset(nod,0,sizeof(nod));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&nod[i][j]);
        res[0][0]=nod[0][0];
        for(int i=1;i<m;i++)    res[0][i]=nod[0][i]+res[0][i-1];
        for(int i=1;i<n;i++)    res[i][0]=nod[i][0]+res[i-1][0];
        for(int i=1;i<n;i++)
            for(int j=1;j<m;j++)
                res[i][j]=max(res[i-1][j],res[i][j-1])+nod[i][j];
        node[n-1][m-1]=0;

        printf("%d\n",res[n-1][m-1]);
    }
}
