#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
void paint(int dist,int size,int height);
int n;
char tri[(1<<10)+1][(1<<10)+1];
int main()
{
    scanf("%d",&n);
    memset(tri,' ',sizeof(tri));
    int t=1<<n;                                  //整个三角形的尺寸
    paint(0,n,t);
    for(int i=1;i<=t;i++)
    {
        for(int j=1;j<=t*2;j++)
            printf("%c",tri[i][j]);
        printf("\n");
    }
    return 0;
}
void paint(int dist,int size,int height)
{
    if(size==1)
    {
        tri[height-1][dist+2]='/';
        tri[height-1][dist+3]=(char)92;
        tri[height][dist+1]='/';
        tri[height][dist+2]=tri[height][dist+3]='_';
        tri[height][dist+4]=(char)92;
        return;
    }
    else
    {
        paint(dist+(1<<(size-2))*2,size-1,height-(1<<(size-1)));            //顶部三角形
        paint(dist,size-1,height);                                                           //左下三角形
        paint(dist+4*(1<<(size-2)),size-1,height);                                 //右下三角形
    }
}
