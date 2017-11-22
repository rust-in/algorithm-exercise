#include <iostream>
#include <cstring>
using namespace std;

long long dp[55];
char A[55];

int main()
{
    while(~scanf("%s", A+1))
    {
        dp[0] = 1;
        int len = strlen(A+1);
        if(len == 1 && A[1] == '0') break;
        for (int i = 1; i <= len; ++i) {
            dp[i] = 0;
            if(A[i]=='#' && A[i-1]=='#') {
                dp[i] = 0;
                continue;
            }
            if(A[i]=='#') {
                dp[i] = dp[i-1];
                continue;
            }
            if(A[i] != '0')
                dp[i] += dp[i-1];
            if(i-2>=0 && A[i-1]!='#' && A[i-1] != '0' && (A[i-1]-'0')*10+(A[i]-'0')<=26)
                dp[i] += dp[i-2];
        }
        printf("%lld\n",dp[len]);
    }
}
