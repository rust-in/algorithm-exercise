#include <bits/stdc++.h>
#define eps 1e-6
#define MAX 100010

using namespace std;

int sgn(double x)
{
    if(fabs(x)<eps)
        return 0;
    if(x<0)
        return -1;
    else return 1;
}

struct Point
{
    double x,y;
    Point() {}
    Point(double x1,double y1)
    {
        x=x1;
        y=y1;
    }
    Point operator -(Point b)
    {
        return Point(x-b.x,y-b.y);
    }
    double operator ^(const Point b)
    {
        return x*b.y-y*b.x;
    }
    double operator *(Point b)
    {
        return x*b.x+y*b.y;
    }
};

struct Line
{
    Point start,over;
    Line() {}
    Line(Point start1,Point over1)
    {
        start=start1;
        over=over1;
    }
};

bool cs(Line l1,Line l2)
{
    return
        ( max(l1.start.x,l1.over.x)>=min(l2.start.x,l2.over.x)
        &&max(l2.start.x,l2.over.x)>=min(l1.start.x,l1.over.x)
        &&max(l1.start.y,l1.over.y)>=min(l2.start.y,l2.over.y)
        &&max(l2.start.y,l2.over.y)>=min(l1.start.y,l1.over.y)
        &&sgn((l2.start-l1.start)^(l1.over-l1.start))*sgn((l2.over-l1.start)^(l1.over-l1.start))<=0
        &&sgn((l1.start-l2.start)^(l2.over-l2.start))*sgn((l1.over-l2.start)^(l2.over-l2.start))<=0 );
}

Line line[MAX];
bool flag[MAX];
int main()
{
    int n,i,j;
    double x1,y1,x2,y2;
    while(~scanf("%d",&n))
    {
        for(i=1;i<=n;i++)
        {
            scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
            line[i]=Line(Point(x1,y1),Point(x2,y2));
            flag[i]=true;
        }
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
                if(cs(line[i],line[j]))
                {
                    flag[i]=false;
                    break;
                }
        }
        for(i=1;i<=n;i++)
        {
            if(flag[i])
            {
                printf("%d ",i);
            }
        }
        printf("\n");
    }
    return 0;
}
