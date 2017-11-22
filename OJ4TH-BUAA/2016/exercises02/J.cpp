#include <cstdio>
#include <cstring>
#define MOD 1000007
int n, m;
int dp[10005][1005];
int main()
{
    while(~scanf("%d %d", &n, &m)) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if(i - j >= 0) //дя╣Ц
                    dp[i][j] = (dp[i-j][j] + dp[i-1][j-1]) % MOD;
            }
        }
        printf("%d\n", dp[n][m]);
    }
}
