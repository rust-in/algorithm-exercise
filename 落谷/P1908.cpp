#include <iostream>
#include <climits>
using namespace std;
/**
πÈ≤¢≈≈–Ú
*/
int num[100000];
long long ans;

void Merge(int a,int b,int c)
{
    int lenl=b-a+1;
    int lenr=c-b;

    int arrl[lenl+1],arrr[lenr+1];
    for(int i=0;i<lenl;i++)
        arrl[i]=num[i+a];
    for(int i=0;i<lenr;i++)
        arrr[i]=num[i+b+1];
    arrl[lenl]=arrr[lenr]=INT_MAX;
    int l=0,r=0;
    for(int i=a;i<=c;i++)
    {
        if(arrl[l]<=arrr[r])
            num[i]=arrl[l++];
        else{
            num[i]=arrr[r++];
            ans+=lenl-l;
        }
    }
}

void MergeSort(int a,int b)
{
    if(a<b)
    {
        int mid=(a+b)/2;
        MergeSort(a,mid);
        MergeSort(mid+1,b);
        Merge(a,mid,b);
    }
}

int main()
{
    int len;
    while(cin>>len)
    {
        for(int i=0;i<len;i++)
            cin>>num[i];
        ans=0;
        MergeSort(0,len-1);
        cout << ans << endl;
    }
}
