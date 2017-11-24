#include <cstdio>
#include <algorithm>
using namespace std;

struct node
{
    int s;
    int f;
} num[100005];

bool cmp(node a, node b)
{
    if(a.f==b.f)    return a.s<b.s;
    return a.f<b.f;
}

int main()
{
    int len;
    while(~scanf("%d",&len)){
        for(int i=0;i<len;i++)  scanf("%d%d",&num[i].s,&num[i].f);
        sort(num,num+len,cmp);
        int i=1,j=0;
        int ans=1;
        for(;i<len;i++){
            if(num[i].s>=num[j].f){
                ans++;
                j=i;
            }
        }
        printf("%d\n",ans);
    }
}
