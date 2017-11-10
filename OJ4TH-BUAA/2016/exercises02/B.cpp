#include <cstdio>
#include <cstring>
using namespace std;

int num[505];

int main()
{
    int n;
    while(~scanf("%d",&n)){
        int a,b;    memset(num,0,sizeof(num));
        for(int i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            a=(a-1)/2;  b=(b-1)/2;
            if(a>b) a=a+b-(b=a);
            for(int j=a;j<=b;j++)   num[j]++;
        }
        int res=0;
        for(int i=0;i<250;i++)
            res=res<num[i]?num[i]:res;
        printf("%d\n",res*10);
    }
}
