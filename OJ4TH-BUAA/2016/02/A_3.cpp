#include<cstdio>
#include<algorithm>
using namespace std;

struct node //ʹ�ýṹ����������
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
    while(l>=0&&num[l].r>=x)l--; //�������д��ڸ�Ԫ�أ��򷵻�С�ڸ�Ԫ�ص�λ��
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
