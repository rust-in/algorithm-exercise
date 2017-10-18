#include <cstdio>
using namespace std;

int num[1000005];

int main()
{
    int len,k,l,r,tmp;

    while(~scanf("%d",&len)){
        scanf("%d",&num[0]);

        for(int i=1;i<len;i++){
            scanf("%d",&tmp);
            num[i] = tmp ^ num[i-1];
        }

        scanf("%d",&k);
        while(k--){
            scanf("%d%d",&l,&r);
            if(l>r) l=l+r-(r=l);
            printf("%d\n",num[l-2]^num[r-1]);
        }
    }
}
