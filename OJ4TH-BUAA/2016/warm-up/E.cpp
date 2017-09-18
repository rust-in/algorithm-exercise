#include <cstdio>
using namespace std;

/**
本题主要考察归并排序
*/

long fullNumber[10005];
long tmp[10005];

void Merge(int left, int mid, int right)
{
    int lenl=mid-left-1;
    int lenr=right-len;

    long arrl[lenl], arrr[lenr];
    for(int i=0;i<lenl;i++)
        arrl[i]=tmp[left+i];
    for(int i=0;i<lenr;i++)
        arrr[i]=tmp[mid+i+1];
}
int main()
{
    int len;
    while(~scanf("%d", &len)){
        for(int i=0;i<len;i++)
            scanf("%d", &fullNumber[i]);

        int cnt;
        scanf("%d", &cnt);
        while(cnt--){

        }
    }
}
