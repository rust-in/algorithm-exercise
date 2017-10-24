#include <cstdio>
using namespace std;

void quickSort(int *num,int l,int r)
{
    if(l>=r)    return;
    int i=l,j=r;
    int tmp = num[l];
    while(i<j){
        while(i<j&&num[j]>=tmp)   j--;
        if(i<j) num[i++]=num[j];
        while(i<j&&num[i]<=tmp)   i++;
        if(i<j) num[j--]=num[i];
    }
    num[i]=tmp;

    quickSort(num,l,i-1);
    quickSort(num,i+1,r);
}

int main()
{
    int len;    int num[100005];
    while(~scanf("%d",&len)){
        for(int i=0;i<len;i++)
            scanf("%d",&num[i]);
        quickSort(num,0,len-1);
        printf("%d\n",num[len%2?len/2:(len/2-1)]);
    }
}
