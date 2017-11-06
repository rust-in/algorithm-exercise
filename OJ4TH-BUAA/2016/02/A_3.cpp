#include<cstdio>
#include<algorithm>
using namespace std;

struct node //使用结构体数组排序
{
    int l;
    int r;
};
node num[50005];

bool cmp(node a,node b)
{
    if(a.r==b.r)
        return a.l<b.l;
    return a.r<b.r;
}

int downerBound(int l,int r,int x)
{
    int mid;
    while(l<r)
    {
        mid=(l+r)/2;
        if(num[mid].r>=x)r=mid;
        else l=mid+1;
    }
    while(l>=0&&num[l].r>=x)l--; //若数组中存在该元素，则返回小于该元素的位置
    return l;
}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int ans=n;
        for(int i=0;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            num[i].l=x-y;num[i].r=x+y;
        }
        sort(num,num+n,cmp);
        for(int i=0;i<n;i++)ans+=downerBound(0,i,num[i].l);
        printf("%d\n",ans);
    }
}
