#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

double pack[100005];
double weight[100005];

struct water{
    double wei;
    double val;
    double rat;
}loop[100005];

bool cmp(water a, water b){
    return a.rat > b.rat;
}

struct pip{
    double wei;
    double val;
}pepe[100005];
int main()
{
    int M,K,S;
    while(scanf("%d%d%d",&M,&K,&S)==3){
        for(int i=0;i<M;i++){
            scanf("%lf%lf",&loop[i].wei,&loop[i].val);
            loop[i].rat=loop[i].val/loop[i].wei;
        }
        sort(loop,loop+M,cmp);
        for(int i=0;i<K;i++)
            scanf("%lf%lf",&pepe[i].wei,&pepe[i].val);

        memset(pack,0,sizeof(pack));
        memset(weight,0,sizeof(weight));
        for(int i=0;i<K;i++)
            for(int j=S;j>=pepe[i].wei;j--){
                if(pack[j-(int)pepe[i].wei]+pepe[i].val>pack[j]){
                    pack[j] = pack[j-(int)pepe[i].wei]+pepe[i].val;
                    weight[j] = weight[j-(int)pepe[i].wei] + pepe[i].wei;
                }
            }
        double ans = pack[S];
        double dump = S - weight[S];
        int i=0;
        while(dump&&i<M){
            if(loop[i].wei<=dump){
                dump -= loop[i].wei;
                ans += loop[i].val;
                i++;
            } else{
                ans += dump * loop[i].rat;
                break;
            }
        }

        printf("%.1lf\n",ans);
    }

}
