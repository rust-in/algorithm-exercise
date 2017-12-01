#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

/**
思路：

难题。逆推DP。

要明确dp的状态只与是否有选择权有关，而与选择权在谁手里无关。因为不论选择权在谁手里，那个人都会尽可能的获得最大的蛋糕重量。

dp[i]表示分配到第i个物品为止，当前拥有选择权的人能获得的最大蛋糕重量，即蛋糕[i~n]的最大值。以有选择权的的人列一个转移方程，然而因为我们只知道初始选择的是AlvinZH，因此我们要逆推：

dp[i] = max(dp[i+1], sum - dp[i+1] + val[i]);//max(不吃， 吃)

其中sum为[i+1~n]蛋糕总质量，最后dp[1]就是AlvinZH获得的最大价值。

注意：
1. 注释里的吃与不吃并不是一直针对同一个人的，指的是当前有选择权的人对当前蛋糕吃与不吃。
2. 整个过程没有管AlvinZH吃还是不吃，针对的对象是有选择权的那个人。

分析：

这道题很有意思，巧妙地避过了选择权在谁手里的问题，dp求解的是有选择权能获得的最大价值，并没有考虑谁有选择权。

逆推也很有意思，因为只知道开始时选择权在AlvinZH手里。

好好理解吧，神奇的DP，你对它一无所知。
*/

int n;
int sum;//表示i+1~n块蛋糕的总量
int val[105], dp[105];

int main()
{
    while(~scanf("%d", &n))
    {
        sum = 0;
        memset(dp, 0, sizeof(dp));

        for(int i = 1; i <= n; ++i)
            scanf("%d", &val[i]);

        for(int i = n; i >= 1; --i)
        {
            dp[i] = max(dp[i + 1], sum - dp[i + 1] + val[i]);//max(不吃, 吃)。
            sum += val[i];
        }
        printf("%d\n", dp[1]);
    }
}
