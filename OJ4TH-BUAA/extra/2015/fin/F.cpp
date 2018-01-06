#include <bits/stdc++.h>
using namespace std;

int n,t,x,y;
long long ans;
string data[100010];
//int mat[1003][10010];

void merge_process(string arr[],int l,int mid,int r) {
    int i=l,j=mid+1,s=r-l+1,k=0;
    string tmpArr[s];
    while(i<=mid && j<=r) {
        if(arr[i]<=arr[j]) tmpArr[k++]=arr[i++];
        else {
            ans+=(j-k-l);
            tmpArr[k++]=arr[j++];
        }
    }
    while(i<=mid) tmpArr[k++]=arr[i++];
    while(j<=r) tmpArr[k++]=arr[j++];
    for(i=0;i<s;i++) arr[l+i]=tmpArr[i];
}

void merge_sort(string arr[],int l,int r) {
    if(l<r) {
        int mid=(r+l)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        merge_process(arr,l,mid,r);
    }
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i=0;i<n;i++) {
            cin>>data[i];
        }
//        cin>>t;
//        // t´ÎÑ¯ÎÊ
//        for(int i=0;i<t;i++) {
//            for(int j=0;j<n;j++) {
//                mat[i][j]=data[j];
//            }
//        }
//        for(int i=0;i<t;i++) {
        ans=0;
//            scanf("%d%d",&x,&y);
        merge_sort(data,0,n-1);
        cout << ans << endl;
//        }
    }
}
