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

struct point{
    double x;
    double y;
}plot[10005];

int main()
{
    int len,a;
    while(~scanf("%d%d",&len,&a)){
        point start;
        scanf("%lf%lf",&start.x,&start.y);
        for(int i=1;i<len;i++){
            scanf("%lf%lf",&plot[i].x,&plot[i].y);
        }

        int left=0,right=0;
        for(int i=1;i<len-1;i++){
            double res = (plot[i].x-start.x)*(plot[i+1].y-start.y) - (plot[i+1].x-start.x)*(plot[i].y-start.y);
            if(res>0){
                left++;
                a+=left;
            }
            else if(res<0){
                right++;
                a-=right;
            }
            start = plot[i];
        }
        printf("%d\n",a);
    }
}
