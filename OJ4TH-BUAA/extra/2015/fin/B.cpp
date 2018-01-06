#include <bits/stdc++.h>
using namespace std;

long abc(int h,string x) //系数为h,各位数值为x
{
    int i=0;
    long res=x[0]-48;
    for(i=1;i<x.length();i++)
        res = res * h + (x[i] - 48);

    return res;
}

long Horner_rule(int arr[],int n,int x)  //系数为x
{
int i;
long ans = 0;
    for(i = 0;i<n;i++)
    {
        ans =arr[i]+(x*ans)%10007;
    }
    return ans;
}

int one[100005];
int two[100005];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        int n1,n2;
        scanf("%d",&n1);
        for(int i=n1;i>=0;i--){
            scanf("%d",&one[i]);
        }
        scanf("%d",&n2);
        for(int i=n2;i>=0;i--){
            scanf("%d",&two[i]);
        }
        int time;   cin>>time;
        while(time--){
            int a,b;
            cin >> a >> b;
            cout << Horner_rule(one,n1+1,a)*Horner_rule(two,n2+1,b)%10007<<endl;
        }
    }
}
