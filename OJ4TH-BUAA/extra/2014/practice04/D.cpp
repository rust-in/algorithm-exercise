#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#define max_size 10010

using namespace std;

typedef long long LL;
char c[max_size];
long long f[max_size];

priority_queue<LL ,vector<LL>,greater<LL> >q;//����С���ѣ�
long long n,ans;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        string s;
        cin>>s;
        getchar();
        memset(f,0,sizeof(f));
        int lens=s.size();
        for(int i=1; i<=lens; i++)
        {
            c[i]=s[i-1];
            f[c[i]]++;
        }

        while(!q.empty())
            q.pop();
        for(int i=65; i<=122; i++)
        {
            if(f[char(i)]>0)
                q.push(f[char(i)]);
        }
        ans=0;
        while(q.size()>1)
        {
            LL a=q.top();
            q.pop();
            LL b=q.top();
            q.pop();
            ans+=(a+b); // ��Ϊ���볤�Ⱥ��������еĲ������
            q.push(a+b);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
