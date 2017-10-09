#include <stdio.h>
using namespace std;

long long ans[1000005];

long long abc(int n)
{
    if(!ans[n])
        ans[n] = abc(n/2) + 1;

    return ans[n];
}

int main()
{
    ans[1]=1;
    int n;
    while(~scanf("%d",&n))
    {
        printf("%lld\n", abc(n));
    }
}
