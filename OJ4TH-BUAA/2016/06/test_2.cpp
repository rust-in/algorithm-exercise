#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const double eps = 1e-8;

int sgn(double x)
{
    if(fabs(x)<eps) return 0;
    if(x > 0 ) return 1;
    else return -1;
}

double judge()
{
    double R,x1,y1,x2,y2;
    scanf("%lf%lf%lf%lf%lf",&R,&x1,&y1,&x2,&y2);
    double r = sqrt(x1*x1+y1*y1);

    if(sgn(r) == 0) return 2*R;

    double k = (R*R)/(r*r);
    double x3,y3,x4,y4,mx,my,dis,ans;
    x3 = k*x1;  y3 = k*y1;        //反演点p'
    x4 = k*x2;  y4 = k*y2;        //反演点q'
    mx = (x3+x4)/2;
    my = (y3+y4)/2;
    dis = sqrt(mx*mx+my*my);

    if(sgn(dis-R)<=0){
        ans = sqrt((x4-x3)*(x4-x3)+(y4-y3)*(y4-y3));
    }else{
        ans = 2*sqrt((dis-R)*(dis-R)+(mx-x3)*(mx-x3)+(my-y3)*(my-y3));
    }

    return ans*r/R;
}

int main()
{
    int T;
    scanf("%d",&T);
    while( T-- ){
        printf("%.7lf\n",judge());
    }
    return 0;
}

int main()
{
    int t;scanf("%d", &t);
    while (t--)
    {
        double r;
        scanf("%lf", &r);
        Pos p, q;
        scanf("%lf%lf%lf%lf", &p._x, &p._y, &q._x, &q._y);
        double Dpq = (p._x - q._x)*(p._x - q._x) + (p._y - q._y)*(p._y - q._y);
        double Dop = p._x*p._x + p._y*p._y;
        if (Dop < 1e-6)//特判两个点在圆心
            printf("%.7f\n", 2 * r);
        else if (r*r*(Dop - Dpq / 4) / (Dop*Dop) >= 1)
            printf("%.7f\n", 2*sqrt(r*r-2*r*sqrt(Dop-Dpq/4)+Dop)+1e-8);//直接在中垂线上求PD+QD
        else
            printf("%.7f\n", r * sqrt(Dpq/Dop)+1e-8);//P'Q'之间的距离乘上系数
    }
    return 0;
}
