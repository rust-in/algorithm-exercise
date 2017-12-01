#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

struct BigNum {
    int len;
    int num[100];
};

int n, kk;
char s[105];//数字串
int A[105];//原数字
BigNum dp[105][12];//dp[i][j]表示前i个数字有j个乘号时的最大值。

BigNum cal(BigNum x, int l, int r)
{
    BigNum ans, y;
    memset(ans.num, 0, sizeof(ans.num));
    memset(y.num, 0, sizeof(y.num));

    y.len = r - l + 1;
    for (int i = r; i >= l; --i)
        y.num[r-i+1] = A[i];

    for (int i = 1; i <= x.len; ++i) {
        for (int j = 1; j <= y.len; ++j) {
            ans.num[i+j-1] += x.num[i] * y.num[j];
        }
    }

    int newLen = x.len + y.len -1;
    for (int i = 1; i <= newLen; ++i) {
        ans.num[i+1] += ans.num[i]/10;
        ans.num[i] = ans.num[i]%10;
    }
    if(ans.num[newLen+1] > 0) newLen++;
    ans.len = newLen;

    /*for (int i = ans.len; i >= 1; --i)
        printf("%d", ans.num[i]);
    printf("\n");*/
    return ans;
}

BigNum cmp(BigNum x, BigNum y)//比较大小
{
    if(x.len > y.len) return x;
    else if(x.len < y.len) return y;

    for (int i = x.len; i >=1 ; --i) {
        if(x.num[i] > y.num[i]) return x;
        else if(x.num[i] < y.num[i]) return y;
    }
    return x;
}

int main()
{
    //freopen("in1.txt", "r", stdin);
    //freopen("outme.txt", "w", stdout);
    while(~scanf("%d %s", &kk, s))
    {
        for (int i = 0; i < 105; ++i) {
            for (int j = 0; j < 12; ++j) {
                dp[i][j].len = 0;
                memset(dp[i][j].num, 0, sizeof(dp[i][j]));
            }
        }
        n = strlen(s);
        for (int i = 1; i <= n; ++i)
            A[i] = s[i-1] - '0';
        //初始化没有添加乘号的情况
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j >= 1; --j) {
                dp[i][0].num[++dp[i][0].len] = A[j];
            }
        }

        for (int i = 2; i <= n; ++i) {
            for (int k = 1; k <= min(kk, i-1); ++k) {
                for (int j = k; j < i; ++j) {
                    dp[i][k] = cmp(dp[i][k], cal(dp[j][k-1], j+1, i));
                }
            }
        }

        for (int i = dp[n][kk].len; i >= 1; --i) {
            printf("%d", dp[n][kk].num[i]);
            if(dp[n][kk].num[dp[n][kk].len] == 0) break;
        }
        printf("\n");
    }
}
