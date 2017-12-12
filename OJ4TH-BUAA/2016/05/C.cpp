#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int one[1000005];
int two[1000005];
int thr[1000005];
int res[1000005];

int main()
{
    int len;
    while(~scanf("%d",&len)){
        for(int i=0;i<len;i++)  scanf("%d",&one[i]);
        two[0]=1;   thr[len-1]=1;
        for(int i=1;i<len;i++){
            if(one[i]>one[i-1])
                two[i] = two[i-1]+1;
            else
                two[i] = 1;
        }
        for(int i=len-2;i>=0;i--){
            if(one[i]>one[i+1])
                thr[i] = thr[i+1]+1;
            else
                thr[i] = 1;
        }
        int ans=0;
        for(int i=0;i<len;i++)  ans+=max(two[i],thr[i]);
        printf("%d\n", ans);
    }
}
