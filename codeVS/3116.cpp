#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio();
    string a,b;
    cin>>a>>b;
    int l = a.length(),r=b.length();
    int num[505]={0};

    int lmax = l>r?l:r;
    for(int i=lmax-1,j=l-1,k=r-1;i>=0;i--,j--,k--){
        if(j>=0)    num[i]+=a[j]-48;
        if(k>=0)    num[i]+=b[k]-48;
    }

    for(int i=lmax-1;i>0;i--){
        num[i-1] += num[i]/10;
        num[i] %= 10;
    }

    for(int i=0;i<lmax;i++)
        cout << num[i];
}
