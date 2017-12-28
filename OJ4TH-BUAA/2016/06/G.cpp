#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
using namespace std;
const double eps=1e-8;
void work()
{
    double r,x1,x2,y1,y2;
    scanf("%lf%lf%lf%lf%lf",&r,&x1,&y1,&x2,&y2);
    double d0=sqrt(pow(x1,2)+pow(y1,2));
    if(fabs(d0)<eps)
    {
        printf("%.3lf\n",2*r);
        return ;
    }
    double k=r*r/(d0*d0);//点P'相对于点P的比值
    double x3=x1*k,x4=x2*k,y3=y1*k,y4=y2*k,ans;//求出来点P'和Q'
    double mx=(x3+x4)/2,my=(y3+y4)/2;//求出点P'和Q'之间的中间点
    double d=sqrt(pow(mx,2)+pow(my,2));//求出中间点到原点之间的距离
    if(d<=r)
    {
        double dist=sqrt(pow(x3-x4,2)+pow(y3-y4,2));//P'和Q'之间的距离
        ans=dist*d0/r;//相似三角形求和
    }
    else
    {
        double kk=r/d;
        double smx=mx*kk,smy=my*kk;//得到点D的x和y
        ans=2*sqrt(pow(smx-x1,2)+pow(smy-y1,2));
    }
    printf("%.3lf\n",ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--) work();
    return 0;
}
