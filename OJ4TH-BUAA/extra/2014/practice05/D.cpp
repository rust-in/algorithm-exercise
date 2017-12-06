#include <bits/stdc++.h>
using namespace std;

const int MAX_V=1010;
const int INF=99999999;
const double eps = 1e-8;

//用于表示边的结构体（终点、容量、反向边）
struct edge
{
    int to,cap,rev;
};

vector<edge> G[MAX_V];//图的邻接表表示,注意是NMAX个数组
bool used[MAX_V];     //DFS中用到的访问标记

//向图中增加一条从s到t容量为cap的边
void add_edge(int from,int to,int cap)
{
    edge a = {to,cap,G[to].size()};
    edge b = {to,cap,G[to].size()};
    G[from].push_back(a);
    G[to].push_back(b);
}

//通过DFS寻找增广路
int dfs(int v,int t,int f)
{
    if(v==t)return f;
    used[v]=true;
    for(int i=0; i<G[v].size(); i++)
    {
        edge &e=G[v][i];
        if(!used[e.to]&&e.cap>0)
        {
            int d=dfs(e.to,t,min(f,e.cap));
            if(d > 0)
            {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

//求解从s到t的最大流
int max_flow(int s,int t)
{
    int flow=0;
    while(1)
    {
        memset(used,0,sizeof(used));
        int f=dfs(s,t,INF);
        if(f==0)
            return flow;
        flow += f;
    }
}

int main()
{
    int s,t,c,v,n,T,res;
    while(scanf("%d%d%d",&v,&n,&T)==3)
    {
        for(int i=0;i<MAX_V;i++)
            G[i].clear();
        while(n--)
        {
            scanf("%d%d%d",&s,&t,&c);
            add_edge(s,t,c);
        }
        while(T--)
        {
            scanf("%d%d",&s,&t);
            res=max_flow(s,t);
            printf("%d\n",res);
        }
    }
    return 0;
}
