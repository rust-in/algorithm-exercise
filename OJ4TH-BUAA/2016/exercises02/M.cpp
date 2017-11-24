#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100010;
const int INF = 0x3f3f3f3f;

bool Vis[N];//是否被访问过
int Dis[N];//距离

struct DisAndStart
{
    int dis;//距离
    int start;//起点
    bool operator < (const DisAndStart& p)const {
        return p.dis<dis;
    }
    DisAndStart(int d, int s):dis(d),start(s){}
};

vector<pair<int, int> > V[N];//二维的vector数组

void dijkstra(int s)
{
    priority_queue<DisAndStart> Q;
    memset(Dis,INF,sizeof(Dis));
    memset(Vis,0,sizeof(Vis));

    Dis[s]=0;
    Q.push(DisAndStart(0,s));
    while(!Q.empty())
    {
        DisAndStart p=Q.top();
        Q.pop();
        if(Vis[p.start]) continue;//已经访问过该点
        Vis[p.start]=1;
        for(int t=0;t<V[p.start].size();t++)
        {
            int end=V[p.start][t].first;
            int Time=V[p.start][t].second;
            if(Dis[p.start]+Time<Dis[end])
            {
                Dis[end]=Dis[p.start]+Time;
                Q.push(DisAndStart(Dis[end],end));
            }
        }
    }
}
int main()
{
    //freopen("in2.txt", "r", stdin);
    //freopen("out2.txt", "w", stdout);
    int n, m, k, des;
    int x, y, Time;
    while(~scanf("%d%d%d", &n, &m, &k))
    {
        for(int i = 1; i <= n; i++)//清空数据
            V[i].clear();
        while(m--)
        {
            scanf("%d%d%d", &x, &y, &Time);
            V[x].push_back(make_pair(y, Time));
            V[y].push_back(make_pair(x, Time));
        }
        dijkstra(1);
        int cnt = 1;
        for(int i = 0; i < k; ++i)
        {
            scanf("%d", &des);

            if(Dis[des] == INF) printf("Case %d:-1\n", cnt);
            else printf("Case %d:%d \n", cnt, Dis[des]);
            cnt++;
        }
        printf("\n");
    }
}
