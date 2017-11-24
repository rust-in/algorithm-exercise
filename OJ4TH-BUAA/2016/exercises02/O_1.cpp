#include <cstdio>
#include <cstring>
typedef long long LL;

long long dp[22][12];
char num[22];

LL convert(int l, int r)
{
    LL res = 0;
    for (int i = l; i <= r; ++i)
        res = res*10 + (num[i]-'0');
    return res;
}

int main()
{
    //freopen("in1.txt", "r", stdin);
    //freopen("outme.txt", "w", stdout);
    int n;
    while(~scanf("%d", &n))
    {
        memset(dp, 0, sizeof(dp));
        scanf("%s", num);

        int len = strlen(num);
        dp[0][0] = num[0] - '0';
        for (int i = 1; i < len; ++i)//初始化
            dp[i][0] = dp[i-1][0] * 10 + (num[i] - '0');

        for (int i = 0; i < len; ++i)
        {
            for (int j = 1; j <= (n<i? n:i); ++j)//最多有(n<i? n:i)个乘号
            {
                for (int k = 1; k <= (i-j+1); ++k)//在i-k位置后添加一个乘号
                {
                    LL tem = dp[i-k][j-1]*convert(i-k+1,i);
                    if(dp[i][j] < tem) dp[i][j] = tem;
                }
            }
        }
        printf("%lld\n", dp[len-1][n]);
    }
}
