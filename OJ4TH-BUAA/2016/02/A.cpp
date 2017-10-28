#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iomanip>

using namespace std;
long font[50005];
long last[50005];
int main()
{
    int len;
    long a,b;
    while(~scanf("%d",&len)){
        for(int i=0;i<len;i++){
            scanf("%ld %ld",&a,&b);
            font[i] = a-b;
            last[i] = a+b;
        }
        sort(font,font+len);
        sort(last,last+len);
        int i,j,u=1,cnt=0;
        for(i=0;i<len;i++){
            for(j = max(u,i+1);j<len;j++){
                if(last[i] < font[j]){
                    cnt += len - j;
                    u = j;
                    break;
                }
            }
        }

        printf("%d\n",cnt);
    }
}
