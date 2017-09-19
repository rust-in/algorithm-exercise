#include <cstdio>
#include <climits>
using namespace std;

/**
本题主要考察归并排序
*/

long fullNumber[10005];
long tmp[10005];
long res;

void Merge(int left, int mid, int right)
{
    int lenl=mid-left+1;
    int lenr=right-mid;

    long arrl[lenl+1], arrr[lenr+1];
    for(int i=0;i<lenl;i++)
        arrl[i]=tmp[left+i];
    for(int i=0;i<lenr;i++)
        arrr[i]=tmp[mid+i+1];
    arrl[lenl]=arrr[lenr]=LONG_MAX;
    int l=0,r=0;
    for(int i=left;i<=right;i++){
        if(arrl[l]<=arrr[r])
            tmp[i]=arrl[l++];
        else{
            tmp[i]=arrr[r++];
            res+=lenl-l;
        }
    }
}

void mergeSort(int left, int right)
{
    if(left<right){
        int mid=(left+right)/2;
        mergeSort(left, mid);
        mergeSort(mid+1, right);
        Merge(left, mid, right);
    }
}
int main()
{
    int len;
    while(~scanf("%d", &len)){
        for(int i=0;i<len;i++)
            scanf("%ld", &fullNumber[i]);

        int cnt;
        scanf("%d", &cnt);
        while(cnt--){
            int one,two;
            scanf("%d %d", &one, &two);
            int j=0;
            res=0;
            for(int i=one;i<=two;i++)
                tmp[j++]=fullNumber[i];
            mergeSort(0,j-1);
            printf("%ld\n", res);
        }
    }
}
