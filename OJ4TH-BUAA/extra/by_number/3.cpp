#include <iostream>
using namespace std;

int main()
{
    int n,m,k;
    while(cin >> n >> m >> k){
        int tmp = n + m*k;
        cout << (n+tmp)*(k+1)/2 << endl;
    }
}
