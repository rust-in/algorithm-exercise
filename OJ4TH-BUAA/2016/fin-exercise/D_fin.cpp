#include <cstdio>
#include <iostream>
#include <algorithm>
#define MaxSize 10005
using namespace std;

int n, ans;
int A[MaxSize];
short int dp[MaxSize][MaxSize];

int main()
{
    while(~scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i)
            scanf("%d", &A[i]);
        sort(A, A+n);

        for (int i = 0; i < n; ++i)
            for (int j = i+1; j < n; ++j)
                dp[i][j] = 2;

        ans = 2;
        for (int j = n-2; j > 0; --j) {
            int i = j-1, k = j+1;
            while(i>=0 && k<n)
            {
                if(A[i]+A[k] < 2*A[j])
                    k++;
                else if(A[i]+A[k] > 2*A[j])
                    i--;
                else
                {
                    dp[i][j] = dp[j][k] + 1;
                    if(dp[i][j] > ans)
                        ans = dp[i][j];
                    i--, k++;
                }
            }
        }
        printf("%d\n", ans);
    }
}
