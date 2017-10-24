#include <iostream>
#include <algorithm>
using namespace std;

int num[1000005];

int main()
{
    ios_base::sync_with_stdio(false);
    int len,key;
    while(cin>>len>>key){
        for(int i=0;i<len;i++)
            cin>>num[i];
        sort(num,num+len);
        cout << num[len-key] << endl;
    }
}
