#include<iostream>
#include<cstdio>
#include<algorithm>
#include <cmath>
using namespace std;

#define INF -110
long long i,j,k,n,top,ans;

struct Node
{
 int x;
 int y;
}no[1000010],stack[1000010];

long long dis(Node p1,Node p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

long long mult(Node p1,Node p2,Node p0)
{
    return ((p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y));
}

long long cmp(Node a,Node b)
{
    if(mult(a,b,no[0])>0)
        return 1;
    else if(mult(a,b,no[0])==0&&dis(a,no[0])<dis(b,no[0]))
        return 1;
    return 0;
}

void work()
{
    k=0;
    for(i=1; i<n; i++)
    {
        if(no[k].y>no[i].y || ((no[k].y == no[i].y) && no[k].x > no[i].x))
            k = i;
    }
    Node tmp;
    tmp = no[0];
    no[0] = no[k];
    no[k] = tmp;
    sort(no+1,no+n,cmp);
    top = 2;
    stack[0] = no[0];
    stack[1] = no[1];
    stack[2] = no[2];
    for(i=3; i<n; i++)
    {
        while(top>1 && mult(no[i],stack[top],stack[top-1])>=0)
            top--;
        stack[++top] = no[i];
    }
}

int main()
{
    while(~scanf("%lld",&n))
    {
        for(i=0; i<n; i++)
            scanf("%lld%lld",&no[i].x,&no[i].y);
        work();
        ans=INF;
        //最远点对
        for(i=0; i<=top; i++)
        {
            for(j=i+1; j<=top; j++)
            {
                if(ans<dis(stack[i],stack[j]))
                    ans=dis(stack[i],stack[j]);
            }
        }
        printf("%lld\n",ans);

        //周长
        double perimeter=0;
        for(int i=0;i<top;i++){
            perimeter+=dis(stack[i],stack[i+1]);
        }
        perimeter+=dis(stack[top],stack[0]);
        printf("%lf\n",perimeter);
    }
    return 0;
}
