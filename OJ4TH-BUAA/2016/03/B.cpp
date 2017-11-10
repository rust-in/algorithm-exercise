#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int wei[4][505];
int tab[4][505];
int rod[4][505];
int res[4][505];

int main()
{
    int len;
    while(~scanf("%d",&len)){
        for(int i=0;i<len;i++)  scanf("%d",&wei[1][i]);
        for(int i=0;i<len;i++)  scanf("%d",&wei[2][i]);
        for(int i=0;i<len;i++)  scanf("%d",&wei[3][i]);
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
                scanf("%d",&tab[i][j]);
        res[1][0]=wei[1][0];
        res[2][0]=wei[2][0];
        res[3][0]=wei[3][0];

        for(int j=1;j<len;j++){
            int tmp;
            res[1][j] = min(res[1][j-1],min(res[2][j-1]+tab[2][1],res[3][j-1]+tab[3][1]))+wei[1][j];
            res[2][j] = min(res[2][j-1],min(res[1][j-1]+tab[1][2],res[3][j-1]+tab[3][2]))+wei[2][j];
            res[3][j] = min(res[3][j-1],min(res[1][j-1]+tab[1][3],res[2][j-1]+tab[2][3]))+wei[3][j];
        }
        printf("%d\n",min(res[1][len-1],min(res[2][len-1],res[3][len-1])));
    }
}
