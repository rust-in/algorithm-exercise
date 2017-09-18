#include <cstdio>
using namespace std;

int cnt = 0;
int num[1000000];
int main()
{
    int one,two;
    while(~scanf("%d %d", &one, &two)){

        for(int i=0; i<two; i++)
            scanf("%d", &num[i]);

        printf("Case %d:\n", ++cnt);

        int srch,font,bottom,mid;
        while(one--){
            scanf("%d", &srch);
            font=0; bottom=two-1;
            bool flag=false;
            while(font <= bottom){
                mid = (font + bottom) / 2;
                if(srch==num[mid]){
                    flag=true;
                    break;
                }
                else if(srch<num[mid])
                    bottom=mid-1;
                else
                    font=mid+1;
            }

            if(flag)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
}
