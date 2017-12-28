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

struct imap{
    int i;
    int num;
}pot[1000005];

bool cmp(imap a, imap b){
    return a.num > b.num;
}

int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k)){
        for(int i=1;i<=n;i++){
            scanf("%d",&pot[i].num);
            pot[i].i=i;
        }
        sort(pot+1, pot+n+1,cmp);
        printf("map%d : %d\n",pot[k].i,pot[k].num);
    }
}
