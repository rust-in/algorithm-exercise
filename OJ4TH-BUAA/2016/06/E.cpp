#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#include <climits>
#include <ctime>
#define INF 1e20
using namespace std;

struct Point
{
    double x;
    double y;
}plot[100005];

int tmpt[100005];

bool cmp(const Point& a, const Point& b)
{
    if(a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}

bool cmpy(const int& a, const int& b)
{
    return plot[a].y < plot[b].y;
}

double dist(int i, int j)
{
    return sqrt((plot[i].x-plot[j].x)*(plot[i].x-plot[j].x)
                + (plot[i].y-plot[j].y)*(plot[i].y-plot[j].y));
}

double nearest(int left, int right)
{
    double d = INF;
    if(left==right)
        return d;
    if(left + 1 == right)
        return dist(left, right);
    int mid = (left+right)>>1;
    double d1 = nearest(left,mid);
    double d2 = nearest(mid+1,right);
    d = min(d1,d2);
    int i,j,k=0;
    //分离出宽度为d的区间
    for(i = left; i <= right; i++)
    {
        if(fabs(plot[mid].x-plot[i].x) <= d)
            tmpt[k++] = i;
    }
    sort(tmpt,tmpt+k,cmpy);
    //线性扫描
    for(i = 0; i < k; i++)
    {
        for(j = i+1; j < k && plot[tmpt[j]].y-plot[tmpt[i]].y<d; j++)
        {
            double d3 = dist(tmpt[i],tmpt[j]);
            if(d > d3)
                d = d3;
        }
    }
    return d;
}


int main()
{
    int len;
    while(~scanf("%d",&len))
    {
        for(int i = 0; i < len; i++)
            scanf("%lf %lf",&plot[i].x,&plot[i].y);

        sort(plot,plot+len,cmp);
        double res = nearest(0,len-1);
        printf("%.2lf\n",res);
    }
    return 0;
}
