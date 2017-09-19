#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int money;
void cont(int rate,int num)
{

}
int main()
{
    int cnt[6];
    int cash[6]={1,5,10,50,100,500};

    while(~scanf("%d %d %d %d %d %d",&cnt[0],&cnt[1],&cnt[2],&cnt[3],&cnt[4],&cnt[5])){
        int res=0;
        scanf("%d",&money);
        for(int i=5;i>=0;i--){
            int tmp=min(cnt[i],money/cash[i]);
            money-=tmp*cash[i];
            res+=tmp;
            if(money==0) break;
        }
        printf("%d\n",res);
    }
}
