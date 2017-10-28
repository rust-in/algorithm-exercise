#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <map>
#include <climits>
using namespace std;

int main()
{
    int m,n,tmp;
    while(~scanf("%d %d",&m,&n)){
        map<int, int> abc;
        int maxl = 0;
        int minl=INT_MAX;
        for(int i=0;i<m;i++){
            int sum=0;
            for(int j=0;j<n-1;j++){
                scanf("%d",&tmp);
                sum+=tmp;
                abc[sum]++;
                maxl=max(maxl,abc[sum]);
            }
            scanf("%d",&tmp);
        }
        printf("%d\n",m-maxl);
        abc.clear();
    }
}
