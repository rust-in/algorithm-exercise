#include <bits/stdc++.h>
using namespace std;
const int MAXN = 605;
int mp[MAXN][MAXN];
struct Point{
    int x, y;
}p[MAXN];
int cmp(Point A, Point B){
    if(A.x == B.x) return A.y < B.y;
    return A.x < B.x;
}
int main()
{
    ///freopen("in.txt","r", stdin);
    int n;
    while(~scanf("%d", &n)){
        memset(mp, 0, sizeof(mp));
        for(int i=0; i<n; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            p[i].x = (x + 300);
            p[i].y = (y + 300);
            mp[p[i].x][p[i].y] = 1;
        }
        sort(p, p+n, cmp);
        int sum = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int dx = p[i].x - p[j].x;
                int dy = p[j].y - p[i].y;
                if(mp[p[i].x+dy][p[i].y+dx] && mp[p[j].x+dy][p[j].y+dx]) sum++;
            }
        }
        printf("%d\n",sum/2);
    }
    return 0;
}
