#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n,t[1001],i,sum;
	while(~scanf("%d",&n))
	{
		sum=0;
		for(i=0;i<n;i++)
			scanf("%d",&t[i]);
		sort(t,t+n);
		for(i=n-1;i>2;i-=2)
		{
			int temp1=t[0]+2*t[1]+t[i];
			int temp2=2*t[0]+t[i-1]+t[i];
			sum+=min(temp1,temp2);
		}

	    if(i==2) sum+=t[0]+t[1]+t[2];
	    else if(i==1) sum+=t[1];
	    else sum+=t[0];

		printf("%d\n",sum);
	}
	return 0;
}
