#include <bits/stdc++.h>

using namespace std;
int a[7];

int main()
{
    long long ans;
    while(~scanf("%d%d%d%d%d%d",&a[1],&a[2],&a[3],&a[4],&a[5],&a[6]))
    {
        ans=a[6];
        if(a[5]>0)
        {
            ans=ans+a[5];
            a[1]=a[1]-11*a[5];
        }
        if(a[4]>0)
        {
            ans=ans+a[4];
            if(a[2]>=5*a[4])
                a[2]=a[2]-5*a[4];
            else
            {
                a[1]=a[1]-(20*a[4]-4*a[2]);
                a[2]=0;
            }
        }
        if(a[3]>0)
        {
            if(a[3]%4==0)
                ans=ans+a[3]/4;
            else
            {
                ans=ans+a[3]/4+1;
                if(a[3]%4==1)
                {
                    if(a[2]>=5)
                    {
                        a[2]=a[2]-5;
                        a[1]=a[1]-7;
                    }
                    else
                    {
                        a[1]=a[1]-(27-4*a[2]);
                        a[2]=0;
                    }
                }
                if(a[3]%4==2)
                {
                    if(a[2]>=3)
                    {
                        a[2]=a[2]-3;
                        a[1]=a[1]-6;
                    }
                    else
                    {
                        a[1]=a[1]-(18-4*a[2]);
                        a[2]=0;
                    }
                }
                if(a[3]%4==3)
                {
                    if(a[2]>=1)
                    {
                        a[2]=a[2]-1;
                        a[1]=a[1]-5;
                    }
                    else
                    {
                        a[1]=a[1]-9;
                    }
                }
            }
        }
        if(a[1]<0) a[1]=0;
        if((a[2]*4+a[1])%36==0)
            ans=ans+(a[2]*4+a[1])/36;
        else
            ans=ans+(a[2]*4+a[1])/36+1;
        printf("%lld\n",ans);
    }
}
