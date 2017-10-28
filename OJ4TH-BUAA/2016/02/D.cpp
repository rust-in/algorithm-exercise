#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <map>
using namespace std;

long one[100005];
long two[100005];

int main()
{
    long len,t;
    while(~scanf("%ld",&len)){
        map<int,int> abc;
        for(int i=0;i<len;i++)  scanf("%ld", &one[i]);
        for(int i=0;i<len;i++)  scanf("%ld", &two[i]);
        scanf("%ld",&t);
        sort(one,one+len);
        sort(two,two+len);

        int nt=0;   long tmpa = one[0],tmpb = two[0];
        for(int i=0;i<len;i++){
            abc[two[i]]++;
        }
        for(int i=0;i<len;i++){
            if(abc[t-one[i]]){
                printf("%d %d",one[i],t-one[i]);
                abc[t-one[i]]=0;
                nt=1;
            }
        }
        if(nt==0)printf("OTZ\n");
        printf("\n");
    }
}
