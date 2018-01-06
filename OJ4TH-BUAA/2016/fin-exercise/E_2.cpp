#include <cstdio>
#include <cstring>
#include <vector>
#define MaxSize 1005
#define INF 0x3f3f3f3f
using namespace std;

int n, m, ans;
vector<int> G[MaxSize];//记录匹配的双方弟子
int match[MaxSize];//记录匹配点
int visit[MaxSize];//记录是否访问

int A[MaxSize], B[MaxSize];

bool dfs(int x)//寻找增广路径
{
    for (int i = 0; i < G[x].size(); ++i)
    {
        int to = G[x][i];
        if(!visit[to])
        {
            visit[to] = 1;
            if(!match[to] || dfs(match[to]))
            {
                match[to] = x;
                return true;
            }
        }
    }
    return false;
}

int MaxMatch()
{
    ans = 0;
    memset(match, 0, sizeof(match));
    for (int i = 1; i <= m; ++i)
    {
        memset(visit, 0, sizeof(visit));//清空访问
        if(dfs(i)) ans++;//从节点i尝试扩展
    }
    return ans;
}

int main()
{
    while(~scanf("%d %d", &n, &m))
    {
        for (int i = 1; i < MaxSize; ++i)
            G[i].clear();
        for (int i = 1; i <= n; ++i)
            scanf("%d", &A[i]);
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d", &B[i]);
            for(int j = 1; j <= n; ++j)
            {
                if(B[i] % A[j] == 0)
                    G[i].push_back(j);
            }
        }

        printf("%d\n", MaxMatch());
    }
}
