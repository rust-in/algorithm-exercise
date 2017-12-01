#include <cstdio>
#include <algorithm>
using namespace std;

int num[6]= {1,3,9,27,81,243};

void ans(int n){
    int upper = 6;
    bool flag = false;
    bool value = true;
    while(n){
        int i=0;
        for(;i<upper;i++)    if(num[i]>=n)   break;
        int tmp=0;
        for(int j=0;j<i;j++)
            tmp += num[j];
        if(tmp >= n){
            upper = i-1;
            flag = true;
            continue;
        }else{
            if(i==upper){ //越界
                if(flag){
                    n-=num[i];
                    printf("%d",num[i]);
                    flag =false;

                } else{
                    n-=num[i-1];
                    printf("%d",num[i-1]);
                    upper--;
                }
                    if(value)
                        printf("+");
                    else
                        printf("-");

            }
            else if(n == num[i]) { //相等
                printf("%d\n",num[i]);
                return;
            } else{
                upper = i;
                printf("%d",num[i]);
                if(value)
                    printf("-");
                else
                    printf("+");
                n=num[i]-n;
                value=!value;
            }
        }

    }
}

int main()
{
    int n;
//    while(~scanf("%d",&n))
//        ans(n);
    for(int i=1;i<=364;i++)
        ans(i);
}
