#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n){
        if(n%10)    cout << n%10;
        if(n%10||(n/10)%10)  cout << (n/10)%10;
        cout << n/100 << endl;
    }
}
