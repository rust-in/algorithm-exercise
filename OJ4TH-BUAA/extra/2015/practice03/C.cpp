#include <cstdio>
using namespace std;

int main()
{
    int l,len,x,w,t,k;
    int cost[10005],weight[10005];
    while(~scanf("%d",&l)){
        len=0;
        for(int i=0;i<l;i++){
            scanf("%d%d%d",&x,&w,&t);
            if(t&&w>0){
                cost[len]=x;
                weight[len]=w;
                len++;
            }
        }
        scanf("%d",&k);
        if(len==0){printf("0\n");continue;}
        long long res[100005]={0};
        for(int i=0;i<len;i++){
            for(int j=k;j>=cost[i];j--){
                if(res[j]<res[j-cost[i]]+weight[i])
                    res[j]=res[j-cost[i]]+weight[i];
            }
        }
        long long fin=0;
        for(int i=0;i<=k;i++)  if(fin<res[i])  fin=res[i];
        printf("%lld\n",fin);
    }
}
