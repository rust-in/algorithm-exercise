#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int N;
    double f[111][111];//f[i][j]表示玩了i盘，共赢了j盘的概率
    while(~scanf("%d",&N))
    {
        while(N--)
        {
            int i,j,k,n,m,x,y;
            double p,q;
            scanf("%d/%d%d",&x,&y,&n);
            p=(double)x/(double)y;
            memset(f,0,sizeof(f));
            f[0][0]=1;
            for(i=1;i<=n;i++)
            {
                f[i][0]=f[i-1][0]*(1-p);
                for(j=1;j*y<=i*x;j++)
                {
                    f[i][j]=f[i-1][j]*(1-p)+f[i-1][j-1]*p;
                }
            }
            q=0;
            for(i=0;i*y<=n*x;i++)
                q+=f[n][i];
            int result=1/q;
            printf("%d\n",result);
        }
    }
}
