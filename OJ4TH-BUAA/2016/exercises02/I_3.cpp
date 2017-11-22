#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int m, n;
int M[201][201];
int dp[2][201][201];
inline int MAX(int a, int b, int c, int d)
{
    int minAns = a;
    if(minAns < b) minAns = b;
    if(minAns < c) minAns = c;
    if(minAns < d) minAns = d;
    return minAns;
}

int main()
{
    while(~scanf("%d%d", &n, &m)){
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d", &M[i][j]);//����ÿһ��ֻ��ǰһ���йأ� ���Թ������飬 ��һά��������
        int cur = 0;
        for (int i = 2; i <= n + m; i++) {
            cur ^= 1;
            for (int j = 1; j <= n&&i - j >= 0; j++) {
                for (int k = 1; k <= n&&i - k >= 0; k++) { //���£� ���ң� ���£� ��������ȡ���ֵ
                    dp[cur][j][k] = MAX(dp[cur^1][j - 1][k - 1], dp[cur^1][j][k - 1], dp[cur^1][j - 1][k], dp[cur^1][j][k]);
                    if (j == k)//�ߵ�ͬһ�У� �ض���ͬһ�У� ����ȷ����A[j][i - j]һ��
                        dp[cur][j][k] += M[j][i - j];
                    else//�ߵ���ͬ�У� ����ȷ����A[j][i - j]�� A[k][i - k]���㡣
                        dp[cur][j][k] += (M[j][i - j] + M[k][i - k]);//����
                }
            }
        }
        printf("%d\n",dp[cur][n][n]);
    }
}
