#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int kill[100005];
int nkill[100005];
int kill2[100005];
int nkill2[100005];
int num[100005];

int main()
{
    int len;
    while(~scanf("%d",&len)){
        for(int i=1;i<=len;i++)
            scanf("%d",&num[i]);

        if(len==1){
            printf("%d\n",num[1]);
            continue;
        }
        kill[1]=num[1];
        nkill[1]=0;
        for(int i=2;i<len;i++){
            kill[i]=nkill[i-1] + num[i];
            nkill[i] = max(kill[i-1],nkill[i-1]);
        }
        int res1 = max(kill[len-1],nkill[len-1]);

        kill2[2]=num[2];
        nkill2[2]=0;
        for(int i=3;i<=len;i++){
            kill2[i]=nkill2[i-1] + num[i];
            nkill2[i] = max(kill2[i-1],nkill2[i-1]);
        }
        int res2 = max(kill2[len],nkill2[len]);

        printf("%d\n",max(res1,res2));
    }
}
