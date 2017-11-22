#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int m, n;
int M[201][201];
int dp[201][201][201];
inline int MAX(int a, int b, int c, int d)
{
    int minAns = a;
    if(minAns < b) minAns = b;
    if(minAns < c) minAns = c;
    if(minAns < d) minAns = d;
    return minAns;
}

int main()
{
    while(~scanf("%d%d", &n, &m)) {
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                scanf("%d", &M[i][j]);
        dp[1][1][1] = M[1][1];
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                for(int k = 1; k <= n && k <= (i+j); ++k) {
                    int t = (i+j)-k;
                    if ( k != i )//保证不重复
                        dp[i][j][k] = M[i][j]+M[k][t]+ MAX(dp[i-1][j][k],dp[i][j-1][k],dp[i-1][j][k-1],dp[i][j-1][k-1]);
                }
        printf("%d\n", dp[n][m-1][n-1] + M[n][m]);
    }
    return 0;
}
