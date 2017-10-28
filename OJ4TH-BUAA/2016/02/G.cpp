#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int a[1000005];

void quick_sort(int s[], int l, int r,int &n)
{
    if(n>=3){
        if(n==5)
        {
                for(int i=l;i<=r;i++)
                    printf("%d ",s[i]);
                printf("\n");
                return;
        }
        else{
            return;
        }

    }
    else
    {
        if (l < r)
        {
            int mid = l+(r-l+1)/2;
            int i = l, j = r, x = s[mid];
            while (i <= j)
            {
                while(i < j && s[i] < x)
                    i++;

                while(i < j && s[j] > x)
                    j--;

                if(i <= j){
                    int tmp = s[i];
                    s[i] = s[j];
                    s[j] = tmp;
                    i++; j--;
                }
            }

            n+=1;
            quick_sort(s, l, i-1,n);
            n+=1;
            quick_sort(s, i, r,n);
        }
    }

}

int main()
{
    int len;
    cin >> len;
    for(int i=0;i<len;i++)
        cin >> a[i];
    int n=0;
    quick_sort(a,0,len-1,n);
}
