#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int left[105],right[105]; //存储左右木条中高度为相应值时的位置。

    int len;
    while(~scanf("%d",&len)){
        for(int i=0;i<105;i++){ //设置每个高度的位置峰值
            left[i]=1;
            right[i]=-1;
        }

        int pot,height;
        for(int i=0;i<len;i++){
            scanf("%d %d",&pot,&height);
            if(pot<left[height])    left[height]=pot; //更新该高度下离原点最远的点
            if(pot>right[height])   right[height]=pot;
        }

        int l=1,r=-1,v=0;
        for(int i=100;i>0;i--){ //遍历所有高度
            l=min(left[i],l);
            r=max(right[i],r);

            if(l<=0&&r>=0)
                v=max(v,(r-l)*(r-l)*i);
        }

        double res = (double)v/4*acos(-1);
        printf("%.3f\n",res);
    }
}
