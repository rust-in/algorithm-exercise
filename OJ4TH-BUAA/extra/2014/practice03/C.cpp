#include <cstdio>
#include <cstring>
using namespace std;
int res[20005];

int main()
{
    int P,N;
    while(~scanf("%d%d",&P,&N)){
        int value,weight;
        memset(res,-1,sizeof(res));     res[0]=0;
        for(int i=0;i<N;i++){
            scanf("%d%d",&value,&weight);
            for(int j=P;j>=weight;j--)
                if(res[j-weight]!=-1&&res[j]<res[j-weight]+value)
                    res[j]=res[j-weight]+value;
        }
        if(res[P]==-1)
            printf("jpx\n");
        else
            printf("%d\n",res[P]);
    }
}
