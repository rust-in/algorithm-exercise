#include <cstdio>
using namespace std;

long ans[55][55];

long abc(int a,int b)
{
    if(!ans[a][b])
        ans[a][b]=abc(a,b-1)+abc(a,b-2);

    return ans[a][b];
}
int main()
{
    for(int i=1;i<50;i++)
    {
        ans[i][i+1]=1;
        ans[i][i+2]=2;
    }

    int a,b,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        printf("%ld\n",abc(a,b));
    }

}
