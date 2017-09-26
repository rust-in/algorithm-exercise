#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 40001
using namespace std;
int a[N],tmp[N],n;
long long ans;
int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9')  {     if(ch=='-') f=-1; ch=getchar();}
    while(ch<='9'&&ch>='0'){  x=x*10+ch-'0'; ch=getchar();}
    return f*x;
}
void gsort(int l,int r)
{
    if(l==r) return ;
    int mid=(l+r)/2;
    gsort(l,mid),gsort(mid+1,r);
    int i=l,j=mid+1,k=l;
    while(i<=mid&&j<=r)
    {
        if(a[i]<=a[j]) tmp[k++]=a[i++];
        else{
            ans+=mid-i+1;
            tmp[k++]=a[j++];
        }
    }
    while(i<=mid) tmp[k++]=a[i++];
    while(j<=r) tmp[k++]=a[j++];
    for(int i=l;i<=r;i++) a[i]=tmp[i];
}
int main()
{
    n=read();
    for(int i=1;i<=n;i++)
     a[i]=read();
    gsort(1,n);
    cout<<ans;
    return 0;
}
