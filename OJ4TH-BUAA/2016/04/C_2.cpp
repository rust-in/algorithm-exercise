#include <cstdio>
using namespace std;

int num[6];

int main()
{
    int n;
    while(~scanf("%d",&n)){
        int a=1;
        for(int i=1;i<=6;i++){
            n+=a;
            a*=3;
        }
        a/=3;
        for(int i=0;i<6;i++){
            num[i]=n/a;
            n-=num[i]*a;
            a/=3;
        }
        a=243;  bool flag=false;
        for(int i=0;i<6;i++){
            if(num[i]==0)
                printf("-%d",a);
            else if(num[i]==2){
                if(!flag){
                    flag=true;
                    printf("%d",a);
                } else
                    printf("+%d",a);
            }
            a/=3;
        }
        putchar('\n');
    }
}
