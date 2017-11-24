#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int res[15][1005];
int wei[15];
int gap[15][15];

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        memset(res,0x3f,sizeof(res));
        for(int i=1;i<=n;i++)
            res[i][0]=0;
        memset(gap,0,sizeof(gap));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++)
                scanf("%d",&wei[j]);
            for(int p=1;p<=n;p++)
                for(int q=1;q<=n;q++)
                    res[p][i]=min(res[p][i],res[q][i-1]+gap[q][p]+wei[p]);
            if(i!=m){
                for(int p=1;p<=n;p++)
                    for(int q=1;q<=n;q++)
                        scanf("%d",&gap[p][q]);
            }
        }
        int ans=res[1][m];
        for(int i=2;i<=n;i++)   ans=min(ans,res[i][m]);
        printf("%d\n",ans);
    }
}
