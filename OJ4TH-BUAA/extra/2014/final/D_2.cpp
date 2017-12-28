#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
    //#ifndef _OJ_  //ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    int m, n, a[1000];
    while(~scanf("%d",&n)){
        scanf("%d", &m);
        while (m--)
        {
            int t = 0, i, j;
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
                scanf("%d", &a[i]);
            for (i = 0; i < n - 1; ++i)
            {
                t = a[i];
                for (j = 1; j < n; ++j)
                {
                    if (a[j] < a[i])
                    {
                        if (t > a[j]) t = a[j];
                        else break;
                    }
                }
                if (j < n) break;
            }
            if (i == n - 1 && j == n)printf("YES\n");
            else    printf("NO\n");
        }
    }

    return 0;
}
