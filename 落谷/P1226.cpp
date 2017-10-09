#include <iostream>
#include <cmath>
using namespace std;

/**
快速幂取模
*/

int quickMod(int a,int b,int c)
{
    int ans = 1;
    while(b){
        if(b/2==1)
            ans=(ans*a)%c;
        b/=2;
        a = (a*a)%c;
    }
    return ans;
}


int main()
{
    cout << (float)9/3600;
}
