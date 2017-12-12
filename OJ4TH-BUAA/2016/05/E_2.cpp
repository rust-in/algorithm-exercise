#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#pragma warning(disable:4996)
using namespace std;
const int N = 1005;
bool G[N][N];
bool flag, visit[N];
int match[N];
int p, n;
struct self_monster {
    int A, L, P;
}a[N];
struct enemy {
    int A, L;
}b[N];
bool dfs(int u)
{
for (int i = 1; i < N; i++)
{
if (G[u][i] && !visit[i])
{
visit[i] = true;
if (match[i] == -1 || dfs(match[i]))
{
match[i] = u;
return true;
}
}
}
return false;
}
int MaxMatch() {
int i, sum = 0;
memset(match, -1, sizeof(match));
for (i = 1; i < N; i++)
{
memset(visit, false, sizeof(visit));
if (dfs(i))sum++;
}
return sum;
}
int main()
{
    while (~scanf("%d", &n)){
        for (int i = 1; i <= n; i++)
            cin >> a[i].A >> a[i].L >> a[i].P;
        for (int i = 1; i <= n; i++)
            cin >> b[i].A >> b[i].L;
        for (int i = 1; i < N; i++)
            for (int j = 1; j < N; j++)
                G[i][j] = false;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (a[i].P == 3)    G[i][j] = true;
                else if (a[i].P == 2 && b[j].A < a[i].L)    G[i][j] = true;
                else if (a[i].P == 1 && b[j].L <=a[i].A)    G[i][j] = true;
                else if (a[i].P == 0 && a[i].A >= b[j].L && a[i].L > b[j].A)    G[i][j]=true;
                else G[i][j] = false;
            }
        }
        int ans = MaxMatch();
        if (ans == n)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
