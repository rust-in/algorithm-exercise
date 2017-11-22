#include <cstdio>
#include <queue>
using namespace std;

struct Flight
{
    int c, id;
    Flight(int c, int id):c(c), id(id) {}
    bool operator < (const Flight& b) const {
        return c < b.c;
    }
};

int n, k, c;
long long ans;
Flight F(0,0);
priority_queue<Flight> Q;

int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        ans = 0;
        for(int i = 1; i <= n + k; i++)
        {
            if(i <= n)
            {
                scanf("%d", &F.c);
                F.id = i;
                Q.push(F);
            }
            if(i >= k+1)//开始处理
            {
                F = Q.top();
                Q.pop();
                ans += (long long)F.c * (i-F.id);
            }
        }
        printf("%lld\n", ans);
    }
}
