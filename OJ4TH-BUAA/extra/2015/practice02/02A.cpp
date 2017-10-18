#include <cstdio>
using namespace std;

int num[1000005];
int nu=0;

bool isPrimary(int a)
{
    for(int i=0;num[i]*num[i]<=a;i++)
        if(a%num[i]==0)
            return false;
    return true;
}

int main()
{
    num[0]=2;   nu=1;
    for(int i=3;i<=1000000;i++){
        if(isPrimary(i))
            num[nu++]=i;
    }

//    for(int i=0;i<100;i++)
//        printf("%d ",num[i]);

    int tmp;
    while(~scanf("%d",&tmp)){

        int j;
        for(j=0;j<nu;j++)
            if(num[j]>tmp)
                break;
        printf("%d\n",j);
    }
}
