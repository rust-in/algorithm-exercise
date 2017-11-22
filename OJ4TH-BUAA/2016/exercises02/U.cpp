#include <iostream>
using namespace std;
long long n;

int main()
{
    while(cin>>n){
        long tmp = n/4;
        int a=n%4;
        if(a==1)
            tmp--;
        else if(a==3)
        {
            if(tmp<=2) tmp=0;
            else     tmp--;
        }
        if(tmp<=0)
            cout  << -1 << endl;
        else
            cout << tmp << endl;
    }
}
