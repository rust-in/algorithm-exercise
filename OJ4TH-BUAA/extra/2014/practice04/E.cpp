#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int node[105][105];
int res[105][105];
int r,c;

const int rodx[]={-1,1,0,0};
const int rody[]={0,0,1,-1};

int dfs(int a, int b)
{
    if(res[a][b])   return res[a][b];
    int ans=0;

    for(int i=0;i<4;i++){
        int x=a+rodx[i],y=b+rody[i];
        if(x<0||x>=r||y<0||y>=c)    continue;
        if(node[x][y]>node[a][b]){
            int tmp = dfs(x,y);
            ans=max(ans,tmp);
        }
    }
    res[a][b]=ans+1;
    return  res[a][b];
}

int main()
{

    while(~scanf("%d%d",&r,&c)){
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                scanf("%d",&node[i][j]);
        int ans=0;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++){
                memset(res,0,sizeof(res));
                ans=max(ans,dfs(i,j));
            }
        printf("%d\n",ans);
    }
}
