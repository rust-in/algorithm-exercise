#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int one[4005];
int two[4005];

int main()
{
    ios_base::sync_with_stdio(false);
    int len;
    while(cin>>len){
        for(int i=0;i<len;i++)
            cin>>one[i];
        for(int i=0;i<len;i++)
            cin>>two[i];
        sort(one,one+len);
        sort(two,two+len);
        cout << one[0]+two[0]<<endl;
    }

}
