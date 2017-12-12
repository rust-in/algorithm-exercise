#include <bits/stdc++.h>
#define MAX 1100
#define INF 0x3f3f3f3f
using namespace std;
struct Node{
    int to;//终点
    int cap;//容量
    int rev;//反向边
};

vector<Node> v[MAX];
bool visited[MAX];
int start[MAX],over[MAX],capacity[MAX];
void Add_Node(int from, int to, int cap)
{
    v[from].push_back((Node){to,cap,v[to].size()});
    v[to].push_back((Node){from,0,v[from].size()-1});
}

int DFS(int s, int t,int f)
{
    if(s==t)
        return f;
    visited[s]=true;
    for(int i=0;i<v[s].size();i++)
    {
        Node &temp=v[s][i];
        if(visited[temp.to]==false &&temp.cap>0)
        {
            int d=DFS(temp.to,t,min(f,temp.cap));
            if(d>0)
            {
                temp.cap-=d;
                v[temp.to][temp.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}

int Max_Flow(int s,int t)
{
    int flow=0;
    for(;;)
    {
        memset(visited,false,sizeof(visited));
        int f=DFS(s,t,INF);
        if(f==0)
            return flow;
        flow+=f;
    }
}
int main()
{
    int V,N,T;
    while(~scanf("%d%d%d",&V,&N,&T))
    {
//    int n,s,t;
    //int start,over,capacity;
//    while(~scanf("%d%d%d",&n,&s,&t))
//    {
        memset(v,0,sizeof(v));
        for(int i=0;i<N;i++)
        {
            scanf("%d%d%d",&start[i],&over[i],&capacity[i]);
//            Add_Node(start[i],over[i],capacity[i]);
        }
        int x,y;
        for(int i=1;i<=T;i++)
        {
            for(int j=0;j<N;j++)
                Add_Node(start[j],over[j],capacity[j]);
            scanf("%d%d",&x,&y);
            printf("%d\n",Max_Flow(x,y));
        }
//        printf("%d\n",Max_Flow(s,t));
//    }
    }
}
