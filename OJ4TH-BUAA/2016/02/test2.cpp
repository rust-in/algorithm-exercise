#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;
#define M 3000010
#define MAXN 1000010
int minFactor[M], prime[M], primeNum;
void calPrime()
{
    for (int i = 2; i < MAXN; i++)
    {
        if (!minFactor[i])
        {
            prime[primeNum++] = i;
            minFactor[i] = primeNum;
        }
        for (int j = 1; j <= minFactor[i]; j++)
        {
            int t = i * prime[j - 1];
            if (t >= MAXN)break;
            minFactor[t] = j;
        }
    }
}
long long  a[M], num[M], sum[M];
int main(void)
{
    calPrime();
    long long n, x, y;
    cin >> n >> x >> y;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        a[tmp]++;
    }
    for(int i = 1; i < M; i++)
    {
        num[i] = num[i - 1] + a[i];
        sum[i] = sum[i - 1] + 1ll * i * a[i];
    }
    long long ans = LLONG_MAX;
    int move = (x + y - 1) / y;
    for(int i = 0; i < primeNum; i++)
    {
        long long tmp = 0;
        int p = prime[i];
        for(int j = 0; j <= p + MAXN; j += p)
        {
            tmp += (num[j + max(p - move, 0)] - num[j]) * x;
            tmp += ((num[j + p - 1] - num[j + max(p - move , 0)]) * (j + p) - (sum[j + p - 1] - sum[j +  max(p - move, 0)])) * y;
        }
        if(tmp < ans) ans = tmp;
    }
    cout << ans << endl;
    return 0;
}
