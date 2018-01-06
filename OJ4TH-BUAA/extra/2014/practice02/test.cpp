//
// Created by yuyuyzl on 2018/1/4.
//
#include <iostream>
using namespace std;


int qsort(int a[],int l,int r,int k){
    if(l>=r)return a[l];

    //rand swap
    int pos=l+rand()%(r-l+1);
    int t=a[l];
    a[l]=a[pos];
    a[pos]=t;
    //rand swap


    int mid=a[l];

    int i=l,j=r;
    while (i<j){
        while (i<j&&a[j]>=mid)j--;
        if(i<j)a[i++]=a[j];
        while (i<j&&a[i]<mid)i++;
        if(i<j)a[j--]=a[i];

    }
    a[i]=mid;
    //for(int tt=l;tt<=r;tt++)cout<<a[tt]<<" ";
    //cout<<endl;
    if(k==j)
        return a[k];
    if(k<j)return qsort(a,l,j-1,k);
    return qsort(a,i+1,r,k);
}


int main(){
    std::iostream::sync_with_stdio(false);
    int n,k;

    while(cin>>n>>k){
        int a[1000001]={0};
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        cout<<qsort(a,0,n-1,n-k)<<endl;
    }
    return 0;
}
