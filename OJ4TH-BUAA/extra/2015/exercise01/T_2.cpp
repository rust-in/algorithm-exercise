#include<stdio.h>
int v[207],w[207],num[207],ans[30007];
int n,i,j,V,N;
int max(int x,int y){return x>y?x:y;}
void ZeroOnePack(int weight,int value)
{
    for(j=V;j>=weight;j--)
        ans[j]=max(ans[j],ans[j-weight]+value);
}
void CompletePack(int weight,int value)
{
    for(j=weight;j<=value;j++)
        ans[j]=max(ans[j],ans[j-weight]+value);
}
void MultiplePack(int weight,int value,int number)
{
    if(weight*number>=V)
        CompletePack(weight,value);
    else
    {
        int k=1;
        while(k<number)
        {
            ZeroOnePack(k*weight,k*value);
            number-=k;
            k*=2;
        }
        ZeroOnePack(number*weight,number*value);
    }
}
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        for(i=0;i<30007;i++)ans[i]=0;
        scanf("%d%d",&V,&N);
        for(i=0;i<N;i++)scanf("%d%d%d",&v[i],&w[i],&num[i]);
        for(i=0;i<N;i++)
        {
            if(num[i]==1)ZeroOnePack(w[i],v[i]);
            else if(num[i]==233)CompletePack(w[i],v[i]);
            else MultiplePack(w[i],v[i],num[i]);
        }
        printf("%d\n",ans[V]);
    }
}
