#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

long long arr[1000001];

long long Counter(long long n)
{
    if(n==1)
    {
        arr[1]=1;
        return arr[1];
    }
    if(arr[n]!=0)//��arr[n]���е������ֱ������
        return arr[n];
    else
    {
        arr[n]=arr[n/2]+1;//arr[n]û�е�����¼���arr[n]
        return Counter(n/2)+1;
    }
}
int main()
{
    memset(arr,0,sizeof(arr));
    long long n;
    while(scanf("%lld",&n)!=EOF)
    {
        printf("%lld\n",Counter(n));
    }
}
