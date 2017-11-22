#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

long wei[105][105];
long gap[105][105];
long res[105][105];

int main()
{
    int n,m;
    while(~scanf("%d %d",&n,&m)){
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%ld",&wei[i][j]);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%ld",&gap[i][j]);
        for(int i=0;i<n;i++)
            res[i][0]=wei[i][0];
        for(int i=1;i<m;i++)
            for(int k=0;k<n;k++){
                long tmp=LONG_MAX;
                for(int j=0;j<n;j++)
                    tmp=min(tmp, res[j][i-1]+gap[j][k]);
                res[k][i]=tmp+wei[k][i];
            }
        long ans = LONG_MAX;
        for(int i=0;i<n;i++)
            ans = min(ans,res[i][m-1]);
        printf("%ld\n", ans);
    }
}
