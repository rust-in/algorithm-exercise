#include <bits/stdc++.h>
using namespace std;

const int MAX_V=1010;
const int INF=99999999;
const double eps = 1e-8;

int v,n;
int rod[25][25];
int rec[25];

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

void DFS(int i){
    if(rec[i]==1)   return;
    rec[i]=1;
    for(int j=1;j<=v;j++){
        if(rod[i][j]>-1)
            DFS(j);
    }
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
    int s,t,c,T,res;
    while(~scanf("%d%d",&v,&n))
    {
        for(int i=0;i<MAX_V;i++)
            G[i].clear();
        memset(rod,-1,sizeof(rod));
        memset(rec,0,sizeof(rec));
        while(n--)
        {
            scanf("%d%d%d",&s,&t,&c);
            rod[s][t]=c;
            add_edge(s,t,c);
        }
        res=max_flow(1,v);
        DFS(1);
        if(rec[v])
            printf("%d\n",res);
        else
            printf("404 Not Found\n");
    }
    return 0;
}
