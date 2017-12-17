#include <iostream>
using namespace std;

int main()
{
    int len;
    int a;
    cin >> len;
    while(len--){
        cin >> a;
        if(a%72==0)
            cout << 7 << endl;
        else
            cout << 32 << endl;
    }
}
