#include<queue>
#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
using namespace std;
int abc[801][801];
int x[601],y[601];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(abc,0,sizeof(abc));
		int i,j;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
			x[i]+=400;
			y[i]+=400;
			abc[x[i]][y[i]]=1;
		}
		int ans=0;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				int abx=x[j]-x[i],aby=y[j]-y[i];

				if(abc[x[j]+abx][y[j]-aby]&&abc[x[i]+aby][y[i]-abx])
					ans++;
				if(abc[x[j]-aby][y[j]+abx]&&abc[x[i]-aby][y[i]+abx])
					ans++;
			}
		}
		cout << ans/4 << endl;
	}
	return 0;
}
