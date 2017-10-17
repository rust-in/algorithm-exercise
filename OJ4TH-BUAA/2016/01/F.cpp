#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

struct node
{
    int pot;
    int len;
};

bool cmp(node a, node b)
{
    return a.pot < b.pot;
}

node num[105];

int main()
{
    int length;
    while(~scanf("%d",&length)){
        for(int i=0;i<length;i++)
            scanf("%d %d",&num[i].pot,&num[i].len);
        sort(num,num+length,cmp);

        int lpot=0,lmax=0;  //左边杆的起点；左边杆的最高高度
        int maxV=0; //最大体积

        while(num[lpot].pot<=0 && lpot<=length-1){
            if(num[lpot].len>lmax){
                lmax = num[lpot].len;

                int rpot = length-1; //右边杆的起点
                int rmax=0; //右边杆的最高高度

                while(num[rpot].pot>=0 && rpot>=0){
                    if(num[rpot].len>rmax){
                        rmax = num[rpot].len;
                        maxV = max((num[rpot].pot-num[lpot].pot)*(num[rpot].pot-num[lpot].pot)*min(lmax,rmax),maxV);
                        if(lmax<rmax)
                            break;
                    }
                    rpot--;
                }
            }
            lpot++;
        }

        double res = (double)maxV/4 * acos(-1);
        printf("%.3f\n",res);
    }
}
