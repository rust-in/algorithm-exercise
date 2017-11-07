#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

#define maxn 1000+10
struct node
{
	int x, y;
}p[maxn];
int n;
double ans;
double d[maxn][maxn];
double dis[maxn][maxn];
//表示1到max(i,j)均已经走过，第一个人在i,第二个人在j，还需要走多长的距离
double dist(int i,int j)
{
	if(dis[i][j]>=0) return dis[i][j];
	int dx=p[i].x-p[j].x;
	int dy=p[i].y-p[j].y;
	return dis[i][j]=hypot(dx,dy);
}
double dp(int i,int j)
{
	if(d[i][j]>0) return d[i][j];
	if(i==n-1)
		return d[i][j]=dist(i,n)+dist(j,n);
	d[i][j]=min(dp(i+1,j)+dist(i,i+1),dp(i+1,i)+dist(j,i+1));
	return d[i][j];
}
int main()
{
	while(~scanf("%d",&n))
	{
		memset(d,-1,sizeof(d));
		memset(dis,-1,sizeof(dis));
		for(int i=1;i<=n;i++)
			scanf("%d%d",&p[i].x,&p[i].y);

		dp(2,1);
		ans=dist(1,2)+d[2][1];
		printf("%.2lf\n",ans);
	}
	return 0;
}
