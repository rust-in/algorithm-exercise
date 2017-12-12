//
// Created by yuyuyzl on 2017/12/8.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;


int a[1000001];
int b[1000001];
int c[1000001];

int main(){
    int n;
    std::iostream::sync_with_stdio(false);
    while(cin>>n){
        memset(a,0, sizeof(a));
        memset(b,0, sizeof(b));
        memset(c,0, sizeof(c));
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        b[0]=1;
        for (int i = 1; i < n; ++i) {
            if(a[i-1]<a[i])b[i]=b[i-1]+1;else b[i]=1;
        }
        c[n-1]=1;
        for (int i = n-2; i >= 0 ; --i) {
            if(a[i+1]<a[i])c[i]=c[i+1]+1;else c[i]=1;
        }/*
        for (int i = 0; i < n; ++i) {
            cout<<b[i]<<" ";
        }
        cout<<endl;
        for (int i = 0; i < n; ++i) {
            cout<<c[i]<<" ";
        }
        cout<<endl;*/
        long long sum=0;
        for (int i = 0; i < n; ++i) {
            sum+=(b[i]>c[i]?b[i]:c[i]);
        }
        cout<<sum<<endl;

    }
    return 0;
}
