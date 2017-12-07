#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

map<int,int> num;

int main()
{
    int m,n,tmp,cnt=1;
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<m;i++){
            scanf("%d",&tmp);
            num[tmp]=1;
        }
        printf("Case %d:\n",cnt++);
        for(int i=0;i<n;i++){
            scanf("%d",&tmp);
            if(num[tmp])
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
}
