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

struct pp
{
    double x;
    double y;
};

double dis(pp p1,pp p2){ //¾àÀë
    return sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
}

double cross(pp p0,pp p1,pp p2){ //²æ»ý
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}

int main()
{
    int len;
    scanf("%d",&len);

    double radius;
    pp O;   O.x=0;  O.y=0; //Ô­µã
    pp one,two;
    while(len--){
        scanf("%lf",&radius);
        scanf("%lf%lf%lf%lf",&one.x,&one.y,&two.x,&two.y);

        if(dis(one,O)==0){
            printf("%.3lf\n",2*radius);
            continue;
        }

        double sma_r = dis(one,O);

        pp three, four;
        three.x = pow(radius,2)/pow(sma_r,2) * one.x; three.y = pow(radius,2)/pow(sma_r,2) * one.y,
        four.x= pow(radius,2)/pow(sma_r,2) * two.x;   four.y = pow(radius,2)/pow(sma_r,2) * two.y;

        pp fin; fin.x = (three.x + four.x) /2;  fin.y = (three.y+four.y)/2;
        double flag = dis(fin,O);

        double res;
        if(flag-radius<=0)
            res = dis(three,four);
        else
            res = 2*sqrt((flag-radius)*(flag-radius)+(fin.x-three.x)*(fin.x-three.x)*(fin.y-three.y)*(fin.y-three.y));
        printf("%lf\n",res);
    }

}
