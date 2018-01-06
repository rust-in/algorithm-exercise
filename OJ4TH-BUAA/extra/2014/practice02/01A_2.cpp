#include <bits/stdc++.h>
using namespace std;

int num[1000005];

int select_k(int s[], int l, int r,int k) //l=0,r=n-1
{   //k=n-k 第k大 k=k-1 第k小
    if(l>=r)    return s[l];

    //rand
    int plot = l + rand()%(r-l+1);
    int tmp = s[plot];
    s[plot] = s[l];
    s[l] = tmp;
    //rand

    //Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换
    int i = l, j = r, x = s[l];
    while (i < j)
    {
        while(i < j && s[j] >= x) // 从右向左找第一个小于x的数
            j--;
        if(i < j)
            s[i++] = s[j];

        while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数
            i++;
        if(i < j)
            s[j--] = s[i];
    }
    s[i] = x;
    if(k==i)
        return s[k];
    else if(k<i)
        return select_k(s, l, i - 1,k);
    else
        return select_k(s, i + 1, r,k);
}

int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k)){
        for(int i=0;i<n;i++)
            scanf("%d",&num[i]);
        select_k(num,0,n-1,k-1);
        for(int i=0;i<k;i++)
            printf("%d ",num[i]);
        printf("\n");
    }
}
