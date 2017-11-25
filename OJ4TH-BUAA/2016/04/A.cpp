#include <cstdio>
#include <climits>
#define MAX 1000
using namespace std;

int minres[MAX][MAX];
int route[MAX][MAX];
int length[MAX+1];
int len;

void matrix(int len,int minres[][MAX], int route[][MAX], int length[])
{
    for(int i=1;i<=len;i++) minres[i][i]=0; //若从0开始，则=0，<len
    for(int l=2;l<=len;l++)
        for(int i=1;i<=len-l+1;i++){ //若从0开始，则=0，<len
            int r = i+l-1;
            minres[i][r]=INT_MAX;
            for(int j=i;j<r;j++){
                int tmp = minres[i][j]+minres[j+1][r]+length[i-1]*length[j]*length[r];
                if(minres[i][r]>=tmp){ //注意比较符号，>=使结果相同时，括号靠前
                    minres[i][r]=tmp;
                    route[i][r]=j;
                }
            }
        }
}

void printRoute(int route[][MAX], int l, int r)
{
    if(l==r)
        printf("A%d",l);
    else{
        printf("(");
        printRoute(route, l, route[l][r]);
        printRoute(route, route[l][r]+1, r);
        printf(")");
    }
}

int main()
{
    while(~scanf("%d",&len)){
        for(int i=0;i<=len;i++) scanf("%d",&length[i]);
        matrix(len, minres, route, length);
        printf("%d\n",minres[1][len]);
        printRoute(route, 1, len);
        printf("\n");
    }
}
