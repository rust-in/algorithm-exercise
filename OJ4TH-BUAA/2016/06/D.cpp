#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#define MAXN 100005
using namespace std;

struct pp
{
    char name[105];
    double x,y;
}num[MAXN];

double cross(pp p0,pp p1,pp p2) //计算叉积  p0p1 X p0p2
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}

double dis(pp p1,pp p2)  //计算 p1p2的 距离
{
    return sqrt((double)(p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
}

bool cmp(pp p1,pp p2) //极角排序函数 ， 角度相同则距离小的在前面
{
    double tmp=cross(num[0],p1,p2);
    if(tmp>0) return true;
    else if(tmp==0&&dis(num[0],p1)<dis(num[0],p2)) return true;
    else return false;
}

void init(int n)
{
    int i;

    for(i=1;i<=n;i++)
    {
//        num[i].name = new char[100000];
        scanf("%s%lf%lf",num[i].name,&num[i].x,&num[i].y);
    }

    num[0].x=0;
    num[0].y=0;

    sort(num+1,num+n+1,cmp);
}

int main()
{
    int len;
    while(~scanf("%d",&len)){
        init(len);
        for(int i=1;i<=len;i++)
            printf("%s\n",num[i].name);
        printf("\n");
    }

}
