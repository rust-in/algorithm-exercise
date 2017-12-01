#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
#define ll long long
#define inf 10000050
#define maxn 100060
int a[maxn],dp[maxn],c[maxn];
int main()
{
    int n,m,i,j,len,d,maxx;
    while(scanf("%d%d",&n,&d)!=EOF)
    {
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            c[i]=inf;
        }
        maxx=1;
        for(i=1;i<=n;i++){
            dp[i]=lower_bound(c+1,c+1+n,a[i])-c;
            maxx=max(maxx,dp[i]);//更新最大值，因为可能这是最后一个数
            j=i-d;
            if(j>=1 && c[dp[j] ]>a[j]){  //把j更新进去，dp[j]是在循环到j时算出来的
                c[dp[j] ]=a[j];
            }
        }
        printf("%d\n",maxx);
    }
    return 0;
}
