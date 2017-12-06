#include <bits/stdc++.h>
#define MAX 10000010
using namespace std;

int a[MAX];

int main()
{
    int n,m,k;
    int *f,*p,*l;
    while(~scanf("%d%d", &n,&m))
    {
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        p=lower_bound(a,a+n,m);
        k=*(p-1);
        f=lower_bound(a,a+n,k);
        l=upper_bound(a,a+n,k);
        printf("%d\n", l-f);
    }
}
