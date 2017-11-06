#include <cstdio>
#include <algorithm>
using namespace std;

int upperBound(long *a, int lef, int righ, int v) {//上界二分
    int middle;
    while(lef < righ) {
        middle = (lef+righ) / 2;
        if(v >= a[middle]) {
            lef = middle + 1;
        } else {
            righ = middle;
        }
    }
    return lef;
}
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

        int cnt=0;
        long tmp;
        for(int i=0;i<len;i++)
            cnt += len-upperBound(font,0,len,last[i]);
//            cnt += len - upperBound(font, 0, len, last[i]); //STL做法
        printf("%d\n",cnt);
    }
}
