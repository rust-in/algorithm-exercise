#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d,e,f,x,y;
    int sum;
    int u[4]= {0, 5, 3, 1}; //对应的是当c%4 = 0, 1, 2, 3 时，剩余空间可放2*2大小的个数

    while(~scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f))
    {
        sum = 0;
        if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0)
            break;
        sum = f; //每个包裹只能转一个6*6的
        sum += e;//每个包裹只能装一个5*5的
        sum += d;//每个包裹只能装一个4*4的
        sum += (c+3)/4;//每个包裹可以装4个 3*3的
        y = 5*d + u[c%4];
        if(b>y)
            sum += (b-y+8)/9;
        x = sum *36 - f*36 -e*25 - d*16 - c*9 - b*4;
        if(a>x)
            sum += (a-x+35)/36;

        printf("%d\n",sum);
    }
}
