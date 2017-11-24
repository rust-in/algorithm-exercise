#include <cstdio>
#include <algorithm>
using namespace std;

int cas[] = {1,5,10,20,50,100};

int main()
{
    int num[6];
    int cos;
    while(~scanf("%d",&num[0])){
        for(int i=1;i<6;i++)    scanf("%d",&num[i]);
        scanf("%d",&cos);
        int pac[cos+1];     pac[0]=0;
        for(int i=1;i<cos+1;i++)    pac[i]=5000;
        for(int i=0;i<6;i++)
            for(int j=0;j<num[i];j++)
                for(int k=cos;k>=cas[i];k--)
                    pac[k]=min(pac[k], pac[k-cas[i]]+1);
        printf("%d\n", pac[cos]);
    }
}
