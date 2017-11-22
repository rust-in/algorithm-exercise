#include <cstdio>
#include <cstring>
#define MOD 1000007
int n;
int dp[50005][350];
int main()
{
    while(~scanf("%d", &n)) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        int ans = 0;
        for (int i = 1; i < 350; ++i) {
            for (int j = 0; j <= n; ++j) {
                if(j - i >= 0)
                    dp[j][i] = (dp[j-i][i] + dp[j-i][i-1]) % MOD;
            }
            ans = (ans + dp[n][i]) % MOD;
        }
        printf("%d\n", ans);
    }
}
