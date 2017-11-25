#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 500005;
int n;
int a[MAXN];
int dp[MAXN];

int lis()
{
    memset(dp, 0, sizeof(int)*n);
    int len = 1;
    dp[0] = a[0];
    for (int i = 1; i < n; ++i)
    {
        int pos = lower_bound(dp, dp + len, a[i]) - dp;
        dp[pos] = a[i];
        len = max(len, pos + 1);
    }
    return len;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)    scanf("%d",&a[i]);
    printf("%d\n",lis());
}
