#include <cstdio>
#include <iostream>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;

int n, m, sum;
int Weight[102];//体积
int Value[102];//价值
int dp[100005];

int main()
{
    while(~scanf("%d %d", &n, &m))
    {
        int wSum = 0, vSum = 0;
        memset(dp, INF, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &Weight[i], &Value[i]);
            wSum += Weight[i];
            vSum += Value[i];
        }

        dp[0] = 0;
        dp[vSum] = wSum;
        for (int i = 0; i < n; ++i) {
            for (int j = vSum; j >= Value[i]; --j) {
                if(dp[j] > dp[j-Value[i]] + Weight[i])
                    dp[j] = dp[j-Value[i]] + Weight[i];
            }
        }

        for (int i = vSum; i >= 0; --i) {
            if(dp[i] <= m) {
                printf("%d\n", i);
                break;
            }
        }
    }
}
