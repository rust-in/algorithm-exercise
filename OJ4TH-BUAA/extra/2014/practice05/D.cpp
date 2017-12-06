#include <bits/stdc++.h>
using namespace std;

const int MAX_V=1010;
const int INF=99999999;
const double eps = 1e-8;

//���ڱ�ʾ�ߵĽṹ�壨�յ㡢����������ߣ�
struct edge
{
    int to,cap,rev;
};

vector<edge> G[MAX_V];//ͼ���ڽӱ��ʾ,ע����NMAX������
bool used[MAX_V];     //DFS���õ��ķ��ʱ��

//��ͼ������һ����s��t����Ϊcap�ı�
void add_edge(int from,int to,int cap)
{
    edge a = {to,cap,G[to].size()};
    edge b = {to,cap,G[to].size()};
    G[from].push_back(a);
    G[to].push_back(b);
}

//ͨ��DFSѰ������·
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

//����s��t�������
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
