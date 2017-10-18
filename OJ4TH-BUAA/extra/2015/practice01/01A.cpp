#include <stdio.h>
using namespace std;

int main()
{
    int n,x,t,cnt=1;
    int num[10005];
    long long sum=1;
    while(~scanf("%d%d%d",&n,&x,&t))
    {
        printf("Case #%d:\n", cnt++);
        while(t--)
        {
            for(int i=0;i<=n;i++)
                scanf("%d", &num[i]);
            sum=num[n];
            for(int i=n-1;i>=0;i--)
                sum=((sum*x)%1000007+num[i])%1000007;
            printf("%ld\n",sum);
        }
    }
}
