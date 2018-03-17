#include <iostream>
using namespace std;

int main()
{
    int n;  cin >> n;
    int l,m;  cin >> l;   m=l;  n--;
    while(n--){
        int tmp;    cin >> tmp;
        l = max(l,tmp);
        m = min(m,tmp);
    }
    cout << m << " " << l;
}
