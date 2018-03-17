#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int len;
    int num[10000];
    cin >> len;
    for(int i=0;i<len;i++)
        cin >> num[i];
    sort(num,num+len);

    int cnt=0;
    for(int i=1;i<len;i++)
        if(num[i]==num[i-1])
            cnt++;
    cout << len-cnt << endl;
    cout << num[0] << " ";
    for(int i=1;i<len;i++)
        if(num[i]!=num[i-1])
            cout << num[i] << " ";
}
