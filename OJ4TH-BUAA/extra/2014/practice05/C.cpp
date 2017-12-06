#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

long long num[1000005];

int main()
{
    ios_base::sync_with_stdio(false);
    int len;    long long key;
    while(cin>>len>>key){
        for(int i=0;i<len;i++)  cin >> num[i];
        int up = lower_bound(num,num+len,key) - num;
        if (up==0)  {cout << 0 << endl;continue;}
        int down = lower_bound(num,num+len,num[up-1])-num;
        cout << up-down << endl;
    }
}
