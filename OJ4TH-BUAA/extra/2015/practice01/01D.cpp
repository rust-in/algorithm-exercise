#include <cstdio>

int main(){
    int len;
    while(~scanf("%d", &len)){
        int gap=0,minium,tmp;

        for(int i=0; i<len; i++){
            scanf("%d", &tmp);

            if(i == 0)
                minium = tmp;

            if(tmp-minium>gap)
                gap = tmp-minium;
            else if(tmp-minium<0)
                minium = tmp;
        }

        gap==0?printf("No solution\n"):printf("%d\n", gap);
    }
}
