#include <cstdio>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;
const double inf=1e20;
double ans;
int N;
struct Node {
    double x;
    double y;
}nd[100007];
bool cmpMostLeft(Node a,Node b) {
    return a.x<b.x;
}
double dis(Node a,Node b) {
    return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}
void FindCloeset(int l,int r) {
    if(l<r) {
        int mid=(l+r)/2;
        FindCloeset(l,mid);
        FindCloeset(mid+1,r);
        for(int i=l;i<=mid;i++) {
            for(int j=mid+1;j<=min(mid+5,r);j++) {
                double tmp=dis(nd[i],nd[j]);
                if(tmp<ans) ans=tmp;
            }
        }
    }
}
void solve(int a,int b){ //a=0,b=N-1
    ans=inf;
    sort(nd,nd+N,cmpMostLeft);
    FindCloeset(a,b);
}

int main() {
    while(~scanf("%d",&N)) {
        for(int i=0;i<N;i++) {
            scanf("%lf%lf",&nd[i].x,&nd[i].y);
        }

        solve(0,N-1);
        printf("%.2f\n",ans);
    }
}
