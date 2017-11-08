#include <cstdio>
#include <cstring>
using namespace std;

int value[305];
int weight[305];
int res[20005];
int main()
{
    int P,N;
    while(~scanf("%d%d",&P,&N)){
        for(int i=0;i<N;i++)
            scanf("%d%d",&value[i],&weight[i]);
        memset(res,0,sizeof(res));
        for(int i=0;i<N;i++)
            for(int j=weight[i];j<=P;j++)
                if(res[j]<res[j-weight[i]]+value[i])
                    res[j]=res[j-weight[i]]+value[i];
        printf("%d\n",res[P]);
    }
}
