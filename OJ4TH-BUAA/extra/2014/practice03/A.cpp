#include <cstdio>
#include <queue>
using namespace std;

int main()
{
    long long res;
    int n;
    while(~scanf("%d",&n)){
        int tmp;    res=0;
        priority_queue<int,vector<int>,greater<int> > qb;
        for(int i=0;i<n;i++)
            scanf("%d",&tmp),qb.push(tmp);
        while(!qb.empty()){
            tmp=qb.top();
            res+=tmp*(--n);
            qb.pop();
        }
        printf("%lld\n",res);
    }
}
