#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
long long have[3005000];
long long sum[3005000];
int main()
{
    long long n,x,y;
    while(~scanf("%lld%lld%lld",&n,&x,&y))
    {
        memset(have,0,sizeof(have));
        memset(sum,0,sizeof(sum));
        for(long long i=1;i<=n;i++)
        {
            long long tmp;scanf("%lld",&tmp);
            have[tmp]++;sum[tmp]+=tmp;
        }
        long long ans=1000000000000000000;
        for(long long i=1;i<=2000000;i++)have[i]+=have[i-1],sum[i]+=sum[i-1];
        long long move=(x/y);
        for(long long i=2;i<=1000000;i++)
        {
            long long now=0;
            for(long long j=i;j<=2000000;j+=i)
            {
                long long fen=max(j-i+1,j-move);
                long long Inum=have[j]-have[fen-1];
                long long Isum=sum[j]-sum[fen-1];
                long long Dnum=have[fen-1]-have[j-i];
                now+=Dnum*x;
                now+=y*(j*Inum-Isum);
            }
            ans=min(ans,now);
        }
        printf("%lld\n",ans);
    }
}
