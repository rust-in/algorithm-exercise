#include <cstdio>
using namespace std;

int main()
{
    int num[1005],cnt;
    scanf("%d",&cnt);
    for(int i=1;i<=cnt;i++){
        int n,m,tmp;
        scanf("%d%d",&n,&m);
        for(int j=0;j<m;j++) scanf("%d",&num[j]);
        for(int j=1;j<n;j++)
            for(int k=0;k<m;k++){
                scanf("%d",&tmp);
                if(tmp<num[k])  num[k]=tmp;
            }
        long res=0;
        for(int j=0;j<m;j++)    res+=num[j];
        printf("Case #%d: %ld\n",i,res);
    }
}
