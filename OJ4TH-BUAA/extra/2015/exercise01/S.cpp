#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int res[30005]={0};
int V,N;

void compack(int w,int v)
{
    for(int i=w;i<=V;i++)
        if(res[i]<res[i-w]+v)
            res[i]=res[i-w]+v;
}

void zeronepack(int w,int v)
{
    for(int i=V;i>=w;i--)
        if(res[i]<res[i-w]+v)
            res[i]=res[i-w]+v;
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--){
        memset(res,0,sizeof(0));

        int v,w,c;
        scanf("%d%d",&V,&N);
        for(int i=0;i<N;i++){
            scanf("%d%d%d",&v,&w,&c);
            if(w*c>=V){//ÍêÈ«±³°ü
                for(int j=w;j<=V;j++)
                    if(res[j]<res[j-w]+v)
                        res[j]=res[j-w]+v;
            } else{//01
                for(int r=1;r<=c;r<<1){
                    for(int j=V;j>=w*r;j--)
                        if(res[j]<res[j-w*r]+v*r)
                            res[j]=res[j-w*r]+v*r;
                    c-=r;
                }
                for(int j=V;j>=c*w;j--)
                    if(res[j]<res[j-w*c]+v*c)
                        res[j]=res[j-w*c]+v*c;
            }
        }
        int ans=0;
        for(int i=0;i<=V;i++)   ans=max(ans,res[i]);
        printf("%d\n",ans);
    }
}
