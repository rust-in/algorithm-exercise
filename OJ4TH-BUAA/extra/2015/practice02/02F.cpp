#include <stdio.h>
#include <cstring>
#include <map>
using namespace std;

int num[2000005];

int main()
{
    int len;
    while(~scanf("%d",&len)){
        memset(num,0,sizeof(num));
        int tmp;    int one[4005];
        for(int i=0;i<len;i++)
            scanf("%d",&one[i]);

        for(int i=0;i<len;i++){
            scanf("%d",&tmp);

            for(int j=0;j<len;j++){
                int cr=tmp+one[j];
                if(cr<0)    cr+=2000001;
                num[cr]++;
            }
        }

        int cnt=0;
        for(int i=0;i<len;i++)
            scanf("%d",&one[i]);
        for(int i=0;i<len;i++){
            scanf("%d",&tmp);

            for(int j=0;j<len;j++){
                int ct=tmp+one[j];
                if(ct>0)
                    ct=2000001-ct;
                else
                    ct*=-1;

                cnt+=num[ct];
            }
        }

        printf("%d\n",cnt);
    }
}
