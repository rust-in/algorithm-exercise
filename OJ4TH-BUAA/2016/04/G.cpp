#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
#define ll long long
#define inf 10000050
#define maxn 100060
int a[maxn],dp[maxn],c[maxn];
int main()
{
    int n,m,i,j,len,d,maxx;
    while(scanf("%d%d",&n,&d)!=EOF)
    {
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            c[i]=inf;
        }
        maxx=1;
        for(i=1;i<=n;i++){
            dp[i]=lower_bound(c+1,c+1+n,a[i])-c;
            maxx=max(maxx,dp[i]);//�������ֵ����Ϊ�����������һ����
            j=i-d;
            if(j>=1 && c[dp[j] ]>a[j]){  //��j���½�ȥ��dp[j]����ѭ����jʱ�������
                c[dp[j] ]=a[j];
            }
        }
        printf("%d\n",maxx);
    }
    return 0;
}
