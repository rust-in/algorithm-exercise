#include <bits/stdc++.h>

/**
http://www.cnblogs.com/agenthtb/p/7487788.html
http://www.voidcn.com/article/p-vionzrzi-bqn.html
*/
using namespace std;
const int maxn = 10005;
int n;
double l,r;
double dp[maxn];
double calc (int n,int x)
{
    return (1.0+l*dp[x-1]+r*dp[n-x])/(1-l-r)+dp[x-1]+dp[n-x];
}
int main()
{
    //freopen("de.txt","r",stdin);
    while (~scanf("%d",&n)){
        if (n==0) break;
        scanf("%lf%lf",&l,&r);
        dp[0]=0;
        dp[1]=1.0/(1-r-l);
        for (int i=2;i<=n;++i){
            dp[i]=calc(i,i);
            for (int j=1;j<=i;++j)
                dp[i]=min(dp[i],calc(i,j));
        }
        printf("%.2f\n",dp[n]);
    }
    return 0;
}
