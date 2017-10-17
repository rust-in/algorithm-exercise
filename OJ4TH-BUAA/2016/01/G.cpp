#include <iostream>
#include <cstdio>
#include <climits>
#define MAXNUM 1000000
using namespace std;

long long num[MAXNUM];
long long cop[MAXNUM];
long res=0;

void Merge(long long *num, long long p, long long q, long long r)
{
    long long n1 = q - p + 1;
    long long n2 = r - q;
    long long i=0,j=0,k;

    long long L[n1],R[n2];

    for(i=0;i<n1;i++)
        L[i] = num[p+i];
    for(j=0;j<n2;j++)
        R[j] = num[q+j+1];

    long long cnt=n2-1;
    for(i=n1-1,j=n2-1,k=r; k>=p; k--) //µπ–Ú¥¶¿Ì
    {
        if(i<0||j<0)    break;
        if(L[i]<=R[j])
            num[k]=R[j--];
        else
        {
            for(;cnt>=0;cnt--){
                if(L[i]>2*R[cnt]){
                    res+=cnt+1;
                    break;
                }
            }
            num[k]=L[i--];
        }
    }

    while(i>=0) num[k--]=L[i--];
    while(j>=0) num[k--]=R[j--];
}

void MergeSort(long long num[], long long p, long long r)
{
    if(p < r)
    {
        long long q = (p+r)/2;
        MergeSort(num,p,q);
        MergeSort(num,q+1,r);
        Merge(num,p,q,r);
    }
}

int main()
{
    long long len;
    while(~scanf("%lld",&len)){
        for(long long i=0;i<len;i++)
            scanf("%lld",&num[i]);
        int slen;
        scanf("%d",&slen);
        while(slen--){
            res = 0;
            long long a,b;
            scanf("%lld %lld",&a,&b);
            if(b<a) a=a+b-(b=a);
            for(long long i=a;i<=b;i++)
                cop[i-a] = num[i];
            MergeSort(cop,0,b-a);
            printf("%ld\n",res);
        }
    }

    return 0;
}
