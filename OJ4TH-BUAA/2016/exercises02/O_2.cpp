#include <bits/stdc++.h>
using namespace std;
long long dp[20][12];

int main()
{
    int n;
    string numstr;
    while(cin>>n>>numstr){
        memset(dp, 0, sizeof(dp));
        int len = numstr.length();
        dp[1][0]=numstr[0]-'0';
        for(int i=1; i<len; i++){
                dp[i+1][0]=(numstr[i]-'0')+dp[i][0]*10;
        }
        int d, u;
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=len; j++){
                for(int k=i; k<j; k++){
                    for(d=0, u=k+1; u<=j; u++){
                        d=d*10+(numstr[u-1]-'0');
                    }
                    if(dp[j][i]<dp[k][i-1]*d){
                        dp[j][i]=dp[k][i-1]*d;
                    }
                }
            }
        }
        cout<<dp[len][n]<<endl;
    }
    return 0;
}
