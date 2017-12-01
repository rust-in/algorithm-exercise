#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

int num[500005];
int sub[500005];
int dp[500005];

int len,gap;

int main()
{
    while(~scanf("%d%d",&len,&gap)){
        gap-=1;
        for(int i=0;i<len;i++)  scanf("%d",num+i),dp[i]=INT_MAX;
        int ans = 0,tmp;
        for(int i=0;i<len;i++){
            sub[i]=lower_bound(dp,dp+len,num[i])-dp;
            ans = max(sub[i]+1,ans); //ÏÂ±ê¼Ó1
            tmp = i-gap;
            if(tmp>=0&&dp[sub[tmp]]>num[tmp])
                dp[sub[tmp]]=num[tmp];
        }
        printf("%d\n",ans);
    }
}
