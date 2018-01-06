#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int wei[3][505]; //记录停留所需时间
int tab[3][505]; //记录换边所需时间
int rod[3][505]; //记录最优解
int res[3][505]; //记录路径

int main()
{
    int len;
    while(~scanf("%d",&len)){
        for(int i=0;i<len;i++)  scanf("%d",&wei[1][i]);
        for(int i=0;i<len;i++)  scanf("%d",&wei[2][i]);
        for(int i=1;i<len;i++)  scanf("%d",&tab[1][i]);
        for(int i=1;i<len;i++)  scanf("%d",&tab[2][i]);

        res[1][0]=wei[1][0];    res[2][0]=wei[2][0];
        for(int j=1;j<len;j++){
            res[1][j]=min(res[1][j-1],res[2][j-1]+tab[2][j])+wei[1][j];
            res[2][j]=min(res[2][j-1],res[1][j-1]+tab[1][j])+wei[2][j];
        }
        printf("%d\n",min(res[1][len-1],res[2][len-1]));
    }
}
