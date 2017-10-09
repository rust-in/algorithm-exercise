#include <cstdio>
#include <climits>
using namespace std;

long long num[2000005];
long long a[1000005];
long long b[1000005];

int main()
{
    int lena,lenb,i;
    while(~scanf("%d%d",&lena,&lenb))
    {
        if(lena==0&&lenb==0)
            printf("%.1f\n",0);
        else
        {
            for(i=0;i<lena;i++)
                scanf("%lld", &a[i]);
            for(i=0;i<lenb;i++)
                scanf("%lld", &b[i]);
            a[lena]=b[lenb]=LONG_LONG_MAX;
            int l=0,r=0,length=lena+lenb;
            for(i=0;i<length;i++)
            {
                if(a[l]<=b[r])
                    num[i]=a[l++];
                else
                    num[i]=b[r++];
            }

            if(length%2)
                printf("%.1lf\n", (double)num[length/2]);
            else
                printf("%.1lf\n", (double)((num[length/2-1]+num[length/2])/2));
        }
    }
}
