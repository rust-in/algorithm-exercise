#include<iostream>
#include<cstdio>
#include<list>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#include<cmath>
#include<memory.h>
#include<set>

long long TNF=99999999;
#define LL __int64
#define eps 1e-8


using namespace std;

#define M 400000100

#define inf 0xfffffff


vector<int>G[1212];

char tempmp[1212];
int mp[1212][1212];
int lmarry[1212],rmarry[1212];
bool visl[1212],visr[1212];

int dis[2][4]={0,-1,0,1,1,0,-1,0};

int n=1000,m=1000,k;

void clear()
{
    memset(lmarry,-1,sizeof(lmarry));
    memset(rmarry,-1,sizeof(rmarry));
    memset(visl,false,sizeof(visl));
    memset(visr,false,sizeof(visr));
    memset(mp,0,sizeof(mp));
    for(int i=0;i<1212;i++)
        G[i].clear();
}

bool dfs(int x)
{
    visl[x]=true;
    for(int i=0;i<G[x].size();i++)
    {
        int v=G[x][i];
        if(!visr[v])
        {
            visr[v]=true;
            if(lmarry[v]==-1 || dfs(lmarry[v]))
            {
                lmarry[v]=x;
                rmarry[x]=v;
                return 1;
            }
        }
    }
    return 0;
}


int main(void)
{
    while(~scanf("%d",&k))
    {
        clear();
        int u,v;
        for(int i=0;i<k;i++)
        {
            scanf("%d %d",&u,&v);
            G[u].push_back(v);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            memset(visr,false,sizeof(visr));
            if(dfs(i))
                ans++;
        }
        printf("%d",ans);
        memset(visl,false,sizeof(visl));
        memset(visr,false,sizeof(visr));
        printf("\n");
    }
}
