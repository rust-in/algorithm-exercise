#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <climits>
using namespace std;

struct pot
{
    double x,y;
    bool flag;
}plot[200005];

int len,arr[200005];

double dis(pot a, pot b)
{
    if(a.flag!=b.flag)
        return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
    else
        return LONG_MAX;
}

bool cmp_y(int a,int b)
{
    return plot[a].y<plot[b].y;
}
double contMin(int l, int r)
{
    if(r-1==l)  return dis(plot[l], plot[r]);
    else if(r-2==l) return min(dis(plot[l],plot[r]), min(dis(plot[l],plot[l+1]),dis(plot[l+1],plot[r])));

    int mid=(l+r)/2;
    double res=min(contMin(l,mid),contMin(mid+1,r));

    int cnt=0;
    for(int i=l;i<=r;i++)
    {
        if(plot[i].x>=(plot[mid].x-res)&&plot[i].x<=(plot[mid].x+res))
            arr[cnt++]=i;
    }

    sort(arr,arr+cnt,cmp_y);
    for(int i=0;i<cnt-1;i++)
        for(int j=i+1;j<cnt;j++)
        {
            if(plot[arr[j]].y-plot[arr[i]].y>=res)
                break;
            res=min(res,dis(plot[arr[i]],plot[arr[j]]));
        }


    return res;
}

bool cmp(pot a, pot b)
{
    return a.x < b.x;
}

int main()
{
    long k;
    scanf("%ld",&k);
    while(k--){
        scanf("%d",&len);
        int i=0;
        for(;i<2*len;i++)
        {
            pot tmp;
            scanf("%lf %lf", &plot[i].x, &plot[i].y);
            plot[i].flag=i<len?true:false;
        }
        sort(plot,plot+2*len,cmp);
        printf("%.3lf\n", contMin(0,2*len-1));
    }
}
