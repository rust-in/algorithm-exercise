#include <cstdio>
#include <algorithm>
using namespace std;

long long num[1005];

int main()
{
    int n;  long long m;
    while (~scanf("%d%lld",&n,&m)){
        for(int i=0;i<n;i++) scanf("%lld",&num[i]);
        num[n]=0;
        sort(num,num+n);
        int ans=0,i=0;  long long tmp=0;
        while (tmp<m){
            while (tmp<m&&i<n&&num[i]<=tmp+1)
                tmp+=num[i++];

            if (tmp>=m)
                break;

            tmp+=(tmp+1);

            ans++;
        }
        printf("%d\n",ans);
    }
}
