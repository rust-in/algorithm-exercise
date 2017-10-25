#include <iostream>
using namespace std;

long long wrong(int n)
{
    if(n==1)
        return 0;
    else if(n==2)
        return 1;
    else{
        return (n-1)*(wrong(n-1)+wrong(n-2));
    }
}

int main()
{
    int num;
    while(cin>>num) cout << wrong(num) << endl;
}
