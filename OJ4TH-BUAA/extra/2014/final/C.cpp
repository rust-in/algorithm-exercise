#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int num[1000005];

int main()
{
    int n,k;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++)
            scanf("%d",&num[i]);
        scanf("%d",&k);
        k = upper_bound(num,num+n,k)-num;
        printf("%d\n,", num[k]);
    }
}
