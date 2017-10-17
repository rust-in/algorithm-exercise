#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int left[105],right[105]; //�洢����ľ���и߶�Ϊ��Ӧֵʱ��λ�á�

    int len;
    while(~scanf("%d",&len)){
        for(int i=0;i<105;i++){ //����ÿ���߶ȵ�λ�÷�ֵ
            left[i]=1;
            right[i]=-1;
        }

        int pot,height;
        for(int i=0;i<len;i++){
            scanf("%d %d",&pot,&height);
            if(pot<left[height])    left[height]=pot; //���¸ø߶�����ԭ����Զ�ĵ�
            if(pot>right[height])   right[height]=pot;
        }

        int l=1,r=-1,v=0;
        for(int i=100;i>0;i--){ //�������и߶�
            l=min(left[i],l);
            r=max(right[i],r);

            if(l<=0&&r>=0)
                v=max(v,(r-l)*(r-l)*i);
        }

        double res = (double)v/4*acos(-1);
        printf("%.3f\n",res);
    }
}
