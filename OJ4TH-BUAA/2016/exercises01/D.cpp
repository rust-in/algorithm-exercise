#include <stdio.h>
using namespace std;

int num[100005];
int flag[100005];

int len;

bool abc()
{
    int A = len-1;
    for(int i=len-2;i>=0;i--){
        if(num[i]+i>=A)
            A = i;
    }

    return (A == 0);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&len);
        for(int i=0;i<len-1;i++)
            scanf("%d",&num[i]);
        if(abc()) printf("I Win!\n");
        else    printf("Too Far!\n");
    }

}
