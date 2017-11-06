#include <stdio.h>
#include <algorithm>
using namespace std;

int node[1005][1005];
long maxres[1005][1005];

int main()
{
    int dep;
    while(~scanf("%d",&dep)){
        for(int i=1;i<=dep;i++)
            for(int j=1;j<=i;j++)
                scanf("%d",&node[i][j]);
        maxres[1][1]=node[1][1];
        for(int d=2;d<=dep;d++){
            maxres[d][1]=maxres[d-1][1]+node[d][1];
            for(int j=2;j<d;j++)
                maxres[d][j]=max(maxres[d-1][j-1],maxres[d-1][j])+node[d][j];
            maxres[d][d]=maxres[d-1][d-1]+node[d][d];
        }
        long res=0;
        for(int i=1;i<=dep;i++) res=max(res,maxres[dep][i]);
        printf("%ld\n",res);
    }
}
