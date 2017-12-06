#include <cstdio>
using namespace std;

int coin[] = {1,5,10,50,100,500};
int num[6];

int main()
{
    while(~scanf("%d",&num[0])){
        for(int i=1;i<6;i++)    scanf("%d",&num[i]);
        int sum;    scanf("%d",&sum);
        int res=0;
        for(int i=5;i>=0;i--){
            while(sum>=coin[i]&&num[i]>0){
                num[i]--;
                sum-=coin[i];
                res++;
            }
        }
        printf("%d\n",res);
    }
}
