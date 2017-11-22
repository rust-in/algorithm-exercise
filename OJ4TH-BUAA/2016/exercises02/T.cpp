#include <cstdio>
#include <queue>
using namespace std;

struct Flight
{
    int c, id;
    bool operator<(const Flight& b) const {
        return c < b.c;
    }
}F[500005], t;

int n, k;
long long ans;
priority_queue<Flight> Q;

int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        ans = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &F[i].c);
            F[i].id = i;
        }
        for(int i = 1; i <= k; i++)
            Q.push(F[i]);
        for(int i = k+1; i <= k+n; i++)
        {
            if(i <= n)
                Q.push(F[i]);
            t = Q.top();
            Q.pop();
            ans += (long long)t.c * (i-t.id);
        }
        printf("%lld\n", ans);
    }
}
