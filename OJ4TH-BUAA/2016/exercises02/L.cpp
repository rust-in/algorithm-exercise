#include <cstdio>
#include <cstring>
#define MaxSize 50005
#define MOD 1000007
#define f(x) (((x) * (3 * (x) - 1)) >> 1)
#define g(x) (((x) * (3 * (x) + 1)) >> 1)

using namespace std;

int n, ans[MaxSize];

void init()
{
    memset(ans, 0, sizeof(ans));
    ans[0] = 1;
    for (int i = 1; i <= 50000; ++i) {
        for (int j = 1; f(j) <= i; ++j) {
            if (j & 1)
                ans[i] = (ans[i] + ans[i - f(j)]) % MOD;
            else
                ans[i] = (ans[i] - ans[i - f(j)] + MOD) % MOD;
        }
        for (int j = 1; g(j) <= i; ++j) {
            if (j & 1)
                ans[i] = (ans[i] + ans[i - g(j)]) % MOD;
            else
                ans[i] = (ans[i] - ans[i - g(j)] + MOD) % MOD;
        }
    }
}

int main()
{
    init();
    while (~scanf("%d", &n))
    {
        printf("%d\n", ans[n]);
    }
}

/*
 * ŷ������ζ���P(n)��ʾn�Ļ���������
 * P(n) = ��{P(n - k(3k - 1) / 2 + P(n - k(3k + 1) / 2 | k �� 1}
 * n < 0ʱ��P(n) = 0��n = 0ʱ, P(n) = 1���ɡ�
 */
