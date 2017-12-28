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
#include <climits>
using namespace std;

long long num[100005];

int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k)){
        long long down = INT_MAX;
        long long up =0, ans;
        long long total,mid;
        for(int i=0;i<n;i++){
            scanf("%lld",&num[i]);
            down = num[i]<down?num[i]:down;
            up = num[i]>up?num[i]:up;
        }
        down = ceil((double)down/k);

        if(k==1){
            printf("%lld\n",up);
            continue;
        }

        while(down<=up){
            total = 0;
            mid = (up+down)/2;
            for(int i=0;i<n;i++){
                if(num[i]>mid){
                    total += ceil(((double)(num[i]-mid))/(k-1));
                }
            }
            if(total>mid)   down = mid+1;
            else{
                ans = mid;
                up = mid-1;
            }
        }
        printf("%lld\n",ans);
    }
}
