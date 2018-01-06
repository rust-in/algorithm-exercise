#include <cstdio>
#include <algorithm>
using namespace std;
struct period{
    int begin;
    int end;
};
bool cmp(period a, period b){
    return a.end<b.end;
}

period prs[100002];
int main() {
    int n;
    while(scanf("%d", &n) > 0) {
        for(int i=0;i<n;i++) {
            scanf("%d%d", &prs[i].begin, &prs[i].end);
        }
        sort(prs,prs+n,cmp);
        int count = 0;
        int latest = 0;
        for(int i=0;i<n;i++) {
            if(prs[i].begin > latest) {
                latest = prs[i].end;
                count++;
            }
        }
        printf("%d\n", count);
    }
}
