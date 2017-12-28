#include <cstdio>
#include <cstring>
#include <cmath>
#define INF 0xFFFFFF
using namespace std;

int toxic_doses[100001];

int main()
{
    int n, k, small, big, ans, totalTimeInMachine, possibleTime;
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%d",&k);
        small = INF;
        big = ans = totalTimeInMachine = 0;
        for(int i = 0; i < n; ++i){
            scanf("%lld",&toxic_doses[i]);
            if(toxic_doses[i] > big)
                big = toxic_doses[i];
            if(toxic_doses[i] < small)
                small = toxic_doses[i];
        }


        while(small <= big){
            totalTimeInMachine = 0;
            possibleTime = (small + big)/2;
            for(int i = 0; i < n; i++)
                if(toxic_doses[i] > possibleTime)
                    totalTimeInMachine += ceil((double)(toxic_doses[i] - possibleTime)/(k - 1));
            if(totalTimeInMachine > possibleTime)
                small = possibleTime + 1;
            else
            {
                ans = possibleTime;
                big = possibleTime - 1;
            }
        }
        printf("%d\n",ans);
    }
}
