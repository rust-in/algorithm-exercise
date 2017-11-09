#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    while(n--){
        int res[30005]={0};
        int V,N,v,w,c;
        scanf("%d%d",&V,&N);
        for(int i=0;i<N;i++){
            scanf("%d%d%d",&v,&w,&c);
            for(int j=1;j<=c;j++)
                for(int k=V;k>=w;k--)
                    res[k]=max(res[k],res[k-w]+v);
        }
        int ans=0;
        for(int i=0;i<=V;i++)    ans=max(ans,res[i]);
        printf("%d\n",ans);
    }
}
