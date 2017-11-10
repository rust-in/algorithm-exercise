#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define CLR(a,b) memset(a,(b),sizeof(a))
const int N = 500+10;
bool vis[N<<1][N<<1];
int X[N],Y[N];
int main()
{
    int n;
    while(~scanf("%d",&n)) {
        CLR(vis,false);
        LL k = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d%d",&X[i],&Y[i]);
            vis[N+X[i]][N+Y[i]] = true;
        }
        int x1, x2, x3,
         x4;
        int y1, y2, y3, y4;
        for(int i = 1; i < n; i++) {
            x1 = X[i], y1 = Y[i];
            for(int j = 0; j < i; j++) {
                x2 = X[j], y2 = Y[j];
                x3 = x1 + (y1-y2);
                y3 = y1 - (x1-x2);
                x4 = x2 + (y1-y2);
                y4 = y2 - (x1-x2);
                if(vis[N+x3][N+y3] && vis[N+x4][N+y4]) k++;
                x3 = x1 - (y1-y2);
                y3 = y1 + (x1-x2);
                x4 = x2 - (y1-y2);
                y4 = y2 + (x1-x2);
                if(vis[N+x3][N+y3] && vis[N+x4][N+y4]) k++;
            }
        }
        printf("%lld\n",k/4);
    }
return 0;
}
