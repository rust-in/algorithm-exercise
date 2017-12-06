#include <cstdio>
#include <algorithm>
using namespace std;

int num[10000000];

int main()
{
    int len;
    while(~scanf("%d",&len)){
        for(int i=0;i<len;i++)  scanf("%d",num+i);
        sort(num,num+len);
        for(int i=0;i<len;i++)
            printf("%d ",num[i]);
        printf("\n");
    }
}
