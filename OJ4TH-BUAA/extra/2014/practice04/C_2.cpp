#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d,e,f,x,y;
    int sum;
    int u[4]= {0, 5, 3, 1}; //��Ӧ���ǵ�c%4 = 0, 1, 2, 3 ʱ��ʣ��ռ�ɷ�2*2��С�ĸ���

    while(~scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f))
    {
        sum = 0;
        if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0)
            break;
        sum = f; //ÿ������ֻ��תһ��6*6��
        sum += e;//ÿ������ֻ��װһ��5*5��
        sum += d;//ÿ������ֻ��װһ��4*4��
        sum += (c+3)/4;//ÿ����������װ4�� 3*3��
        y = 5*d + u[c%4];
        if(b>y)
            sum += (b-y+8)/9;
        x = sum *36 - f*36 -e*25 - d*16 - c*9 - b*4;
        if(a>x)
            sum += (a-x+35)/36;

        printf("%d\n",sum);
    }
}
