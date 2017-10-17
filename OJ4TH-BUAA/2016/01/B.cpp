#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    long long num;
    while(cin>>num){
        long long res = num/2 + num%2 + 1;
        cout << res << endl;
    }

}
