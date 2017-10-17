#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

long abc(int h,string x)
{
    int i=0;
    long res=x[0]-48;
    for(i=1;i<x.length();i++)
        res = res * h + (x[i] - 48);

    return res;
}


int main()
{
    int len,h1,h2;
    string x1,x2;
    cin >> len;
    while(len--){
        cin >> h1 >> x1 >> h2 >> x2;

        long a = abc(h1,x1);
        long b = abc(h2,x2);

        cout << a +b << endl;
    }

}
